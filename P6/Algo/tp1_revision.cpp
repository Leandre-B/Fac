#include <iostream>
#include <string>
#include <array>

struct OccMot {
    std::string mot;
    int occ;
};


struct Maillon{
    OccMot occMot;
    Maillon* suiv;
};

using listeMots = Maillon*;

struct OccLettre{
    char mot;
    int occ;
};


using tabLettre = std::array<OccLettre, 26>;

void initialise (listeMots & l){
    l=nullptr;
}

void ajoutDebut(std::string mot, listeMots & l){
    Maillon* m = new Maillon;
    m->occMot.mot=mot;
    m->occMot.occ=1;
    m->suiv = l;
    l=m;
}

void ajoute(std::string mot, listeMots & l){
    if(mot==l->occMot.mot)
        ++l->occMot.occ;
    else if(l->occMot.mot>mot)
        ajoutDebut(mot, l);
    else{
        ajoute(mot, l->suiv);
    }
}

void affiche(listeMots & l){
    if(l!=nullptr){
        std::cout<<l->occMot.mot<<" ("<<l->occMot.occ<<")\n";
        affiche(l->suiv);
    }
}

int taille(listeMots l){
    if(l==nullptr)
        return 0;
    else
        return 1+taille(l->suiv);
}

bool estValide(listeMots l){
    if(l->suiv==nullptr){
        if(l->occMot.occ>0)
            return true;
        else
            return false;
    }else{
        if( l->occMot.mot < l->suiv->occMot.mot and l->occMot.occ >0)
            return estValide(l->suiv);
        else
            return false;
    }
}

int plusLong(listeMots l){
    if(l==nullptr)
        return 0;
    else{
        int currentPlusLong = plusLong(l->suiv);
        if(currentPlusLong > static_cast<int>((l->occMot.mot).length()))
            return currentPlusLong;
        else
            return (l->occMot.mot).length();
    }
}

void afficheLongueur(listeMots l, int longueur){
    if(l!=nullptr){
        if(longueur==static_cast<int>((l->occMot.mot).length()))
            std::cout<<l->occMot.mot<<"\n";
        afficheLongueur(l->suiv, longueur);
    }
}

int main(){

    listeMots l;
    initialise(l);
    ajoutDebut("Zoucoup", l);
    l->occMot.occ=0;
    ajoutDebut("Soucou", l);
    ajoutDebut("Mou2ou", l);
    ajoutDebut("Loucouiii", l);

    affiche(l);
    afficheLongueur(l,6);

    return 0;

}
