#include "deplacement.h"


/*========def des types de case======
# : mur
$ : caisse
. : destination
* : caisse sur une destination
@ : personnage
+ : personnage sur une destination
' ' : case vide (espace)
=====================================
*/

bool deplac_honriz(const Plateau&,int,int);

//regarde si un deplacement vertical est possible
bool deplac_verti(const Plateau & plateau, int x, int y){
    if(plateau.grille[y-1][x]=='#' or plateau.grille[y+1][x]=='#'){
        return false;
    }

    //si y'a 2 caisses de chaque côté on regarde si les 2 peuvent etre deplacées honrizontalement
    else if(plateau.grille[y-1][x]=='$' and plateau.grille[y+1][x]=='$'){
        if(deplac_honriz(plateau,x,y-1)==false and deplac_verti(plateau,x,y+1==false))
            return false;
    }

    //si y'a 1 caisse en dessous on regarde si elle peut etre deplacée honrizontalement
    else if(plateau.grille[y+1][x]=='$'){
        return deplac_honriz(plateau, x,y+1);
    }

    //si y'a 1 caisse au dessus on regarde si elle peut etre deplacée honrizontalement
    else if(plateau.grille[y-1][x]=='$'){
        return deplac_honriz(plateau, x,y-1);
    }
        
    return true;
}

//regarde si un deplacement horinzontal est possible
bool deplac_honriz(const Plateau & plateau, int x, int y){
    //si y'a au moins 1 mur deplacement honri impossible
    if(plateau.grille[y][x-1]=='#' or plateau.grille[y][x+1]=='#'){
        return false;

    }

    //si y'a 2 caisses de chaque côté on regarde si les 2 peuvent etre deplacées verticalement
    else if(plateau.grille[y][x-1]=='$' and plateau.grille[y][x+1]=='$'){
        if(deplac_verti(plateau,x-1,y)==false and deplac_verti(plateau,x+1,y==false))
            return false;
    }

    //si y'a 1 caisse a droite on regarde si elle peut etre deplacée verticalement
    else if(plateau.grille[y][x+1]=='$'){
        return deplac_verti(plateau, x+1,y);
    }

    //si y'a 1 caisse a gauche on regarde si elle peut etre deplacée verticalement
    else if(plateau.grille[y][x-1]=='$'){
        return deplac_verti(plateau, x-1,y);
    }

    return true;
}


//Regarde si le deplacement d'une caisse provoque une situtation où la partie est perdu/bloquee
//x,y : position de la caisse
void est_bloque(Plateau & plateau, int x, int y){
    
    if(deplac_honriz(plateau,x,y)==false and deplac_verti(plateau,x,y)==false){
        plateau.bloque=true;
    }
    else    {
        plateau.bloque=false;
    }
}

// déplace le personnage
// plateau.x,plateau.y : position du joueur
void depl_perso(int d_x,int d_y,Plateau &plateau){

    //======deplacement personnage======

    //si on deplace le personnage sur une destination
    if(plateau.grille[plateau.y+d_y][plateau.x+d_x]=='.')
        plateau.grille[plateau.y+d_y][plateau.x+d_x]='+';

    //si on déplace le perso sur une case où il y'avait une caisse sur une destination 
    else if(plateau.grille[plateau.y+d_y][plateau.x+d_x]=='*')
    {
        
        plateau.grille[plateau.y+d_y][plateau.x+d_x]='+';
        --plateau.score;
    }

    //sinon on le deplace sur une case vide
    else
        plateau.grille[plateau.y+d_y][plateau.x+d_x]='@';
    
    //====================================


    //=========maj case d'origine===========

    //si le perso etait sur une case vide
    if(plateau.grille[plateau.y][plateau.x]=='@')
        plateau.grille[plateau.y][plateau.x]=' ';

    //si le perso etait sur une destination
    else if(plateau.grille[plateau.y][plateau.x]=='+'){
        plateau.grille[plateau.y][plateau.x]='.';
    }
    //====================================

}

// déplace la caisse
// plateau.x,plateau.y : position du joueur
void depl_caisse(int d_x,int d_y,Plateau &plateau){

    //si on deplace la caisse sur une case vide
    if(plateau.grille[plateau.y+d_y*2][plateau.x+d_x*2]==' ')
        plateau.grille[plateau.y+d_y*2][plateau.x+d_x*2]='$';

    //si c'est sur une destination
    else if(plateau.grille[plateau.y+d_y*2][plateau.x+d_x*2]=='.')
    {

        plateau.grille[plateau.y+d_y*2][plateau.x+d_x*2]='*';
        ++plateau.score;
    }


}

//renvoie la direction de déplacement (x,y)
void find_direction(char direction,int & d_x,int & d_y){
    switch (direction)  {
        case 'h':
            d_y =-1;
            break;
        case 'b':
            d_y=1;
            break;
        case 'd':
            d_x=1;
            break;
        case 'g':
            d_x=-1;
            break;
    }
}

//regarde si un déplacement peut être effectué
//et le traite si oui
// plateau.x,plateau.y : position du joueur
bool deplacement(char direction,Plateau &plateau){
    
    //direction de deplacement
    int d_x=0;
    int d_y=0;
    find_direction(direction,d_x,d_y);
    
    //si on essaye de pousser une caisse
    if(plateau.grille[plateau.y+d_y][plateau.x+d_x]=='$' or plateau.grille[plateau.y+d_y][plateau.x+d_x]=='*'){

        //on vérifie si la case après la caisse n'est pas un mur ou une autre caisse
        if(plateau.grille[plateau.y+d_y*2][plateau.x+d_x*2]!='#' and plateau.grille[plateau.y+d_y*2][plateau.x+d_x*2]!='$' and plateau.grille[plateau.y+d_y*2][plateau.x+d_x*2]!='*'){
            depl_caisse(d_x,d_y,plateau);
            depl_perso(d_x,d_y,plateau);
            plateau.x+=d_x; plateau.y+=d_y; //update de la position de perso
            
            //on regarde si la caisse déplacée provoque une situation où le joueur est bloqué
            if(plateau.grille[plateau.y+d_y][plateau.x+d_x]!='*')
                est_bloque(plateau,plateau.x+d_x,plateau.y+d_y);

            return true;
        }
        else
            return false;
    }

    //si on essaye de deplacer le perso vers une autre case (autre qu'une caisse)
    if (plateau.grille[plateau.y+d_y][plateau.x+d_x]!='#'){
        depl_perso(d_x,d_y,plateau);

        plateau.x+=d_x;plateau.y+=d_y; //update de la position de perso
        return true;
    }

    //on ne peut pas se déplacer/pousser de caisse
    return false;
}
