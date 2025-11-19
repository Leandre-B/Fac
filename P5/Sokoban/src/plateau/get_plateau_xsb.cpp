#include "get_plateau_xsb.h"

//affiche le plateau dans le terminal
void affiche_plateau(Plateau plateau)
{
    for(int i=0;i<plateau.hauteur;++i)
    {

        for(int j=0;j<plateau.longueur;++j)
        {
            std::cout<<plateau.grille[i][j];
        }
        std::cout<<std::endl;
    }
}

/* Prend : 
-La hauteur du plateau
-La largeur de plateau
-La position du personage (x,y)
-Le nombre de caisse
-Le score (nombre de plateau sur des emplacements)
*/
bool init_variable(Plateau & plateau)
{
    std::ifstream fic;

    fic.open(plateau.chemin);

    if (fic.is_open()){
        
        //=== initialisation des variables du plateau =====
        int x_count=0; //largeure
        int y_count=0; //hauteure
        int max_l=0; //largeure maximum

        char c;

        plateau.nom=plateau.chemin;
        plateau.nom.erase(0,14);
        plateau.nom.erase(plateau.nom.length()-4,4);

        plateau.nb_caisse=0;
        plateau.score = 0;
        plateau.bloque = false;
        //================

        while(fic.good())
        {
            fic.get(c);
            if(c=='@')
            {
                plateau.x=x_count;
                plateau.y=y_count;
            }
            if(c=='$' or c=='*' )
                ++plateau.nb_caisse;

            if(c=='*')
                ++plateau.score;

            if(c!='\n')
                ++x_count;
            else
            {
                y_count++;
                if(x_count>=max_l)
                    max_l=x_count;
                x_count=0;
            }
            plateau.longueur=max_l;
            plateau.hauteur=y_count-1;
        }
        return true;
    }else{
        std::cout<<"Erreur lors du l'ouverture du fichier .xsb"<<std::endl;
        return false;
    }
}

//remplie le plateau de ' ' suivant le principe de 
//l'exploration exhaustive
void remplie_plateau(char** & grille, int y,int x)
{

    //haut
    if(grille[y-1][x]!='#' and grille[y-1][x]!=' '){
        if(grille[y-1][x]=='0')
            grille[y-1][x]=' ';
        remplie_plateau(grille,y-1,x);
    }

    //bas
    if(grille[y+1][x]!='#' and grille[y+1][x]!=' '){
        if(grille[y+1][x]=='0')
            grille[y+1][x]=' ';
        remplie_plateau(grille,y+1,x);
    }

    //droite
    if(grille[y][x+1]!='#' and grille[y][x+1]!=' '){
        if(grille[y][x+1]=='0')
            grille[y][x+1]=' ';
        remplie_plateau(grille,y,x+1);
    }

    //gauche
    if(grille[y][x-1]!='#' and grille[y][x-1]!=' '){
        if(grille[y][x-1]=='0')
            grille[y][x-1]=' ';
        remplie_plateau(grille,y,x-1);
    }
}

//récupère le plateau selon le format .xsb
bool get_plateau(Plateau & plateau)
{

    std::ifstream fic;
    fic.open(plateau.chemin);
    if (fic.is_open())
    {
        char c;

        //initialisation des variables
        if(!init_variable(plateau))
            return false;

        //initialisation de la grille
        plateau.grille=new char*[plateau.hauteur];
        for(int i=0;i<plateau.hauteur;++i)
        {
            plateau.grille[i]=new char[plateau.longueur];
        }

        //par défaut, toutes les cases sont non-jouables ('0')
        for(int i=0;i<plateau.hauteur;++i)
            for(int j=0;j<plateau.longueur;++j)
            {
                plateau.grille[i][j]='0';
            }


        while(fic.good())
        {
            //on récupere les murs
            for(int i=0;i<plateau.hauteur;++i)
            {
                int j=0;
                fic.get(c);
                while(c!='\n')
                {
                    if(c=='#')
                        plateau.grille[i][j]='#';
                    fic.get(c);
                    ++j;
                }
            }
        }

        plateau.grille[plateau.y][plateau.x]=' ';
        
        //on remplie l'intérieur des murs d'espace (cases jouables)
        remplie_plateau(plateau.grille, plateau.y, plateau.x);
        

        //on remet le curseur au début du fichier
        fic.clear();
        fic.seekg(0, std::ios::beg);

        //on ajoute à la grille les autres informations
        // '.', '@', '+', '*'
        
        while(fic.good())
        {

            for(int i=0;i<plateau.hauteur;++i)
            {
                int j=0;
                fic.get(c);
                while(c!='\n')
                {
                    if(plateau.grille[i][j]!='0' and plateau.grille[i][j]!='#')
                        plateau.grille[i][j]=c;
                    fic.get(c);
                    ++j;
                }

            }
        }
        return true;
    }
    else
    {
        std::cout<<"erreur d'ouverture du fichier .xsb"<<std::endl;;
        return false;
    }
}




