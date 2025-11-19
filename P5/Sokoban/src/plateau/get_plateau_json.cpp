#include "get_plateau_json.h"


//convertie une chaine de caractère en entier
int str_to_int(std::string str){
    std::string str_int="";
    for(unsigned int i = 0;i<str.length();++i){
        if(isdigit(str[i]))
            str_int+=str[i];
    }

    return std::stoi(str_int);
}

//convertie les éléments du .json en la valeur correspondante dans la grille du plateau
//suivant le nom de la clé
void convert_to_grille(std::string cle, std::string valeurX, std::string valeurY,Plateau & plateau){
    int x=str_to_int(valeurX);
    int y=str_to_int(valeurY);


    if(cle=="murs"){
        plateau.grille[y][x]='#';
    }

    else if(cle=="objectifs"){
        //si on met un objectif sur une caisse
        if(plateau.grille[y][x]=='$'){
            ++plateau.score;
            plateau.grille[y][x]='*';
        }

        //si on met un objectif sur un perso
        else if(plateau.grille[y][x]=='@')
            plateau.grille[y][x]='+';
        
        //sinon si y'a r
        else
            plateau.grille[y][x]='.';
    }

    else if(cle=="caisses"){
        ++plateau.nb_caisse;

        //si on met une caisse sur un objectif
        if(plateau.grille[y][x]=='.'){
            plateau.grille[y][x]='*';
            ++plateau.score;
        }
        else
            plateau.grille[y][x]='$';
    }

    else if(cle=="personnage"){
        plateau.x=x;
        plateau.y=y;

        //si perso sur objectif
        if(plateau.grille[y][x]=='.')
            plateau.grille[y][x]='+';
        else
            plateau.grille[y][x]='@';
    }

}


//constuit la grille du plateau
void init_grille(Plateau & plateau){

    plateau.grille=new char*[plateau.hauteur];
    for(int i=0;i<plateau.hauteur;++i)
    {
        plateau.grille[i]=new char[plateau.longueur];
    }
    for(int i=0;i<plateau.hauteur;++i)
        for(int j=0;j<plateau.longueur;++j)
        {
            plateau.grille[i][j]=' ';
        }

    plateau.grille[plateau.y][plateau.x]='@';
}

//traite les chaines de caractères en enlevant les espaces et ' " '
void traitement_str(std::string & chaine){
    std::string str_traite="";
    for(unsigned int i = 0;i<chaine.length();++i){
        if(chaine[i]!=' ' and chaine[i]!='\"' )
            str_traite+=chaine[i];
    }
    chaine = str_traite;
}

//récupére la largeure, hauteur, nom plateau et position du personnage
bool get_hauteur_largeur_nom_perso(Plateau & plateau){

    plateau.nb_caisse=0;
    plateau.score=0;
    plateau.bloque=false;

    std::ifstream fic;

    fic.open((plateau.chemin));
    if (fic.is_open())
    {
        char c;
        std::string cle;
        fic.get(c);
        while(fic.good()){
            while(c!='}')
            { 
                //tant qu'on est pas sur le début d'un coupe cle-valeur
                while(c!='\"'){

                    //si on rencontre une accolade fermante, on est a la fin du fichier
                    if(c=='}') return true;
                    fic.get(c);
                }

                //on entre dans un premier couple cle-valeur

                //====on recupere le nom de la cle====
                cle="";
                
                fic.get(c);
                while(c!=':'){
                    cle+=c;
                    fic.get(c);
                }
                traitement_str(cle);

                //===========================

                //===== Si la cle est le nom======
                if(cle=="nom"){
                        fic.get(c);
                    while(c!='\"'){
                        fic.get(c);
                    }
                    std::string valeur= "";

                    fic.get(c);
                    while(c!='\"'){
                        valeur+=c;
                        fic.get(c);
                    }

                    traitement_str(valeur);

                    plateau.nom=valeur;
                    
                    fic.get(c); //on récupérer le dernier "
                }
                //=================
                
                //===== Valeur de la clé longeur et hauteur/largeur
                else if(cle=="largeur" or cle=="hauteur"){
                    std::string valeur= "";
                    fic.get(c);
                    while(c!=','){
                        valeur+=c;
                        fic.get(c);
                    }

                    traitement_str(valeur);

                    if(cle=="largeur")
                        plateau.longueur=str_to_int(valeur);
                    if(cle=="hauteur")
                        plateau.hauteur=str_to_int(valeur);
                }
                //===========================================

                //===== Valeur de la clé personnage
                else if(cle=="personnage"){
                    std::string valeur= "";
                    fic.get(c);
                    while(c!='['){
                        fic.get(c);
                    }

                    //on prend le x
                    fic.get(c);
                    while(c!=','){
                        valeur+=c;
                        fic.get(c);
                    }
                    traitement_str(valeur);
                    plateau.x=str_to_int(valeur);
                    
                    valeur="";

                    //on prend le y
                    fic.get(c);
                    while(c!=']'){
                        valeur+=c;
                        fic.get(c);
                    }
                    traitement_str(valeur);
                    plateau.y=str_to_int(valeur);
                //===========================================

                }else{
                    fic.get(c);
                    while(c!=','){
                        fic.get(c);
                    }
                }
            }

        fic.get(c);
        }


    }else{
        std::cout<<"Erreur lors de l'ouverture du fichier."<<std::endl;
        return false;
    }
    return true;
}

//récupére les murs
bool get_murs(Plateau & plateau){
    std::ifstream fic;

    fic.open(plateau.chemin);
    if (fic.is_open())
    {
        char c;
        std::string cle;
        fic.get(c);
            while(fic.good()){
                while(c!='}'){ //la fin du json
        
                //tant qu'on est pas sur le début d'un coupe cle-valeur
                while(c!='\"'){

                    //si on rencontre une accolade fermante, on est a la fin du fichier
                    if(c=='}') return true;
                    fic.get(c);
                }

                //on entre dans un premier couple cle-valeur

                //====on recupere le nom de la cle====
                cle="";
                
                fic.get(c);
                while(c!=':'){
                    cle+=c;
                    fic.get(c);
                }
                traitement_str(cle);
                //========================

                //===== on recupere les murs ====
                if(cle=="murs"){
                    fic.get(c);
                    while(c!='['){
                        fic.get(c);
                    }
                    if(c=='['){
                        fic.get(c);
                        while(c!=']'){

                            std::string valeurX="";

                            while(c!='['){
                                fic.get(c);
                            }
                            
                            fic.get(c);
                            while(c!=','){
                                valeurX+=c;
                                fic.get(c);
                            }

                            std::string valeurY="";
                            fic.get(c);
                            while(c!=']'){
                                valeurY+=c;
                                fic.get(c);
                            }


                            convert_to_grille(cle, valeurX, valeurY, plateau);
                            fic.get(c);


                            while(c!=']' and c!=','){
                                fic.get(c);
                            }
                        }
                    }
                }
                //==========================
            }
            fic.get(c);
        }
    
    }else{
        std::cout<<"Erreur lors de l'ouverture du fichier."<<std::endl;
        return false;
    }
    return true;
}

//on récupère le reste des infos (objectifs et caisses)
bool get_last_infos(Plateau & plateau){
    std::ifstream fic;


    fic.open(plateau.chemin);
    if (fic.is_open())
    {
        char c;
        std::string cle;
        fic.get(c);
            while(fic.good()){
                while(c!='}'){ //la fin du json
        
                //tant qu'on est pas sur le début d'un coupe cle-valeur
                while(c!='\"'){

                    //si on rencontre une accolade fermante, on est a la fin du fichier
                    if(c=='}') return true;
                    fic.get(c);
                }
                //on entre dans un premier couple cle-valeur

                //====on recupere le nom de la cle====
                cle="";
                
                fic.get(c);
                while(c!=':'){
                    cle+=c;
                    fic.get(c);
                }
                traitement_str(cle);
                //========================

                //===== on recupere les caisses et les objectifs====
                if(cle=="objectifs" or cle=="caisses"){
                    fic.get(c);
                    while(c!='['){
                        fic.get(c);
                    }
                    if(c=='['){
                        fic.get(c);
                        while(c!=']'){

                            std::string valeurX="";

                            while(c!='['){
                                fic.get(c);
                            }
                            
                            fic.get(c);
                            while(c!=','){
                                valeurX+=c;
                                fic.get(c);
                            }

                            std::string valeurY="";
                            fic.get(c);
                            while(c!=']'){
                                valeurY+=c;
                                fic.get(c);
                            }


                            convert_to_grille(cle, valeurX, valeurY, plateau);
                            fic.get(c);

                            //on vérifie si le tableau 
                            while(c!=']' and c!=','){
                                fic.get(c);
                            }
                        }
                    }
                }
                //==========================
            }
            fic.get(c);
        }
    
    }else{
        std::cout<<"Erreur lors de l'ouverture du fichier."<<std::endl;
        return false;
    }
    return true;
}

//parse les fichiers .json représentant des plateaux de Sokoban
bool get_plateau_json(Plateau & plateau){

    if(!get_hauteur_largeur_nom_perso(plateau))
        return false;

    //contruit la grille du plateau
    init_grille(plateau);
    
    get_murs(plateau);


    //on remplie le reste de '0'
    for(int i=0;i<plateau.hauteur;++i)
        for(int j=0;j<plateau.longueur;++j)
        {
            if(plateau.grille[i][j]!='#' and plateau.grille[i][j]!='@')
                plateau.grille[i][j]='0';
        }

    //remplie les cases où on peut se déplacer de ' '
    //suit le principe de l'exploration exhaustive
    remplie_plateau(plateau.grille,plateau.y,plateau.x);

    //récupére les dernieres informations
    //(caisses et destinations)
    if(!get_last_infos(plateau))
        return false;

    return true;
}

