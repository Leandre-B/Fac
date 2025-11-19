#include <iostream>
#include <fstream>


struct Noeud{
    bool est_mot = false;
    char lettre = '?';
    Noeud* fils_aine = nullptr;
    Noeud* frere_droit = nullptr;
};

using Dico = Noeud*;


void init(Dico & dico){
    dico = nullptr;
};

void ajouterMot(Dico & dico, const std::string & mot){
    if(mot!=""){
        std::string new_mot="";
        for(uint i=1; i<mot.length(); ++i)
            new_mot+=mot[i];
        
        if(dico==nullptr){
            dico = new Noeud;
            dico->lettre = mot[0];
            if(new_mot=="")
                dico->est_mot = true;
            else
                ajouterMot(dico->fils_aine, new_mot);
        }else{
            if(dico->lettre==mot[0])
                ajouterMot(dico->fils_aine, new_mot);
            else
                ajouterMot(dico->frere_droit, mot);
        }
    }
}

int taille(Dico dico){
    if(dico==nullptr)
        return 0;
    else{
        int nb_aine = 1;
        nb_aine += taille(dico->fils_aine) ;
        nb_aine += taille(dico->frere_droit);
        return nb_aine;
    }
}

void ajouterDico(Dico & dico, std::string file){
    std::ifstream fic;
    fic.open(file);
    if(fic.is_open()){
        std::string mot;
        while(fic.good()){
            fic>>mot;
            ajouterMot(dico, mot);
        }
    }else
        std::cout<<"ERREUR LORS DE L'OUVERTURE DU FICHIER \""<<file<<"\"\n";
}

//punaise j'ai fait ça du 1er coup, pas d'erreur de compilation + semble fonctionner correctement
//ça fait peur... <:'(
bool appartient(Dico dico, std::string mot){
    if(dico==nullptr or mot=="")
        return false;

    else if(mot.length()==1)
        return dico->est_mot;

    else{
        if(dico->lettre==mot[0]){
            std::string new_mot="";
            for(uint i=1; i<mot.length(); ++i)
                new_mot+=mot[i];
            return appartient(dico->fils_aine, new_mot);
        }else
            return appartient(dico->frere_droit, mot);
    }
}

void appliqueMasque(Dico dico, std::string masque, std::string & mot){
    if(dico!=nullptr){
        if(masque.length()==1 and dico->est_mot){
            if(masque[0]==dico->lettre or masque[0]=='?')
                std::cout<<mot+dico->lettre<<"\n";
        }else{
            std::string new_masque="";
                for(uint i=1; i<masque.length(); ++i)
                    new_masque+=masque[i];

            if(masque[0]==dico->lettre){
                mot+=dico->lettre;
                appliqueMasque(dico->fils_aine, new_masque, mot);
            }
            else if(masque[0]=='?'){
                Dico aux = dico;
                std::string aux_mot = mot;
                while(aux!=nullptr){
                    aux_mot+=aux->lettre;
                    appliqueMasque(aux->fils_aine, new_masque, aux_mot);
                    aux=aux->frere_droit;
                    aux_mot = mot;
                }
                delete aux;
            }
            else{
                appliqueMasque(dico->frere_droit, masque, mot);
            }
        }
    }
}

int main(){
    Dico dico;
    init(dico);
    ajouterDico(dico, "larousse.txt");
    //std::cout<<appartient(dico, "ABASOUDISSANT")<<"\n";
    std::string mot="";
    appliqueMasque(dico, "PHY?????", mot);

    return 0;
}