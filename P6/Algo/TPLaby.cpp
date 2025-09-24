#include <iostream>
#include <array>

#include <cstdlib>
#include <ctime>

const uint NBLIGNES = 20;
const uint NBCOL = 30;

using Labyrinthe = std::array<std::array<char, NBCOL>, NBLIGNES>;

//couple (numLigne, numCol)
struct Position{
    uint x;
    uint y;
};
//===== Debut Def PilePosition ==========
struct PilePosition{
    std::array<Position, NBCOL*NBLIGNES> pile;
    uint t;
    uint tmax = NBCOL*NBLIGNES;
};

void initPile(PilePosition & p){
    p.t=0;
}

bool estVide(const PilePosition & p){
    return (p.t==0);
}

void empiler(PilePosition & p, const Position & pos){
    if(p.t<p.tmax){
        ++p.t;
        p.pile[p.t-1]=pos;
    }else
        std::cout<<"Pile pleine\n";
}

void depiler(PilePosition & p){
    if(p.t>0) {
        --p.t;
    }else
        std::cout<<"La pile est déjà vide\n";
}

Position sommet(PilePosition & p){
    if(p.t>0)
        return p.pile[p.t-1];
    else{
        std::cout<<"PilePosition vide, '0' est retourné\n";
        Position pos;
        pos.x=0; pos.y=0;
        return pos;
    }
}

void vide(PilePosition & p){
    p.t=0;
}

//======Fin def PilePosition =======
void affLaby(const Labyrinthe & laby){
    for(uint i=0; i<NBLIGNES; ++i){
        for(uint j=0; j<NBCOL; ++j)
            std::cout<<laby[i][j];
        std::cout<<std::endl;
    }
}
void initLaby(Labyrinthe & laby){
    for(uint i=1; i<NBLIGNES-1; ++i){
        for(uint j=1; j<NBCOL-1; ++j)
            laby[i][j]=' ';
    }

    //ligne du haut/bas
    for(uint i=0; i<NBLIGNES; ++i){
        laby[i][0]='*';
        laby[i][NBCOL-1]='*';
    }

    //murs gauche et droite
    for(uint i=0; i<NBCOL; ++i){
        laby[0][i]='*';
        laby[NBLIGNES-1][i]='*';
    }
}

void ajoutObstacle(Labyrinthe & laby, const float & ratio){
    srand(time(nullptr));

    uint t=(NBCOL-1)*(NBLIGNES-1);
    uint ind = t*ratio;
    uint rdm;
    for(uint i=1; i<NBLIGNES-1; ++i){
        for(uint j=1; j<NBCOL-1; ++j){
            rdm=rand()%t;
            if(rdm<ind){
                laby[i][j]='*';
                --ind; --t;
            }else
                 --t;   
        }
    }
}

void ajouteSymbRdm(Labyrinthe & laby, const char & symb){
    srand(time(nullptr));
    bool ajoute = false;
    while(!ajoute){
        uint x = rand()%(NBLIGNES-2)+1;
        uint y = rand()%(NBCOL-2)+1;
        if(laby[x][y]==' '){
            laby[x][y]=symb;
            ajoute = true;
        }
    }
}

void ajoutSourisFromage(Labyrinthe & laby){
    ajouteSymbRdm(laby,'S');
    ajouteSymbRdm(laby,'F');
}

Position posistionLibre(const Labyrinthe & laby, const Position & pos){
    Position pLibre; pLibre.x=0; pLibre.y=0;
    //en bas
    if(laby[pos.x+1][pos.y]==' ' or laby[pos.x+1][pos.y]=='F'){
        pLibre.x=pos.x+1; pLibre.y=pos.y;
    }
    //en haut
    else if(laby[pos.x-1][pos.y]==' ' or laby[pos.x-1][pos.y]=='F'){
        pLibre.x=pos.x-1; pLibre.y=pos.y;
    }
    //a droite
    else if(laby[pos.x][pos.y+1]==' ' or laby[pos.x][pos.y+1]=='F'){
        pLibre.x=pos.x; pLibre.y=pos.y+1;
    }
    //a gauche
    else if(laby[pos.x][pos.y-1]==' ' or laby[pos.x][pos.y-1]=='F'){
        pLibre.x=pos.x; pLibre.y=pos.y-1;
    }
    return pLibre;
}

Position posSouris(const Labyrinthe & laby){
    Position p;
    p.x=0; p.y=0;
    for(uint i=0; i<NBLIGNES; ++i){
        for(uint j=0; j<NBCOL; ++j){
            if(laby[i][j]=='S'){
                p.x=i; p.y=j;
                return p;
            }
        }
    }
    std::cout<<"Erreur : position de la souris non trouvé (return (0,0))\n";
    return p;
}


void resoudreLaby(Labyrinthe laby){
    PilePosition pile;
    bool trouve=false;
    Position posS = posSouris(laby);
    Position posSourisOrigin = posS;
    do{
        Position posLibre =posistionLibre(laby, posS);
        if(!(posLibre.x==0 and posLibre.y==0)){ //si une position libre autour est trouvée
            if(laby[posLibre.x][posLibre.y]=='F')
                trouve=true;
            else{
                laby[posS.x][posS.y]='.'; //on laisse une marque
                empiler(pile, posS); //on memorise la position dans la pile
                posS=posLibre; //on déplace la souris sur la position libre
            }
        }else{ //aucune position libre trouvée autour
            depiler(pile);
            posS = sommet(pile);
        }
    }while(!estVide(pile) and !trouve);

    laby[posSourisOrigin.x][posSourisOrigin.y]='S';
    if(trouve)
        std::cout<<"Fromage trouvé en : "<<sommet(pile).x<<" "<<sommet(pile).y<<"\n"; //pas bon
    else
        std::cout<<"Fromage non trouvé.. :(\n";
    affLaby(laby);
}

int main(){
    Labyrinthe laby;
    initLaby(laby);
    ajoutObstacle(laby, 0.0);
    ajoutSourisFromage(laby);
    affLaby(laby);
    resoudreLaby(laby);
    return 0;
}