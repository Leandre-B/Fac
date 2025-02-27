#include <string>
#include <iostream>
#include <array>
#include <fstream>

struct  t_main{
    std::string nom;
    std::array<int, 1> tabh;
    unsigned int nbCartes;
};

struct t_tour{
  std::array<t_main, 6> mains;
  int nbJ;
};


void charger_tour(std::string f, t_tour & tour){
    std::ifstream fic;
    fic.open(f);
    if(fic.is_open()){
        fic>>tour.nbJ;
        std::cout<<"nbJ "<<tour.nbJ<<std::endl;
        for(int i = 0;i<tour.nbJ;++i){

            fic>>tour.mains[i].nom;
            std::cout<<"nom "<<tour.mains[i].nom<<std::endl;

            fic>>tour.mains[i].nbCartes;
            std::cout<<"nbC "<<tour.mains[i].nbCartes<<std::endl;

            for(unsigned int j = 0;j<tour.mains[i].nbCartes;++j){
                fic>>tour.mains[i].tabh[j];
                std::cout<<tour.mains[i].tabh[j]<<std::endl;
            }
        }

    }else{
        std::cout<<"Erreur lors de l'ouverture du fichier."<<std::endl;
    }
}

int max_main(t_main main){
    int max=main.tabh[0];
    for(unsigned int i = 1;i<main.nbCartes;++i){
        if(main.tabh[i]>max)
            max=main.tabh[i];
    }
    return max;
}


int main(){
    t_tour t1,t2;
    std::string f1 = "tour1.txt";
    std::string f2 = "tour2.txt";
    charger_tour(f1,t1);

    return 0;
}
