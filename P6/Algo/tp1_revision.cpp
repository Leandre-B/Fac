#include <iostream>
#include <string>
#include <array>
#include <fstream>

struct OccMot {
    std::string mot;
    unsigned int occ=0;
};


struct Maillon{
    OccMot occMot;
    Maillon* suiv = nullptr;
};

using listeMots = Maillon*;

struct TabMots{
    std::string* mots;
    unsigned int taille;
};

struct OccLettre{
    char mot;
    unsigned int occ;
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
    if(l==nullptr)
        ajoutDebut(mot,l);
    else if(mot==l->occMot.mot)
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
        if(currentPlusLong > (l->occMot.mot).length())
            return currentPlusLong;
        else
            return (l->occMot.mot).length();
    }
}

void afficheLongueur(listeMots l, int longueur){
    if(l!=nullptr){
        if(longueur==(l->occMot.mot).length())
            std::cout<<l->occMot.mot<<"\n";
        afficheLongueur(l->suiv, longueur);
    }
}

void afficheTriLongueur(listeMots l){
    int plsLong=plusLong(l);
    for(int i=1; i<=plsLong; ++i){
        afficheLongueur(l,i);
    }
}

void saisit(listeMots & l){
    int n;
    std::cout<<"Combien de mot voulez-vous saisir ? ";
    std::cin>>n;
    for(int i=0; i<n; ++i){
        std::cout<<"Entrez un mot : ";
        std::string mot;
        std::cin>>mot;
        ajoute(mot, l);
    }
}

void construit (listeMots & l, std::string nomFichier){
    std::ifstream fic;
    fic.open(nomFichier);

    if(fic.is_open()){
        std::string mot;
        while(fic.good()){
            fic>>mot;
            ajoute(mot, l);
        }
    }else{
        std::cout<<"ERREUR LORS DE L'OUVERTURE DU FICHIER "<<"\""<<nomFichier<<"\"\n";
    }
}

void remplit(TabMots & t, listeMots l){
    t.taille=taille(l);
    t.mots=new std::string[t.taille];
    for(int i=0; i<t.taille; ++i){
        t.mots[i]=l->occMot.mot;
        l=l->suiv;
    }
}
void afficheTabMot(TabMots t){
    for(int i=0; i<t.taille; ++i){
        std::cout<<t.mots[i]<<"\n";
    }
}


bool appartient_bis(std::string mot, TabMots t, int d, int f){
    if(d>f)
        return false;
    else{
        int m = (d+f)/2;
        if(mot==t.mots[m])
            return true;
        else if(mot<t.mots[m])
            return appartient_bis(mot, t, d, m-1);
        else
            return appartient_bis(mot, t, m+1, f);
    }
}
bool appartient(std::string mot, TabMots t){
    return appartient_bis(mot, t, 0, t.taille-1);
}

int main(){

    listeMots l;
    initialise(l);
    construit(l,"bouledesuif.txt");

    affiche(l);
    
    TabMots t;
    remplit(t, l);
    afficheTabMot(t);

    std::string mot;
    std::cout<<"Entrer un mot a rechercher : ";
    std::cin>>mot;

    if(appartient(mot, t)){
        std::cout<<"Le mot "<<mot<<" apparait dans le texte !\n";
    }else
        std::cout<<"Le mot "<<mot<<" n'apparait pas dans le texte :(\n";

    
    return 0;
}
