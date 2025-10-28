#include <iostream>
#include <fstream> //also include string


struct ArbreTab{
    uint n;
    uint racine;
    std::string* etiquettes;
    uint* gauche;
    uint* droite;
    uint* pere;
};

//Q2
//== construire arbre a partir d'un fichier txt=======
ArbreTab init(const uint & n, const uint & racine){
    ArbreTab arb;

    arb.n = n;
    arb.racine = racine;
    arb.etiquettes = new std::string [n+1];
    arb.gauche = new uint [n+1];
    arb.droite = new uint [n+1];
    arb.pere = new uint [n+1];

    return arb;
}

void construireNoeud(ArbreTab & arb, const uint & i, const std::string & etiquette,
                    const uint & gauche, const uint & droite)
{
    arb.etiquettes[i]=etiquette;
    arb.gauche[i]=gauche;
    arb.droite[i]=droite;
    arb.pere[gauche] = i;
    arb.pere[droite] = i;
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
            uint droite = get_uint;

            construireNoeud(arb, i, etiquette, gauche, droite);
        }

    }else{
        std::cout<<"Erreur lors du l'ouverture du fichier \""
                 <<file_name<<"\"\n";
        arb = init(0,0);
    }

    return arb;
}
//==================================

//Q3
//====================
//retourne pronfondeur du noeud (racine = 0)
int pronfondeur(ArbreTab arb, uint ind_noeud){
    //on remonte par le pere jusqu'a la racine
    uint pronf = 0;
    while(ind_noeud!=0){
        ind_noeud = arb.pere[ind_noeud];
        ++pronf;
    }
    return pronf;
}
//======

//Q4
//=================
//parcours prefixe
void affichageNoeud(const ArbreTab & arb, const uint & n){
    std::cout<<arb.etiquettes[n]<<", ";
    if(arb.gauche[n]!=0)
        std::cout<<arb.etiquettes[arb.gauche[n]]<<", ";
    else
        std::cout<<"*, ";

    if(arb.droite[n]!=0)
        std::cout<<arb.etiquettes[arb.droite[n]]<<", ";
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
        if(n!=0) affichageBis(arb,arb.droite[n]);
    }
}

void affichage(const ArbreTab & arb){
    std::cout<<"\n";
    affichageBis(arb, arb.racine);
    std::cout<<"\n";
}
//============

int main(){

    ArbreTab arb = construire("usine1.txt");
    affichage(arb);

    return 0;
}