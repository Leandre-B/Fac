//j'ai pas sauvegardé, j'ai perdu +1h de travail
//flemme de continuer
#include <iostream>
#include <string>
#include <fstream>
#include <queue>

//Q1
//=== Struct de données génération =======
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
    Noeud* parentG=nullptr;
    Noeud* parentD=nullptr;
};

using ArbGen = Noeud*;
//====================================


//=== Création arbre généalogique =======
Individu indList(std::string name){
    Individu ind;
    if(name=="riri"){
        ind.nom="duck";
        ind.prenom="riri";
        ind.dateNaiss.jour=23;
        ind.dateNaiss.mois=2;
        ind.dateNaiss.annee=2013;
    }

    else if(name=="fifi"){
        ind.nom="duck";
        ind.prenom="fifi";
        ind.dateNaiss.jour=30;
        ind.dateNaiss.mois=12;
        ind.dateNaiss.annee=2023;
    }

    else if(name=="loulou"){
        ind.nom="duck";
        ind.prenom="loulou";
        ind.dateNaiss.jour=23;
        ind.dateNaiss.mois=02;
        ind.dateNaiss.annee=2003;
    }
    
    else if(name=="donald"){
        ind.nom="duck";
        ind.prenom="donald";
        ind.dateNaiss.jour=3;
        ind.dateNaiss.mois=10;
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

Noeud* creerNoeud(const ArbGen & parentG, const ArbGen & parentD){

    ArbGen arb = new Noeud;
    Individu ind;
    //saisieIndividu(ind);

    std::string name_ind;
    std::cin>>name_ind;
    ind = indList(name_ind);
    arb->individu=ind;
    arb->parentG=parentG;
    arb->parentD=parentD;

    return arb;
    
}

ArbGen creerArb(){
    ArbGen v = nullptr;
    ArbGen C = creerNoeud(v,v);
    ArbGen B = creerNoeud(v,v);
    ArbGen A = creerNoeud(B,C); 
    return A;
}
//=================

//Q2
void saisieIndividu(Individu & ind){
    std::cout<<"nom :"; 
    std::cin>>ind.nom;

    std::cout<<"prenom : ";
    std::cin>>ind.prenom;

    std::cout<<"dateNaiss (jour/mois/annee) : ";
    std::cin>>ind.dateNaiss.jour>>ind.dateNaiss.mois>>ind.dateNaiss.annee;
}

//Q3
bool estMemeIndividu(const Individu & ind1, const  Individu & ind2){
    bool same = true;
    if(ind1.nom!=ind2.nom) same=false;
    else if(ind1.prenom!=ind2.prenom) same=false;
    else if(ind1.dateNaiss.jour!=ind2.dateNaiss.jour) same=false;
    else if(ind1.dateNaiss.mois!=ind2.dateNaiss.mois) same=false;
    else if(ind1.dateNaiss.annee!=ind2.dateNaiss.annee) same=false;
    return same;
}

//Q4
//parcours de l'arbre en prefixe
Noeud* rechercheInd(ArbGen arb, Individu ind){
    if(arb==nullptr)
        return nullptr;
    else if(estMemeIndividu(arb->individu, ind))
        return arb;
    else{
        Noeud* recherche = rechercheInd(arb->parentG, ind);
        if(recherche==nullptr) //si on l'a pas trouvé à partir du parent Gauche
            return rechercheInd(arb->parentD, ind);
        else
            return recherche;
    }
}

// Q5
// Ajouter dans un arbre un individu ind1 comme parent d’un autre individu ind2
void ajouterParent(ArbGen & arb, Individu ind1, Individu ind2){
    Noeud* ptr_ind2 = rechercheInd(arb, ind2);
    if(ptr_ind2!=nullptr){
        if(ptr_ind2->parentG==nullptr){
            ptr_ind2->parentG = new Noeud;
            ptr_ind2->parentG->individu = ind1;
            ptr_ind2->parentG->parentG = nullptr;
            ptr_ind2->parentG->parentD = nullptr;
        }
        else if(ptr_ind2->parentD==nullptr){
            ptr_ind2->parentD = new Noeud;
            ptr_ind2->parentD->individu = ind1;
            ptr_ind2->parentD->parentG = nullptr;
            ptr_ind2->parentD->parentD = nullptr;
        }
    }
}

//Q6
//echange deux parent de l'enfant
void echangeParent(ArbGen & enfant){
    Noeud* aux = enfant->parentD;
    enfant->parentD = enfant->parentG;
    enfant->parentG = aux;
}

//Q7
void affIndividu(const Individu & ind){
    std::cout<<"Nom : "<<ind.nom<<"\n"
             <<"Prenom : "<<ind.prenom<<"\n"
             <<"Naiss : "<<ind.dateNaiss.jour<<"/"<<ind.dateNaiss.mois<<"/"<<ind.dateNaiss.annee<<"\n";
}

//Q8
//prefixe
void affFamille(ArbGen gen){
    if(gen!=nullptr){
        affIndividu(gen->individu); std::cout<<"\n";
        if(gen->parentD!=nullptr) affFamille(gen->parentD);
        if(gen->parentG!=nullptr) affFamille(gen->parentG);
    }
}

//largeur (genération par génération)
void affFamilleLarg(ArbGen gen){
    std::queue<ArbGen> q;
    q.push(gen);
    while(!q.empty()){
        affIndividu(q.front()->individu); std::cout<<"\n";
        if(q.front()->parentG!=nullptr) q.push(q.front()->parentG);
        if(q.front()->parentD!=nullptr) q.push(q.front()->parentD);
        q.pop();
    } 
}

//Q9
//hauteur de l'arbre
int nombreGen (ArbGen arb){
    if(arb==nullptr)
        return 0;
    else{
        int nbG = nombreGen(arb->parentG);
        int nbD = nombreGen(arb->parentD);
        if(nbG>nbD)
            return 1 + nbG;
        else
            return 1 + nbD;
    }    
}

//Q10
//nombre de gen complete
//retourn le plus petit arbre complet (inverse condition Q9)
int nombreGenCmplt (ArbGen arb){
    if(arb==nullptr)
        return 0;
    else{
        int nbG = nombreGen(arb->parentG);
        int nbD = nombreGen(arb->parentD);
        if(nbG<nbD)
            return 1 + nbG;
        else
            return 1 + nbD;
    }    
}

//Q10
//verif validité argbre géné (parent plus vieux qu'enfant)
//verif que les années car bon un parent qui a 3 mois de plus que sont enfant....
//en fait si pas des Hommes ça passe mdr
//osef
bool valideGen(ArbGen gen){
    if(gen==nullptr)
        return true;
    else{
        if(gen->parentG!=nullptr){
            if( (gen->parentG->individu.dateNaiss.annee) > (gen->individu.dateNaiss.annee) )
                return(valideGen(gen->parentG));
            else
                return false;
        }
        if(gen->parentD!=nullptr){
            if( (gen->parentD->individu.dateNaiss.annee) > (gen->individu.dateNaiss.annee) )
                return(valideGen(gen->parentG));
            else
                return false;
        }
        return true; //pas de parents donc OK
    }
}

//Q11
// creer arbre gen a partir : 
// d'un individu, l'arbGen de son 1er parent et celui de son 2eme parent
ArbGen fusionAbrGen(Individu ind, ArbGen arbPG, ArbGen arbPD){
    ArbGen nouveau = new Noeud;
    nouveau->individu = ind;
    nouveau->parentG = arbPG;
    nouveau->parentD = arbPD;

    return nouveau;
}

//Q12 
//creer arbre a partir du fichier gene.txt
//plein de ligne genre : 
//81 nom81 quatrevingtun 11 7 1677 0 0
// 81      nom81   quatrevingtun    11     7     1677    0       0
//num ind | nom |     prenom    | jour | mois | annee |num p1 | nump2
//fichier dans l'ordre (parent avant enfant)

struct NoeudTab{
    Individu individu;
    int parentG;
    int parentD;
};


void convert(ArbGen & arb, NoeudTab* tab, int posInd){
    if(posInd!=-1){
        arb = new Noeud;
        arb->individu = tab[posInd].individu;
        //parent gauche
        if(tab[posInd].parentG!=-1){
            arb->parentG = new Noeud;
            convert(arb->parentG, tab, tab[posInd].parentG);
        }else
            arb->parentG=nullptr;

        //parent droit
        if(tab[posInd].parentD!=-1){
            arb->parentD = new Noeud;
            convert(arb->parentD, tab, tab[posInd].parentD);
        }else
            arb->parentD=nullptr;

    }
}

ArbGen genFromFile(std::string fileName){
    std::ifstream fic;
    fic.open(fileName);
    NoeudTab* tabInd;
    tabInd = new NoeudTab [100];
    if(fic.is_open()){
        int get_int;
        std::string get_str;

        while(fic.good()){
            Individu ind;
            fic>>get_int;
            int i = get_int - 1;

            //nom
            fic>>get_str;
            tabInd[i].individu.nom = get_str;

            //prenom
            fic>>get_str;
            tabInd[i].individu.prenom = get_str;

            //jour
            fic>>get_int;
            tabInd[i].individu.dateNaiss.jour = get_int;

            //mois
            fic>>get_int;
            tabInd[i].individu.dateNaiss.mois = get_int;

            //annee
            fic>>get_int;
            tabInd[i].individu.dateNaiss.annee = get_int;

            //annee
            fic>>get_int;
            tabInd[i].parentG = get_int - 1;

            //parentD
            fic>>get_int;
            tabInd[i].parentD = get_int - 1;
        }

        ArbGen arb;
        convert(arb, tabInd, 0);
        delete[] tabInd;
        return arb;

    }else{
        std::cout << "erreur lors de l'ouverture du fichier \""
                  << fileName <<"\"\n";
        return nullptr;
    }

}

int main(){


    ArbGen gen = genFromFile("gene.txt");
    affFamilleLarg(gen);
    std::cout<<nombreGenCmplt(gen);
    return 0;
}