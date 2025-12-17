#include <iostream>
#include <fstream>

/**
 * Représente un enregistrement (une ligne) de la table de base de données
 */
struct EnregistrementBDD {
    std::string id;
    std::string prenom;
    std::string nom;
    int age;
};

/**
 * Les valeurs de la table sont stockées dans une liste chaînée.
 * MaillonBDD est un maillon de cette liste simplement chaînée.
 */
struct MaillonBDD {
    EnregistrementBDD enreg;
    MaillonBDD *suiv;
};
using ListeBDD = MaillonBDD*;

/**
 * L'index unique est représenté grâce à un Arbre Binaire de Recherche.
 * NoeudIU est un nœud de cet ABR.
 * Attention : il ne stocke pas directement la valeur indexée, mais un pointeur vers le maillon.
 */
struct NoeudIU {
    MaillonBDD *maillon;
    NoeudIU *sag;
    NoeudIU *sad;
};
using IndexUnique = NoeudIU *;

/**
 * Une table de base de données contient les valeurs (liste des différentes lignes) et un index unique.
 */
struct TableBDD {
    IndexUnique index;
    ListeBDD valeurs;
};

/**
 * Crée un enregistrement (une ligne de la table de base de données) à partir des informations fourniées en paramètre.
 */
EnregistrementBDD creeEnregistrement(std::string id, std::string prenom, std::string nom, int age) {
    EnregistrementBDD e;

    e.id = id;
    e.prenom = prenom;
    e.nom = nom;
    e.age = age;

    return e;
}

void initTable(TableBDD & table){
    table.valeurs = nullptr;
    table.index = nullptr;
}

bool ajoutIU(IndexUnique & iu, MaillonBDD *m){
    if(iu==nullptr){
        iu = new NoeudIU;
        iu->maillon = m;
        iu->sag = nullptr;
        iu->sad = nullptr;
        return true;
    }
    if(iu->maillon->enreg.id == m->enreg.id)
        return false;
    else{
        if(m->enreg.id > iu->maillon->enreg.id)
            return ajoutIU(iu->sag, m);
        else
            return ajoutIU(iu->sad, m);
    }
}



bool ajoutTable(TableBDD & table, EnregistrementBDD e){
    MaillonBDD* m = new MaillonBDD;
    m->enreg = e;
    m->suiv = nullptr;
    if(ajoutIU(table.index, m)){
        m->suiv = table.valeurs;
        table.valeurs=m;
    }else{
        delete m;
        return false;
    }
    return true;
}

void charge(TableBDD & table, std::string nomFichier){
    std::ifstream fic;
    fic.open(nomFichier);
    std::string id, nom, prenom;
    int age;
    fic>>id;
    while(fic.good()){
        fic>>nom;
        fic>>prenom;
        fic>>age;
        EnregistrementBDD e = creeEnregistrement(id,nom, prenom, age);
        ajoutTable(table, e);
        fic>>id;
    }
}


MaillonBDD * recherche(IndexUnique iu, std::string id){
    if(iu==nullptr)
        return nullptr;
    else{
        if(iu->maillon->enreg.id == id)
            return iu->maillon;
        else
        {
            if(iu->maillon->enreg.id < id)
                return recherche(iu->sag, id);
            else
                return recherche(iu->sad, id);
        }
    }
}

IndexUnique plsGrandPred(IndexUnique & iu){
    if(iu->sad==nullptr)
        return iu;
    else
        return plsGrandPred(iu->sad);
}
void supprimeIU(IndexUnique & iu, std::string id){
    if(iu!=nullptr){
        if(iu->maillon->enreg.id == id){
            if(iu->sag==nullptr and iu->sad==nullptr){
                delete iu;
                iu = nullptr;
            }
            else if(iu->sag==nullptr and iu->sad!=nullptr){
                iu->maillon->enreg.id = iu->sag->maillon->enreg.id;
                delete iu->sag;
                iu->sag = nullptr;
            }
            else if(iu->sag!=nullptr and iu->sad==nullptr){
                iu->maillon->enreg.id = iu->sad->maillon->enreg.id;
                delete iu->sad;
                iu->sad = nullptr;
            }else{
                IndexUnique pred = nullptr;
                pred = plsGrandPred(iu->sag);

                iu->maillon->enreg.id = pred->maillon->enreg.id;
                supprimeIU(iu->sad, pred->maillon->enreg.id);
            }

        }
        else
        {
            if(iu->maillon->enreg.id < id)
                return supprimeIU(iu->sag, id);
            else
                return supprimeIU(iu->sad, id);
        }
    }
}

void supprimeListe(ListeBDD & liste, std::string id){
    if(liste!=nullptr){
        if(liste->enreg.id == id){
            ListeBDD aux = liste;
            liste->suiv = liste->suiv->suiv;
            delete aux;
        }else
            supprimeListe(liste->suiv, id);
    }
}

void supprimeTable(TableBDD & table, std::string id){
    supprimeIU(table.index, id);
    supprimeListe(table.valeurs, id);
}


// Pour vos tests :
int main() {
    TableBDD table;
    initTable(table);
    charge(table, "enreg.txt");

    supprimeIU(table.index, "GomAdd");
    supprimeListe(table.valeurs, "GomAdd");

    return 0;
}
