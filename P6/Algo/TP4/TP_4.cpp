//j'ai pas sauvegardé, j'ai perdu +1h de travail
//flemme de continuer
#include <iostream>
#include <string>




struct Date{
    uint jour;
    uint mois;
    uint annee;
};

struct Individu{
    std::string nom;
    std::string prenom;
    Date dateNaiss;
};

struct Noeud{
    Individu individu;
    Noeud* parent1=nullptr;
    Noeud* parent2=nullptr;
};

using ArbGen = Noeud*;

Individu indList(std::string name){
    Individu ind;
    if(name=="riri"){
        ind.nom="duck";
        ind.prenom="riri";
        ind.dateNaiss.jour=23;
        ind.dateNaiss.annee=2;
        ind.dateNaiss.annee=2013;
    }

    else if(name=="fifi"){
        Individu fifi;
        ind.nom="duck";
        ind.prenom="fifi";
        ind.dateNaiss.jour=30;
        ind.dateNaiss.annee=12;
        ind.dateNaiss.annee=2023;
    }
    
    else if(name=="donald"){
        ind.nom="duck";
        ind.prenom="donald";
        ind.dateNaiss.jour=3;
        ind.dateNaiss.annee=10;
        ind.dateNaiss.annee=1999;
    }
    else{
        //default
        ind.nom="defaultNom";
        ind.prenom="defaultPrenom";
        ind.dateNaiss.jour=0;
        ind.dateNaiss.annee=0;
        ind.dateNaiss.annee=0;
    }
    return ind;
}

void saisieIndividu(Individu & ind){
    std::cout<<"nom :"; 
    std::cin>>ind.nom;

    std::cout<<"prenom : ";
    std::cin>>ind.prenom;

    std::cout<<"dateNaiss (jour/mois/annee) : ";
    std::cin>>ind.dateNaiss.jour>>ind.dateNaiss.mois>>ind.dateNaiss.annee;
}

bool estMemeIndividu(const Individu & ind1, const  Individu & ind2){
    bool same = true;
    if(ind1.nom!=ind2.nom) same=false;
    else if(ind1.prenom!=ind2.prenom) same=false;
    else if(ind1.dateNaiss.jour!=ind2.dateNaiss.jour) same=false;
    else if(ind1.dateNaiss.mois!=ind2.dateNaiss.mois) same=false;
    else if(ind1.dateNaiss.annee!=ind2.dateNaiss.annee) same=false;
    return same;
}

//parcours de l'arbre en largeur
Noeud* rechercheInd(ArbGen arb, Individu ind){
    if(arb==nullptr)
        return nullptr;
    else if(estMemeIndividu(arb->individu, ind))
        return arb;
    else{
        Noeud* recherche = rechercheInd(arb->parent1, ind);
        if(recherche==nullptr) //si on l'a pas trouvé à partir du parent 1
            return rechercheInd(arb->parent2, ind);
        else
            return nullptr;
    }
}


ArbGen creerArb(const ArbGen & parent1, const ArbGen & parent2){

    ArbGen arb = new Noeud;
    Individu ind;
    //saisieIndividu(ind);
    std::string name_ind;
    std::cin>>name_ind;
    ind = indList(name_ind);
    arb->individu=ind;
    arb->parent1=parent1;
    arb->parent2=parent2;

    return arb;
    
}

ArbGen famille1(){

    ArbGen C = creerArb(nullptr, nullptr);
    ArbGen B = creerArb (nullptr, nullptr);
    ArbGen A = creerArb(B,C);
    return A;
}

int main(){


    ArbGen gen1 = famille1();
    Individu r = indList("riri");
    std::cout<<r->individu.nom;
    //Noeud* n = rechercheInd(gen1,r);
    //std::cout<<n->individu.nom;
    
    return 0;
}