#include <iostream>
#include <string>


std::string extrait (std::string e, int pos, int lg){
    if(lg<0) return "";
    else return(extrait(e,pos,lg-1)+e[pos+lg-1]);
}

bool est_signe(char c){
    bool signe=false;

    if(c=='+' or c=='-' or c=='*' or c=='/')
        signe = true;
    return signe;
}

bool est_chiffre (char c){

    bool chiffre=false;
    int i = 0;
    while(i<10 and chiffre!=true){
        if(static_cast<int>(c)-48==i)
            chiffre = true;
        ++i;
    }
    return chiffre;
}



int main(){

    // std::string e = "courgette";
    // std::cout<<extrait(e,pos,lg-1)<<std::endl; //-1 sur lg car e[pos] compris
    std::cout<<est_signe('5')<<est_signe('/')<<est_chiffre('5')<<est_chiffre('t');


    return 0;
}
