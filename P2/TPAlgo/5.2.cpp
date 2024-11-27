#include <iostream>
#include <string>
#include <fstream>

void wc(std::string ch1){
    std::ifstream fic;
    fic.open(ch1);
    if(fic.is_open()){

        int l=0;
        int c=0;
        int m=0;
        std::string lgn,mot;
        do{
            std::getline(fic,lgn);
            ++l;
            for(unsigned int i =0;i<lgn.length();++i){
                ++m;
                mot=lgn[i];
                for(unsigned j=0;j<mot.length();++j){
                    if(std::isspace(mot[j])==0)
                        ++c;
                }
            }
        }while(fic.good());
        std::cout<<"Ce fichier contient "<<l<< " lignes, "<<m<<" mots et "<<c<<"lettres."<<std::endl;

    }else{
        std::cout<<"Erreur lors de l'ouverture du fichier"<<std::endl;
    }
}

int main(){
    std::string ch1 = "5.1/fic1.txt";
    std::cout<<"Info sur le fichier : "<<ch1<<std::endl;
    wc(ch1);

    return 0;
}
