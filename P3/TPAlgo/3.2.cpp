#include <iostream>
#include <string>
#include <fstream>


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


void lectureFic(EnsFilm & ensFilm,std::string nomFic){
    std::string dummy;
    std::ifstream fic;
    fic.open(nomFic);

    if(fic.is_open()){

        fic>>ensFilm.nbFilm;

        ensFilm.tabFilm=new Film[ensFilm.nbFilm]; std::getline(fic,dummy);

        int i =0;
        while(i<ensFilm.nbFilm){

            std::getline(fic,ensFilm.tabFilm[i].nomFilm);
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
        std::cout<<"-Duree (en min) : "<<ensFilm.tabFilm[i].duree<<std::endl;
        std::cout<<"-Langue : "<<ensFilm.tabFilm[i].langue<<std::endl;
        std::cout<<std::endl;
    }

}

void addAllFilm(Selection & selection,EnsFilm ensFilm){
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

    std::cout<<"Duree minimale (en min) : ";
    std::cin>>dureeMin;

    std::cout<<"Duree maximale (en min) : ";
    std::cin>>dureeMax;

    //on ajoute tout les films
    addAllFilm(selection, ensFilm);


    //si un film de correspond pas, on désalloue les cases correspondantes
    for(int i = 0;i<ensFilm.nbFilm;++i){
        if(!((ensFilm.tabFilm[i].nomReal==real or real=="X") and
           (ensFilm.tabFilm[i].annee>=anneeMin and ensFilm.tabFilm[i].annee<=anneeMax) and
           (ensFilm.tabFilm[i].duree>=dureeMin and ensFilm.tabFilm[i].duree<=dureeMax))){

            //delete selection.adrTabFilm[i]; //faut le faire ???
            selection.adrTabFilm[i]=nullptr;
            }
    }

}

void affSelection(Selection selection){
    std::cout<<"Film selectione(s) : "<<std::endl<<std::endl;
    for(int i=0;i<selection.nbFilm;++i){
        if(selection.adrTabFilm[i]!=nullptr)
            std::cout<<(*selection.adrTabFilm[i]).nomFilm<<" ("
                     <<(*selection.adrTabFilm[i]).nomReal<<", "
                     <<(*selection.adrTabFilm[i]).annee<<")"<<std::endl;
    }
    std::cout<<std::endl;
}

void enregistrerSelection(Selection & selection,std::string nomFic){
    std::string dummy;
    std::ofstream fic;
    fic.open(nomFic);

    if(fic.is_open()){
        for(int i = 0;i<selection.nbFilm;++i){
            if(selection.adrTabFilm[i]!=nullptr)
                fic<<(*selection.adrTabFilm[i]).nomFilm<<" ("
                <<(*selection.adrTabFilm[i]).nomReal<<", "
                <<(*selection.adrTabFilm[i]).annee<<")"<<std::endl;
        }
    }else{
        std::cout<<"PROBLEME LORS DE L'OUVERTURE DU FICHIER !"<<std::endl;
    }
}


int main(){
    std::string ficFilm="film.txt";
    std::string ficSelection="selection.txt";
    Selection selection;
    EnsFilm ensFilm;

    //selection.adrTabFilm = &(ensFilm.tabFilm);

    lectureFic(ensFilm,ficFilm);
    affEnsFilm(ensFilm);

    selectionFilm(selection, ensFilm);
    affSelection(selection);

    enregistrerSelection(selection, ficSelection);


    return 0;
}
