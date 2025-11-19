#include <iostream>
#include <fstream>


struct Noeud{
    bool est_mot = false;
    Noeud* lettres [26] = {nullptr};
};

using Dico = Noeud*;


void init(Dico & dico){
    dico = new Noeud;
};

void ajouterMot(Dico & dico, const std::string & mot){
    if(mot=="")
        dico->est_mot=true;
    else{
        if(dico->lettres[mot[0]-'A'] == nullptr)
            dico->lettres[mot[0]-'A'] = new Noeud;

        std::string new_mot="";
        for(uint i=1; i<mot.length(); ++i)
            new_mot+=mot[i];
        ajouterMot(dico->lettres[mot[0]-'A'], new_mot);
    }
}

int taille(Dico dico){
    if(dico==nullptr)
        return 0;
    else{
        int cpt=1;
        for(int i=0; i<26; ++i){
            cpt += taille(dico->lettres[i]);
        }
        return cpt;
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

bool appartient(Dico dico, std::string mot){
    if(mot=="")
        return dico->est_mot;
    else{
        if(dico->lettres[mot[0]-'A'] == nullptr)
            return false;
        std::string new_mot="";
        for(uint i=1; i<mot.length(); ++i)
            new_mot+=mot[i];
        return appartient(dico->lettres[mot[0]-'A'], new_mot);
    }
}

void afficherMasque(Dico dico, std::string masque, std::string mot){
    if(dico!=nullptr){
        if(masque=="" and dico->est_mot==true){
            std::cout<<mot<<"\n";
        }
        else{
            std::string new_masque="";
            for(uint j=1; j<masque.length(); ++j)
                new_masque+=masque[j];

            for(int i=0; i<26; ++i){
                if( (int(masque[0])== 'A'+i) or masque[0]=='?'){
                    afficherMasque(dico->lettres[i], new_masque, mot+char('A'+i));
                }
            }
            
        }
    }
}


int main(){
    Dico dico;
    init(dico);
    ajouterDico(dico, "larousse.txt");
    std::cout<<taille(dico)-1<<"\n"; // -1 car premier noeud n'est pas un lettre

    afficherMasque(dico, "PI??A", "");

    return 0;
}