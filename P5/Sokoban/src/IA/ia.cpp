#include "ia.h"

struct Coord{
    int x;
    int y;
};

struct Couple{
    Coord desti;
    Coord caisse;
};

//==== Calcul n!======
int facto(int n){
    if(n==0)
        return 1;
    else{
        return n*(facto(n-1));
    }
}
//===========


//===== Copie le plateau de jeu ========
void copie_plateau(Plateau plateau, Plateau & plateau_copie){
    plateau_copie.longueur=plateau.longueur;
    plateau_copie.hauteur=plateau.hauteur;
    plateau_copie.score=plateau.score;
    plateau_copie.nb_caisse=plateau.nb_caisse;
    plateau_copie.bloque=plateau.bloque;
    plateau_copie.x=plateau.x;
    plateau_copie.y=plateau.y;

    //init de la grille
    plateau_copie.grille=new char*[plateau_copie.hauteur];
    for(int i=0;i<plateau_copie.hauteur;++i)
    {
        plateau_copie.grille[i]=new char[plateau_copie.longueur];
    }
    //copie de la grille
    for(int i = 0;i<plateau_copie.hauteur;++i){
        for(int j = 0;j<plateau_copie.longueur;++j)
            plateau_copie.grille[i][j]=plateau.grille[i][j];
    }
}
//=========================


//trouve et stocke toutes les caisses et les destinations
void trouve_caisse_destination(const Plateau & plt, std::vector<Coord> & caisses,std::vector<Coord> & desti){
    //trouve les caisses et les destination
    for(int i = 0;i<plt.hauteur;++i){
        for(int j = 0;j<plt.longueur;++j){
            if(plt.grille[i][j]=='$'){
                Coord c;
                c.x=j;
                c.y=i;
                caisses.push_back(c);
            }else if(plt.grille[i][j]=='.' or plt.grille[i][j]=='+'){
                Coord c;
                c.x=j;
                c.y=i;
                desti.push_back(c);
            }
        }
    }
}


std::string resoudre_3_bis(Plateau & plt, std::vector<Coord>  caisses,std::vector<Coord> desti){

    std::vector<Couple> couples;

    //forme des couples caisse-destination au hasard
    for(int i = caisses.size();i>0;--i){
        Couple c;
        int rdm_i = std::rand()%i;
        c.caisse=caisses[rdm_i];
        caisses.erase(caisses.begin()+rdm_i);

        rdm_i = std::rand()%i;
        c.desti=desti[rdm_i];
        desti.erase(desti.begin()+rdm_i);

        couples.push_back(c);

    }


    std::string chm_cpl="";

    //construit une chemin pour ammener le perso à déplacer chaque caisse vers sa destination
    for(unsigned int i = 0;i<couples.size();++i){
        int x_c = couples[i].caisse.x;
        int y_c = couples[i].caisse.y;

        //chemin de la caisse vers la destination
        //typ "hbdg"
        std::string chm_caisse=a_star(plt, x_c, couples[i].desti.x, y_c, couples[i].desti.y, true);

        if(chm_caisse=="o") //si aucun chemin n'a été trouvé
            return "o";
        else{
            //pour chaque déplacement unique de chm_caisse, regarde si le perso peut se déplacer
            //au bon endroit pour pousser la caisse dans la direction
            for(unsigned int k = 0; k<chm_caisse.length();++k){
                std::string chm_p;
            
                switch (chm_caisse[k]){
                    
                    case 'h':
                        //chemin de la position du perso jusqu'au dessous de la caisse
                        chm_p=a_star(plt, plt.x, x_c, plt.y, y_c+1, false)+"h";
                        if(chm_p[0]=='o') //si le personage ne peut pas s'y rendres
                            return "o";
                        for(unsigned int l=0;l<chm_p.length();++l)
                            deplacement(chm_p[l],plt);

                        chm_cpl=chm_cpl+chm_p;
                        --y_c;
                        break;

                
                    case 'b':
                    //chemin de la position du perso jusqu'au dessus de la caisse
                        chm_p=a_star(plt, plt.x, x_c, plt.y, y_c-1, false)+"b";
                        if(chm_p[0]=='o') //si le personage ne peut pas s'y rendre
                            return "o";
                        for(unsigned int l=0;l<chm_p.length();++l)
                            deplacement(chm_p[l],plt);
                            
                        chm_cpl=chm_cpl+chm_p;
                        ++y_c;
                        break;


                    case 'd':
                    //chemin de la position du perso jusqu'à la gauche de la caisse
                        chm_p=a_star(plt, plt.x, x_c-1, plt.y, y_c, false)+"d";
                        if(chm_p[0]=='o') //si le personage ne peut pas s'y rendre
                            return "o";
                        for(unsigned int l=0;l<chm_p.length();++l)
                            deplacement(chm_p[l],plt);

                        chm_cpl=chm_cpl+chm_p;
                        ++x_c;
                        break;


                    case 'g':
                        //chemin de la position du perso jusqu'à la droite de la caisse
                        chm_p=a_star(plt, plt.x, x_c+1, plt.y, y_c, false)+"g";
                        if(chm_p[0]=='o') //si le personage ne peut pas s'y rendre
                            return "o";
                        for(unsigned int l=0;l<chm_p.length();++l)
                            deplacement(chm_p[l],plt);

                        chm_cpl=chm_cpl+chm_p;
                        --x_c;
                        break;

                }
            }
        }

    }

    if(chm_cpl=="") //si il n'y a aucune chemin
        return "o";
    else    
        return chm_cpl;
}

std::string resoudre_plt(Plateau plateau){
    srand(time(nullptr));

    std::vector<Coord> caisses;
    std::vector<Coord> destination;
    trouve_caisse_destination(plateau, caisses, destination);

    Plateau plateau_copie;
    copie_plateau(plateau, plateau_copie);

    std::string sol_f="";
    std::vector<std::string> solutions;
    int essaie = 0;
    //comme on essaie des couples caisse-destination au hasard,
    //on essaye de générer plusieurs combinaisons différentes

    int fact_nb_caisse;
    if(plateau.nb_caisse<2)
        fact_nb_caisse= facto(plateau.nb_caisse+2);
    else
        fact_nb_caisse= facto(plateau.nb_caisse+1);
        
    while(essaie<fact_nb_caisse){
        std::string sol=resoudre_3_bis(plateau_copie,caisses,destination);
        if(sol!="o"){ //si on a trouvé une solution
            solutions.push_back(sol);
        }
        else
            copie_plateau(plateau, plateau_copie);

        ++essaie;
    }

    //on cherche la meilleure solution (string la plus courte)
    if(solutions.size()==0){
        std::cout<<"Pas de solutions trouvées"<<std::endl;
        sol_f = "";
    }else{
        int i_best_sol=0;

        for(unsigned int i = 1;i<solutions.size();++i){
            if(solutions[i].length()<solutions[i_best_sol].length())
                i_best_sol = i;
        }
        sol_f=solutions[i_best_sol];
    }

    std::cout<<"Meilleur solution trouvée : "<<std::endl;
    std::cout<<sol_f<<std::endl<<std::endl;
    std::cout<<"Nombre de déplacements : "<<sol_f.length()<<std::endl<<std::endl<<std::endl;


    delete [] plateau_copie.grille;

    return sol_f;
}