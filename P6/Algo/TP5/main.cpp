#include <iostream>
#include <fstream> //also include string
#include <queue>

struct ArbreTab{
    uint n;
    uint racine;
    std::string* etiquettes;
    uint* gauche;
    uint* droit;
    uint* pere;
};

struct Noeud{
    std::string etiquette;
    Noeud* gauche;
    Noeud* droit;
    Noeud* pere;
};

using ArbreBinaire = Noeud*;


//Q2
//== construire arbre a partir d'un fichier txt=======
ArbreTab init(const uint & n, const uint & racine){
    ArbreTab arb;

    arb.n = n;
    arb.racine = racine;
    arb.etiquettes = new std::string [n+1];
    arb.gauche = new uint [n+1];
    arb.droit = new uint [n+1];
    arb.pere = new uint [n+1];

    return arb;
}

void construireNoeud(ArbreTab & arb, const uint & i, const std::string & etiquette,
                    const uint & gauche, const uint & droit)
{
    arb.etiquettes[i]=etiquette;
    arb.gauche[i]=gauche;
    arb.droit[i]=droit;
    arb.pere[gauche] = i;
    arb.pere[droit] = i;
}


ArbreTab construire (const std::string & file_name){
    ArbreTab arb;

    std::ifstream fic;
    fic.open(file_name);
    if(fic.is_open()){

        uint get_uint;
        std::string get_str;

        fic>>get_uint;
        uint n = get_uint;
        fic>>get_uint;
        arb = init(n, get_uint);
        for(uint i=1; i<n+1; ++i){
            fic>>get_str;
            std::string etiquette = get_str;

            fic>>get_uint;
            uint gauche = get_uint;

            fic>>get_uint;
            uint droit = get_uint;

            construireNoeud(arb, i, etiquette, gauche, droit);
        }

    }else{
        std::cout<<"Erreur lors du l'ouverture du fichier \""
                 <<file_name<<"\"\n";
        arb = init(0,0);
    }

    return arb;
}
//==================================Q2

//Q3
//====================
//retourne pronfondeur du noeud (racine = 0)
int pronfondeur(ArbreTab arb, uint ind_noeud){
    //on remonte par le pere jusqu'a la racine
    int pronf = -1;
    while(ind_noeud!=0){
        ind_noeud = arb.pere[ind_noeud];
        ++pronf;
    }
    return pronf;
}
//=========Q3

//Q4
//=================
//parcours prefixe
void affichageNoeud(const ArbreTab & arb, const uint & n){
    std::cout<<arb.etiquettes[n]<<", ";
    if(arb.gauche[n]!=0)
        std::cout<<arb.etiquettes[arb.gauche[n]]<<", ";
    else
        std::cout<<"*, ";

    if(arb.droit[n]!=0)
        std::cout<<arb.etiquettes[arb.droit[n]]<<", ";
    else
        std::cout<<"*, ";

    if(arb.pere[n]!=0)
        std::cout<<arb.etiquettes[arb.pere[n]]<<",";
    else
        std::cout<<"*,";
    std::cout<<pronfondeur(arb, n)<<"\n";
}

void affichageBis(const ArbreTab & arb, uint n){
    if(n!=0){
        affichageNoeud(arb, n);
        if(n!=0) affichageBis(arb,arb.gauche[n]);
        if(n!=0) affichageBis(arb,arb.droit[n]);
    }
}

void affichage(const ArbreTab & arb){
    std::cout<<"\n";
    affichageBis(arb, arb.racine);
    std::cout<<"\n";
}
//============Q4

//Q6
//convertion ArbreTab -> ArbreBinaire
void convertionBis(const ArbreTab & arbTab, uint noeud, ArbreBinaire & arbBin, ArbreBinaire pere){
    if(noeud!=0){
        arbBin = new Noeud;
        arbBin->etiquette = arbTab.etiquettes[noeud];
        arbBin->pere = pere;

        if(arbTab.gauche[noeud]!=0)
            convertionBis(arbTab, arbTab.gauche[noeud], arbBin->gauche, arbBin);
        else
            arbBin->gauche = nullptr;

        if(arbTab.gauche[noeud]!=0)
            convertionBis(arbTab, arbTab.droit[noeud], arbBin->droit, arbBin);
        else
            arbBin->droit = nullptr;
    }
}
void convertion(const ArbreTab & arbTab, ArbreBinaire & arbBin){
    convertionBis(arbTab, arbTab.racine, arbBin, nullptr);
}
//============Q6

//Q6-3
//calcule pronfondeur noeud
//content de celle-ci (merci encore raphael pour la sol trouvée en P3)
//inutile par contre car on a le parent...
int pronfondeurBinCool(ArbreBinaire arb, Noeud* noeud){
    if(arb==nullptr)
        return -1;
    else if(arb==noeud)
        return 0;
    else{
        int prof = pronfondeurBinCool(arb->gauche, noeud);
        if(prof==-1) //si on a rien trouvé a gauche on regarde a droit
            prof = pronfondeurBinCool(arb->droit, noeud);
        if(prof==-1) //si y'a toujours rien a droit
            return -1;
        else 
            return 1+prof;
    }
}

int pronfondeurBin(Noeud* noeud){
    if(noeud==nullptr)
        return -1;
    else
        return 1 + pronfondeurBin(noeud->pere);
}
//==================Q6-3

//Q6-4
//affichage prefixe arbre binaire + pronfondeur
//============
void affichageNoeudBin(const ArbreBinaire & arb){
    if(arb==nullptr)
        std::cout<<"Noeud inconnu :(\n";
    else{
        std::cout<<arb->etiquette<<", ";
        if(arb->gauche!=nullptr)
            std::cout<<arb->gauche->etiquette<<", ";
        else
            std::cout<<"*, ";

        if(arb->droit!=nullptr)
            std::cout<<arb->droit->etiquette<<", ";
        else
            std::cout<<"*, ";

        if(arb->pere!=nullptr)
            std::cout<<arb->pere->etiquette<<",";
        else
            std::cout<<"*,";
        std::cout<<pronfondeurBin(arb)<<"\n";
    }
}

void affichageArbBin(ArbreBinaire arbBin){
    if(arbBin!=nullptr){
        affichageNoeudBin(arbBin);
        if(arbBin->gauche!=nullptr) affichageArbBin(arbBin->gauche);
        if(arbBin->droit!=nullptr) affichageArbBin(arbBin->droit);
    }
}

//============Q6-4

//Q7
//=============
bool estRacine(Noeud* noeud){
    return (noeud->pere==nullptr);
}

bool estFeuille(Noeud* noeud){
    return(noeud->gauche==nullptr and noeud->droit==nullptr);   
}

bool estInterne(Noeud* noeud){
    return(!estRacine(noeud) and !estFeuille(noeud));
}

bool estFilsDroit(Noeud* noeud){
    if(!estRacine(noeud))
        return(noeud->pere->droit == noeud);
    else
        return false;
}

bool estFilsGauche(Noeud* noeud){
    if(!estRacine(noeud))
        return(noeud->pere->gauche == noeud);
    else
        return false;
}
//==============Q7

//Q8
//========================
//calcul nombre de feuille
//parait plus naturel de faire en itératif
//parcours en largeur a l'aide d'une file
int nombreFeuille(ArbreBinaire arb){
    std::queue<ArbreBinaire> file;
    file.push(arb);
    uint cpt_feuille = 0;
    while(!file.empty()){
        if(estFeuille(file.front()))
            ++cpt_feuille;
        if(file.front()->gauche!=nullptr)
            file.push(file.front()->gauche);
        if(file.front()->droit!=nullptr)
            file.push(file.front()->droit);
        file.pop();
    }
    return cpt_feuille;
}
//===================Q8

//Q9
//============
void affFeuilles(ArbreBinaire arbBin){
    if(estFeuille(arbBin))
        affichageNoeudBin(arbBin);
    else{
        if(arbBin->gauche!=nullptr) affFeuilles(arbBin->gauche);
        if(arbBin->droit!=nullptr) affFeuilles(arbBin->droit);
    }
}
//=============Q9
int hauteur(ArbreBinaire arbBin){
    if(estFeuille(arbBin))
        return 0;
    else{
        int hauteurGauche = hauteur(arbBin->gauche) +1;
        int hauteurDroit = hauteur(arbBin->droit) +1;
        if(hauteurGauche>hauteurDroit)
            return hauteurGauche;
        return hauteurDroit;
    }
}
//=====Q9

//Q10
Noeud* rechercheEtiquette(ArbreBinaire arb, const std::string & etiquette){
    if(arb==nullptr)
        return nullptr;
    else if(arb->etiquette==etiquette)
        return arb;
    else{
        Noeud* eti = rechercheEtiquette(arb->gauche, etiquette);
        if(eti==nullptr)
            return rechercheEtiquette(arb->droit, etiquette);
        else
            return eti;
    }
}
//=========Q10

//Q11
//===========
//on s'enfonce puis on supprime a la remonté
void deleteArbre(ArbreBinaire & arb){
    if(arb!=nullptr){
        deleteArbre(arb->gauche);
        deleteArbre(arb->droit);
        delete arb;
        arb = nullptr;
    }
}
//========Q11

int main(){

    ArbreTab arbTab = construire("usine1.txt");
    //affichage(arbTab);
    
    ArbreBinaire arbBin;
    convertion(arbTab, arbBin);
    //affichageArbBin(arbBin);
    deleteArbre(arbBin);
    affichageArbBin(arbBin);


    return 0;
}