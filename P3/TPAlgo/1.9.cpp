#include <iostream>
#include <string>

std::string extraire(std::string chaine, int indice, int longueur){
    if(longueur==0)
        return "";
    else
        return extraire(chaine, indice, longueur-1)+chaine[indice+longueur];
}

bool estPalindrome(std::string chaine, int g, int d){
    if(chaine[g]!=chaine[d]) return false;
    else if(d>g) return true;
    else return estPalindrome(chaine,g+1, d-1);

}

int occurence(std::string chaine, char lettre,unsigned int n){
    if(n==chaine.length()) return 0;
    else if(chaine[n]==lettre) return 1+occurence(chaine, lettre, n+1);
    else return occurence(chaine, lettre, n+1);
}

int main(){

    /* 1
    std::string chaine;
    int indice,longueur;

    std::cout<<"Entrer un chaine de char : ";
    std::cin>>chaine;

    std::cout<<"Entrer a partir de quel char vous voulez couper la chaine : ";
    std::cin>>indice;

    std::cout<<"Entrer la longueur de la chaine que vous voulez extraire : ";
    std::cin>>longueur;

    std::cout<<"Chaine extraite : \""<<extraire(chaine, indice, longueur)<<"\""<<std::endl;

    std::cout<<"Entrer une chaine (test palindrome) : ";
    std::cin>>chaine;
    */

    /* 2
    std::string chaine;
    if(estPalindrome(chaine, 0,chaine.length()-1))
        std::cout<<"\""<<chaine<<"\" est un palindrome !!!"<<std::endl;
    else
        std::cout<<"\""<<chaine<<"\" n'est pas un palindrome !!!"<<std::endl;
    */

    std::string chaine;
    char lettre;

    std::cout<<"Entrer un ch de char (occu) : ";
    std::cin>>chaine;

    std::cout<<"Entrer la lettre a chercher : ";
    std::cin>>lettre;

    std::cout<<"Il y'a "<<occurence(chaine, lettre,0)<<" \'"<<lettre<<"\' dans "<<chaine<<std::endl;




    return 0;
}
