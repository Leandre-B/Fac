#include <iostream>
#include <string>
#include <array>

/**
 * Fonction de hachage de référence.
 *
 * Paramètres :
 *  * `prenom` : prénom de l'adhérent
 *  * `nom` : nom de l'adhérent
 *
 * Hachage =  Initiale(`prenom`) * 26 + Initiale(`nom`)
 */
unsigned int h(std::string prenom, std::string nom) {
    return ((prenom[0]-'A') * 26 + (nom[0]-'A'));
}

struct Adherent{
    std::string nom;
    std::string prenom;
    unsigned int num;
};

struct Alveole{
    bool occupe;
    Adherent adh;
};

struct TableHachage{
    std::array<Alveole, 676> table;
    int m = 676;
};

void initTableachage(TableHachage & t){
    for(int i=0; i<t.m; ++i){
        t.table[i].occupe=false;
    }
}

void ajoutAdh(TableHachage & t, Adherent adh){
    int index = h(adh.prenom, adh.nom);
    int i=1;
    while(t.table[index].occupe)
        ++index;
    t.table[index].adh = adh;
    t.table[index].occupe = true;
}

unsigned int trouveAdh(TableHachage & t, std::string nom, std::string prenom){
    int index = h(prenom, nom);
    int index_origine = index-1;
    int i=1;
    do{
        if(t.table[index].occupe){
            if(t.table[index].adh.prenom == prenom and
                t.table[index].adh.nom == nom)
                return t.table[index].adh.num;
            else
                index = (index+1)%676;
        }
        else
            index = (index+1)%676;

    }while(index!=index_origine);

    return 0;
}

void afficheAdhs(TableHachage & t){
    for(int i=0; i<t.m; ++i){
        if(t.table[i].occupe){
            std::cout<<i<<" : "<<t.table[i].adh.nom<<" "<<t.table[i].adh.prenom<<" "<<t.table[i].adh.num<<"\n";
        }
    }
}
// Pour vos tests et pour la question 6 :
int main() {
    TableHachage t;
    initTableachage(t);
    Adherent adh;
    adh.nom = "Doe";
    adh.prenom = "John";
    adh.num = 1;
    ajoutAdh(t, adh);

    adh.nom = "Adams";
    adh.prenom = "Amy";
    adh.num = 2;
    ajoutAdh(t, adh);

    adh.nom = "Zavatte";
    adh.prenom = "Achille";
    adh.num = 3;
    ajoutAdh(t, adh);

    adh.nom = "Zidane";
    adh.prenom = "Zinédine";
    adh.num = 4;
    ajoutAdh(t, adh);

    adh.nom = "Eustache";
    adh.prenom = "Jean";
    adh.num = 5;
    ajoutAdh(t, adh);

    adh.nom = "Dean";
    adh.prenom = "James";
    adh.num = 6;
    ajoutAdh(t, adh);

    afficheAdhs(t);
    std::cout<<trouveAdh(t, "Dean", "James")<<"\n";
    std::cout<<trouveAdh(t, "Dalton", "Joe")<<"\n";

    return 0;
}

