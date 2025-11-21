#include <iostream>
#include <string>
#include <fstream>

std::string cmprFicGtLine(std::string strF1, std::string strF2){
    std::ifstream  f1;
    std::ifstream  f2;
    f1.open(strF1);
    f2.open(strF2);

    if(f1.is_open() and f2.is_open()){
        std::string l1,l2;
        std::getline(f1,l1);
        std::getline(f2,l2);
        //std::cout<<"l2 = "<<l2<<" taille = "<<l2.length()<<std::endl; rien si fichier vide
        if(l1!=l2)
            return "Non";

        while(f1.good() or f2.good()){
            std::getline(f1,l1);
            std::getline(f2,l2);
            if(l1!=l2)
                return "Non";
        }
        return "Oui";

    }else{
        return "Non applicable";
    }
}

std::string cmprFicGt(std::string strF1, std::string strF2){
    std::ifstream  f1;
    std::ifstream  f2;
    f1.open(strF1);
    f2.open(strF2);

    if(f1.is_open() and f2.is_open()){
        char c1,c2;
        f1.get(c1);
        f2.get(c2);
        if(c1!=c2)
            return "Non";

        while(f1.good() or f2.good()){
            f1.get(c1);
            f2.get(c2);
            if(c1!=c2)
                return "Non";
        }
        return "Oui";

    }else{
        return "Non applicable";
    }
}

std::string cmprFic(std::string strF1, std::string strF2){
    std::string c1,c2;
    std::ifstream  f1;
    std::ifstream  f2;
    f1.open(strF1);
    f2.open(strF2);

    if(f1.is_open() and f2.is_open()){
        f1>>c1;
        f2>>c2;
        if(c1!=c2)
            return "Non";

        while(f1.good() or f2.good()){
            f1>>c1;
            f2>>c2;
            if(c1!=c2)
                return "Non";
        }
        return "Oui";

    }else{
        return "Non applicable";
    }
}

int main(){

    std::string fic1="5.1/fic1.txt";
    std::string fic2="5.1/fic2.txt";
    std::string fic3="5.1/fic3.txt";

    std::cout <<"fic1 et fic2 identiques ? " << cmprFicGtLine(fic1,fic2)<<std::endl;
    std::cout <<"fic1 et fic3 identiques ? " << cmprFicGtLine(fic1,fic3)<<std::endl;

    std::cout <<"fic1 et fic2 identiques ? " << cmprFicGt(fic1,fic2)<<std::endl;
    std::cout <<"fic1 et fic3 identiques ? " << cmprFicGt(fic1,fic3)<<std::endl;

    std::cout <<"fic1 et fic2 identiques ? " << cmprFic(fic1,fic2)<<std::endl;
    std::cout <<"fic1 et fic3 identiques ? " << cmprFic(fic1,fic3)<<std::endl;

    return 0;
}
