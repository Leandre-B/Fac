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

    std::cout<<"Année de sortie minimale : ";
    std::cin>>anneeMin;

    std::cout<<"Année de sortie maximale : ";
    std::cin>>anneeMax;

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
            //--selection.nbFilm;
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
        fic<<selection.nbFilm<<std::endl;
        for(int i = 0;i<selection.nbFilm;++i){
            if(selection.adrTabFilm[i]!=nullptr)
                fic<<(*selection.adrTabFilm[i]).nomFilm<<std::endl
                <<(*selection.adrTabFilm[i]).annee<<std::endl
                <<(*selection.adrTabFilm[i]).nomReal<<std::endl
                <<(*selection.adrTabFilm[i]).duree<<std::endl
                <<(*selection.adrTabFilm[i]).langue<<std::endl;
        }
    }else{
        std::cout<<"PROBLEME LORS DE L'OUVERTURE DU FICHIER !"<<std::endl;
    }
}

int nbFilmCommuns(Selection selec1, Selection selec2){
    int nbCommun=0;
    int j;
    bool trouve;

    for(int i =0; i<selec1.nbFilm; ++i){
        j=0;
        trouve = false;
        while(j<selec2.nbFilm and !trouve){
            if(selec1.adrTabFilm[i]!=nullptr and selec2.adrTabFilm[j]!=nullptr)
                if(selec1.adrTabFilm[i]==selec2.adrTabFilm[j]){
                    trouve = true;
                    ++nbCommun;
                }
            ++j;
        }
    }

    return nbCommun;
}

void triSelection(Selection & selection){
    //bubble sort pck flemme

    Film* temp;

    for(int i = 0;i<selection.nbFilm-1;++i){
        for(int j = i+1;j<selection.nbFilm;++j){
            if(selection.adrTabFilm[i]!=nullptr and selection.adrTabFilm[j]!=nullptr)
                if((*selection.adrTabFilm[i]).annee>(*selection.adrTabFilm[j]).annee){
                    temp = selection.adrTabFilm[j];
                    selection.adrTabFilm[j]=selection.adrTabFilm[i];
                    selection.adrTabFilm[i]=temp;
                }

        }
    }

}

int main(){
    std::string ficFilm="film.txt";
    std::string ficSelection="selection.txt";
    Selection selection1,selection2;
    EnsFilm ensFilm;

    //selection1.adrTabFilm = &(ensFilm.tabFilm);

    lectureFic(ensFilm,ficFilm);
    affEnsFilm(ensFilm);

    selectionFilm(selection1, ensFilm);
    affSelection(selection1);

    // enregistrerSelection(selection1, ficSelection);

    selectionFilm(selection2, ensFilm);
    affSelection(selection2);

    std::cout<<"Il y'a "<<nbFilmCommuns(selection1, selection2)<<" film(s) en commun(s) entre les deux selections"<<std::endl;

    triSelection(selection1);
    affSelection(selection1);

    return 0;
}
