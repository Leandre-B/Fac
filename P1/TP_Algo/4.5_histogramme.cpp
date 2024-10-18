#include <iostream>
#include <array>

int main(){

    const int TAILLE=21;

    using tab = std::array<int,TAILLE>;
    tab occuNote;
    int note;
    int grdOccu=0;

    //initialiser tableau à 0 dans toutes les cases
    for (int i=0;i<TAILLE;i++){
        occuNote[i]=0;
    }

        //entrer notes
        do{
            std::cout<<"Entrez note : "<<std::endl;
            std::cin>>note;

            for (int i=0;i<TAILLE;i++){
            if(note==i)
               occuNote[i]++;;
            }
        }while ((note<=TAILLE-1 and note>=0));

        //recherche la note la plus entrée
        for(int i = 0;i<TAILLE;++i)
        {
            if(occuNote[i]>grdOccu)
            grdOccu=occuNote[i];
        }

        //affiche histogramme horizontalement
        for (int i=0;i<TAILLE;++i){
            if(i<10)
                std::cout<<"0"<<i<<" :";
            else
                std::cout<<i<<" :";

            for(int j = 0;j<occuNote[i];++j){
                std::cout<<"*";
            }
            std::cout<<std::endl;
        }

        //affiche histogramme verticalement
        for(int i=grdOccu;i>0;--i){
            for(int j=0;j<TAILLE;++j){
                if(occuNote[j]>=i){
                    std::cout<<" * ";
                }
                else{
                    std::cout<<"   ";
                }
            }
            std::cout<<std::endl;
        }
    for (int i=0;i<TAILLE;++i){
        if(i<10)
            std::cout<<"0";
        std::cout<<i<<" ";
    }

    return 0;
}
