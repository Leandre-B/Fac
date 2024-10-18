#include <iostream>
#include <string>

int main(){

    std::string phrase;
    unsigned int i=0;
    bool palindrome=true;

    std::cout <<"Entrez votre mot/phrase : ";
    std::getline(std::cin, phrase);

    while (palindrome and i<phrase.length()/2){

        if(phrase[i]!=phrase[phrase.length()-1-i])
            palindrome=false;
        ++i;
    }

    if(palindrome)
        std::cout<<"\""<<phrase<<"\""<<" est un palindrome ! "<<std::endl;
    else
        std::cout<<"\""<<phrase<<"\""<<" n'est pas un palindrome ! "<<std::endl;

    return 0;
}
