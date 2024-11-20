#include <iostream>
#include <string>

std::string copie(std::string s, int i, int j){
    std::string copieS;

    for(int k = 0;k<j;++k){
        copieS+=s[(i-1)+k];
        // std::cout<<s[(i-1)+k];
    }
    return copieS;
}

void supprime(std::string & s, int i, int j){

    std::string sGauche = copie(s , 0 , i);
    // std::cout<<"G : "<<copie(s , 0 , i)<<std::endl;

    std::string sDroite = copie(s , i+j , s.length()-i-j+1);
    // std::cout<<"D : "<<copie(s , i+j , s.length()-i-j-2)<<std::endl;

    s=sGauche + sDroite;
}

void insere (std::string s1, std::string & s2, int i){

    std::string s2G = copie(s2,0,i);
    std::string s2D = copie(s2,i,s2.length());
    s2 = s2G + s1 +s2D;
}

int position (std::string s1, std::string s2){
    unsigned int j;
    unsigned int i = 0;
    bool sameL;
    while(i<s2.length()-s1.length()){
        j=0;
        sameL=true;
        while(j<s1.length() and sameL ){
            if(s2[i+j]!=s1[j])
                sameL=false;
            ++j;
        }
        if(sameL)
            return i+1;
        ++i;
    }
    return -1;
}

int main(){
    /*
    std::string s;
    int i,j;

    std::cout<<"saisie chaine : ";
    std::cin>>s;

    std::cout<<"saisir a partir de quel char on veut copier la chaine : ";
    std::cin>>i;

    std::cout<<"saisir le nbr de char qu'on veut copier/supprimer : ";
    std::cin>>j;

    supprime(s, i, j);
    std::cout<<s<<std::endl;
    */

    /*
    int i;
    std::string s1, s2;
    std::cout <<"Saisie s1 : ";
    std::cin>>s1;
    std::cout <<"Saisie s2 : ";
    std::cin>>s2;
    std::cout<<"Saisir position ou inserer s1 dans s2 : ";
    std::cin>>i;
    insere(s1,s2,i);
    std::cout<<s2;
    */

    std::string s1,s2;
    std::cout<<"Entrer un mot : ";
    std::cin>>s1;
    std::cin.ignore();
    std::cout<<"Entrez une phrase : ";
    std::getline(std::cin,s2);
    if(position(s1,s2)==-1)
        std::cout<<"\""<<s1<<"\" n'est pas inclue dans \""<<s2<<"\"";
    else
        std::cout<<"\""<<s1<<"\" est inclue dans \""<<s2<<"\""<<" a la position : "<<position(s1,s2);
    return 0;
}
