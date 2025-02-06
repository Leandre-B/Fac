#include <iostream>
#include <string>
#include <fstream>

const std::string NOMFIC="film.txt";

struct Film{
    std::string nomFilm;
    int annee;
    std::string nomReal;
    int duree;
    std::string langue;
};

struct EnsFilm{
    Film* tabFilm;
    int nbFilm;
};

struct Selection{
    Film** adrTabFilm; //adresse d'un tableau de pointeur
    int nbFilm;
};


void lectureFic(EnsFilm & ensFilm){
    std::string dummy;
    std::ifstream fic;
    fic.open(NOMFIC);

    if(fic.is_open()){

        fic>>ensFilm.nbFilm;

        ensFilm.tabFilm=new Film[ensFilm.nbFilm]; std::getline(fic,dummy);

        int i =0;
        while(i<ensFilm.nbFilm){
            std::getline(fic,ensFilm.tabFilm[i].nomFilm);
            std::cout<<"Test lecteurFic ensFilm.nomFilm : "<<ensFilm.tabFilm[i].nomFilm<<std::endl;

            fic>>ensFilm.tabFilm[i].annee; std::getline(fic,dummy);
            std::getline(fic,ensFilm.tabFilm[i].nomReal);
            fic>>ensFilm.tabFilm[i].duree; std::getline(fic,dummy);
            std::getline(fic,ensFilm.tabFilm[i].langue);
            ++i;
        }
    }else{
        std::cout<<"PROBLEME LORS DE L'OUVERTURE DU FICHIER !"<<std::endl;
    }
}

void affEnsFilm(EnsFilm ensFilm){
    for(int i = 0;i<ensFilm.nbFilm;++i){
        std::cout<<"----Film "<<i+1<<"----"<<std::endl;
        std::cout<<"-Nom : "<<ensFilm.tabFilm[i].nomFilm<<std::endl;
        std::cout<<"-Annee : "<<ensFilm.tabFilm[i].annee<<std::endl;
        std::cout<<"-Realisteur : "<<ensFilm.tabFilm[i].nomReal<<std::endl;
        std::cout<<"-Duree : "<<ensFilm.tabFilm[i].duree<<std::endl;
        std::cout<<"-Langue : "<<ensFilm.tabFilm[i].langue<<std::endl;
        std::cout<<std::endl;
    }

}

void addAllFilmSelection(Selection & selection,EnsFilm ensFilm){
    selection.nbFilm=ensFilm.nbFilm;
    selection.adrTabFilm = new Film* [selection.nbFilm];
    for(int i = 0;i<selection.nbFilm;++i){
        selection.adrTabFilm[i]=&ensFilm.tabFilm[i];
    }
}


void selectionFilm(Selection & selection, EnsFilm ensFilm){
    std::string real;
    int anneeMax, anneeMin, dureeMax, dureeMin;

    std::cout<<"Veuillez choisir un/des films selon les critères suivants: "<<std::endl;

    std::cout<<"Nom du realisateur (entrer 'X' pour tous les selectionner) : ";
    std::cin>>real;

    std::cout<<"Année de sortie maximale : ";
    std::cin>>anneeMax;

    std::cout<<"Année de sortie minimale : ";
    std::cin>>anneeMin;

    std::cout<<"Duree maximale : ";
    std::cin>>dureeMax;

    std::cout<<"Duree minimale : ";
    std::cin>>dureeMin;

    for(int i = 0;i<ensFilm.nbFilm;++i){
        if(ensFilm.tabFilm[i].nomReal==real)
            if(ensFilm.tabFilm[i].annee>=anneeMin and ensFilm.tabFilm[i].annee<=anneeMax)
                if(ensFilm.tabFilm[i].duree>=dureeMin and ensFilm.tabFilm[i].duree<=dureeMax)
                    //construire la selection petit a petit dynamiquement ??? Il me faut quand meme le nombre de film a inserer a l'avance non ?
    }

}


int main(){
    Selection selection;
    EnsFilm ensFilm;

    //selection.adrTabFilm = &(ensFilm.tabFilm);

    lectureFic(ensFilm);
    // affEnsFilm(ensFilm);


    return 0;
}
