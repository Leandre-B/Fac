#include <iostream>
#include <string>
#include <array>

struct Lecteur{
    unsigned int num;
    std::string nom;
    std::string prenom;
    std::array<unsigned int, 10> tabIsbnLivreEmprunte;
};

struct EnsLecteur{
    std::array<Lecteur, 100> tabLecteur;
    unsigned int nb;
};

struct Livre{
    unsigned int isbn;
    std::string titre;
    std::string nomAuteur;
    bool emprunt;
}

struct EnsLivres{
    std::array<Livre, 100> tabLivres;
    unsigned int nb;
};

struct Biblio{
    EnsLivres livres;
    EnsLecteur lecteur;
};



void saisie(Lecteur & lec){
    std::cout<<"Saisir le numero du lecteur : ";
    std::cin>>lec.num;
    std::cout<<"Saisir le nom du lecteur : ";
    std::cin>>lec.nom;
    std::cout<<"Saisir le prenom du lecteur : ";
    std::cin>>lec.prenom;
}

void affiche(Lecteur lec){
    std::cout<<" N° : "<<lec.num<<std::endl
             <<" Nom : "<<lec.nom<<std::endl
             << " Prenom : "<<lec.prenom<<std::endl
             <<"-------------"<<std::endl<<std::endl;
}

void initialise (EnsLecteur & ensLecteur){
    ensLecteur.nb=0;
}

void ajoute(EnsLecteur & ensLecteur){
    Lecteur lecteur;
    saisie(lecteur);
    ensLecteur.tabLecteur[ensLecteur.nb]=lecteur;
    ++ensLecteur.nb;
}

void saiseTous(EnsLecteur & ensLecteur){
    int nbToAdd;
    std::cout<<"Combien de lecteurs voulez-vous ajouter ? ";
    std::cin>>nbToAdd;

    std::cout<<"----Saisie de "<<nbToAdd<<" lecteur(s) : ----"<<std::endl;
    for(int i = 0;i<nbToAdd;++i){
        std::cout<<"    Sasir un lecteur : "<<std::endl;
        ajoute(ensLecteur);
    }
}

void afficheTous(EnsLecteur ensLecteur){
    std::cout<<std::endl<<"---Liste des lecteurs : ---"<<std::endl<<std::endl;
    for(unsigned int i = 0;i<ensLecteur.nb;++i){
        affiche(ensLecteur.tabLecteur[i]);
    }
}

std::string rechercheNom(EnsLecteur ensLecteur, unsigned int numToSearch){
    unsigned int i =0;
    while(i<ensLecteur.nb){
        if(ensLecteur.tabLecteur[i].num==numToSearch)
            return ensLecteur.tabLecteur[i].nom;
        ++i;
    }
    return "Aucune correspondance.";
}

void emprunts(Biblio biblio){

    for(int i = 0;i<biblio.EnsLivres.nb;++i){
        /*
         *
         * si livre emprunte
         *      affiche livre
         *      regarde isbn
         *      regarde emprunt lecteur
         *          si match entre isbn livre et isbn d'un livre emprunte par un lecteur
         *              afficher lecteur
         */
    }
}


int main(){

    EnsLecteur ensLecteur;
    initialise(ensLecteur);
    saiseTous(ensLecteur);
    afficheTous(ensLecteur);

    unsigned int numToSearch;
    std::cout<<"Entrer le num du lecteur recherche : ";
    std::cin>>numToSearch;
    std::cout<<"Lecteur correspondant : "<<rechercheNom(ensLecteur, numToSearch)<<std::endl;

    return 0;
}
