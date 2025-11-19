#include "a_star.h"

struct coord
{
    int x,y; //position
    char parent; //direction du parent
};


struct case_grille{
     
    int x, y; //position de la case
    int g; //distance entre cette case et celle de départ (+1 a chaque déplacement)
    int h; //distance de manhattan entre cette et celui d'arrivé
    int f; //g+h

    char parent; //direction du parent
};


//ajoute une case dans une list de case
void ajout_case_grille(std::vector<case_grille> & l,int x, int y, int g, int h,char parent){
    case_grille n;
    n.x=x;
    n.y=y;
    n.g=g;
    n.h=h;
    n.f=g+h;
    n.parent=parent; 

    l.push_back(n);
}

//retourne la case avec le f le plus bas
case_grille lower_f(std::vector<case_grille> l){
    case_grille lower_n = l[0];
    for(unsigned int i = 1;i<l.size();++i){
        if(l[i].f<lower_n.f)
            lower_n=l[i];
    }

    return lower_n;
}

//retourne la position de cood dans une liste de coord (-1 si rien)
int pos_dans_l_ferme(std::vector<coord> l,int x,int y){
    for(unsigned int i = 0;i<l.size();++i){
        if(l[i].x==x and l[i].y==y)
            return i;
    }
    return -1;
}

//retourne la position d'une case dans une liste de case (-1 si rien)
int pos_dans_l_ouverte(std::vector<case_grille> l,int x,int y){
    for(unsigned int i = 0;i<l.size();++i){
        if(l[i].x==x and l[i].y==y)
            return i;
    }
    return -1;
}

//inverse les directions dans un chaine de direction
void inverse(std::string & chemin){
    for(unsigned int i = 0;i<chemin.length();++i){
        switch (chemin[i])
        {
        case 'h':
            chemin[i]='b';
            break;
        
        case 'b':
            chemin[i]='h';
            break;

        case 'g':
            chemin[i]='d';
            break;

        case 'd':
            chemin[i]='g';
            break;
        }
    }
}

//reconstruit le chemin
std::string reconstuire_chemin(std::vector<coord> l, int x, int y){
    std::string chemin = "";
    bool fin=false;
    while (!fin) {
        int pos = pos_dans_l_ferme(l, x, y);
        //std::cout<<"pos : "<<pos<<std::endl;

        //si case pas dans la liste fermee
        if (pos == -1){
            fin=true;
            //std::cout<<"fin chemin"<<std::endl;
        }
        else{
            char dir = l[pos].parent;
            
            //si on arrivé au départ
            if (dir == 'o'){
                fin=true;
                //std::cout<<"fin chemin o"<<std::endl;
            }
            else{
                chemin = dir + chemin;
                if (dir == 'h')
                    y -= 1;
                else if (dir == 'b')
                    y += 1;
                else if (dir == 'd')
                    x += 1;
                else if (dir == 'g')
                    x -= 1;
            }
            
        }
    }
    
    inverse(chemin);
    return chemin;
}

//=========A Star==============
//algo de path finding
//retourne sous forme d'une chaine de car
//les deplacement pour aller de (xp,yp) a (xd,yd)
//si caisse==true, y'a des conditions en plus
//(ex : si on veut pousser la caisse vers le haut, vérifier que celle du bas soit libre)
std::string a_star(Plateau plateau,int xp,int xd,int yp,int yd,bool caisse){ 

    //init la liste ouverte
    std::vector<case_grille> l_ouverte={};

    //init la liste fermee
    std::vector<coord> l_ferme={};

    //ajoute du point depart dans la liste ouverte
    int h_0 = std::abs(xd-xp) + std::abs(yd-yp); //distance de manhattan
    ajout_case_grille(l_ouverte, xp, yp, 0, h_0, 'o'); //'o' pas de parent


    while(!l_ouverte.empty()){ //tant que la liste ouverte n'est pas vide

        //on prend la meilleure case de la liste ouverte (=plus petit f)
        case_grille best_n_ouverte=lower_f(l_ouverte);
        int pos_best = pos_dans_l_ouverte(l_ouverte,best_n_ouverte.x,best_n_ouverte.y);
        l_ouverte.erase(l_ouverte.begin() + pos_best);

        //si c'est la destination
        if(best_n_ouverte.x==xd and best_n_ouverte.y==yd){
            
            //on la met dans la liste fermée
            coord n_coord;
            n_coord.x = best_n_ouverte.x;
            n_coord.y = best_n_ouverte.y;
            n_coord.parent = best_n_ouverte.parent;
            l_ferme.push_back(n_coord);
            
            return reconstuire_chemin(l_ferme,xd,yd);
        }

        else{
            //si c'est un caisse, on la suprimme momentanément pour ne pas qu'elle se bloque elle même
            char symb_d = plateau.grille[yp][xp];
            if(caisse){
                plateau.grille[yp][xp] = ' ';
                
            }

            //on la push dans la liste fermée
            coord n_coord;
            n_coord.x=best_n_ouverte.x;
            n_coord.y=best_n_ouverte.y;
            n_coord.parent=best_n_ouverte.parent;

            l_ferme.push_back(n_coord);

            //=========on regarde ses voisins========
            char voisine;
            int v_x,v_y;

            // ===== en haut======
            v_x =l_ferme.back().x;
            v_y=l_ferme.back().y-1;
            voisine = plateau.grille[v_y][v_x];

            if(voisine!='#' and voisine!='$' and voisine!='*'){
                if ((caisse and plateau.grille[v_y+2][v_x]!='#' and plateau.grille[v_y+2][v_x]!='$' and plateau.grille[v_y+2][v_x]!='*') or !caisse){
                    if(pos_dans_l_ferme(l_ferme, v_x, v_y)==-1){ //si pas dans la liste fermée

                        //g augmente
                        int g = best_n_ouverte.g + 1;

                        //distance de manhattan entre la case courante et la case d'arrivée (destination)
                        int h = std::abs(xd-v_x) + std::abs(yd-v_y);
                        
                        //on regarde sa position dans la liste ouverte (-1 si absente)
                        int pos_l_ouverte = pos_dans_l_ouverte(l_ouverte, v_x, v_y);

                        //si case pas dans la liste ouverte
                        if(pos_l_ouverte==-1){
                            //on l'ajoute
                            ajout_case_grille(l_ouverte, v_x ,v_y ,g ,h, 'b'); //'b' car parent en bas
                        }else{
                            //si elle est dedans et que le g est meilleur, on l'update
                            if(g<l_ouverte[pos_l_ouverte].g){
                                l_ouverte[pos_l_ouverte].g=g;
                                l_ouverte[pos_l_ouverte].h=h;
                                l_ouverte[pos_l_ouverte].f=g+h;
                                l_ouverte[pos_l_ouverte].parent='b';
                            }

                        }

                    }
                }
            }
            //===============



            // ===== en bas======
            v_x =l_ferme.back().x;
            v_y=l_ferme.back().y+1;
            voisine = plateau.grille[v_y][v_x];

            if(voisine!='#' and voisine!='$' and voisine!='*'){
                if ((caisse and plateau.grille[v_y-2][v_x]!='#' and plateau.grille[v_y-2][v_x]!='$' and plateau.grille[v_y-2][v_x]!='*') or !caisse){
                    if(pos_dans_l_ferme(l_ferme, v_x, v_y)==-1){ //si pas dans la liste fermée

                        //g augmente
                        int g = best_n_ouverte.g + 1;

                        //distance de manhattan entre la case courante et la case d'arrivée (destination)
                        int h = std::abs(xd-v_x) + std::abs(yd-v_y);
                        
                        //on regarde sa position dans la liste ouverte (-1 si absente)
                        int pos_l_ouverte = pos_dans_l_ouverte(l_ouverte, v_x, v_y);

                        //si pas dans la liste ouverte
                        if(pos_l_ouverte==-1){
                            ajout_case_grille(l_ouverte, v_x ,v_y ,g ,h, 'h'); //'h' car parent en haut
                        }else{
                            //si elle est dedans et que le g est meilleur, on l'update
                            if(g<l_ouverte[pos_l_ouverte].g){
                                l_ouverte[pos_l_ouverte].g=g;
                                l_ouverte[pos_l_ouverte].h=h;
                                l_ouverte[pos_l_ouverte].f=g+h;
                                l_ouverte[pos_l_ouverte].parent='h';
                            }

                        }

                    }
                }
            }
            //===============


            // ===== a droite ======
            v_x =l_ferme.back().x+1;
            v_y=l_ferme.back().y;
            voisine = plateau.grille[v_y][v_x];

            if(voisine!='#' and voisine!='$' and voisine!='*'){
                if ((caisse and plateau.grille[v_y][v_x-2]!='#' and plateau.grille[v_y][v_x-2]!='$' and plateau.grille[v_y][v_x-2]!='*') or !caisse){
                    if(pos_dans_l_ferme(l_ferme, v_x, v_y)==-1){ //si pas dans la liste fermée

                        //g augmente
                        int g = best_n_ouverte.g + 1;

                        //distance de manhattan entre la case courante et la case d'arrivée (destination)
                        int h = std::abs(xd-v_x) + std::abs(yd-v_y);
                        
                        //on regarde sa position dans la liste ouverte (-1 si absente)
                        int pos_l_ouverte = pos_dans_l_ouverte(l_ouverte, v_x, v_y);

                        //si pas dans la liste ouverte
                        if(pos_l_ouverte==-1){
                            ajout_case_grille(l_ouverte, v_x ,v_y ,g ,h, 'g');//'g' car parent à gauche
                        }else{
                            //si elle est dedans et que le g est meilleur, on l'update
                            if(g<l_ouverte[pos_l_ouverte].g){
                                l_ouverte[pos_l_ouverte].g=g;
                                l_ouverte[pos_l_ouverte].h=h;
                                l_ouverte[pos_l_ouverte].f=g+h;
                                l_ouverte[pos_l_ouverte].parent='g';
                            }

                        }

                    }
                }
            }
            //===============


            // ===== a gauche ======
            v_x =l_ferme.back().x-1;
            v_y=l_ferme.back().y;
            voisine = plateau.grille[v_y][v_x];

            if(voisine!='#' and voisine!='$' and voisine!='*'){
                if ((caisse and plateau.grille[v_y][v_x+2]!='#' and plateau.grille[v_y][v_x+2]!='$' and plateau.grille[v_y][v_x+2]!='*') or !caisse){
                    if(pos_dans_l_ferme(l_ferme, v_x, v_y)==-1){ //si pas dans la liste fermée

                        //g augmente
                        int g = best_n_ouverte.g + 1;

                        //distance de manhattan entre la case courante et la case d'arrivée (destination)
                        int h = std::abs(xd-v_x) + std::abs(yd-v_y);
                        
                        //on regarde sa position dans la liste ouverte (-1 si absente)
                        int pos_l_ouverte = pos_dans_l_ouverte(l_ouverte, v_x, v_y);

                        if(pos_l_ouverte==-1){
                            ajout_case_grille(l_ouverte, v_x ,v_y ,g ,h, 'd'); //'d' car parent à droite
                        }else{
                            //si elle est dedans et que le g est meilleur, on l'update
                            if(g<l_ouverte[pos_l_ouverte].g){
                                l_ouverte[pos_l_ouverte].g=g;
                                l_ouverte[pos_l_ouverte].h=h;
                                l_ouverte[pos_l_ouverte].f=g+h;
                                l_ouverte[pos_l_ouverte].parent='d';
                            }

                        }

                    }
                }
            }
            //===============
            //====================================

            //on remet la caisse supprimée
            plateau.grille[yp][xp]=symb_d;
        }
    }

    return "o";

}