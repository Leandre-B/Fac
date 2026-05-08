#include <iostream>
#include <string>


void trier(std::string &ch){
    for (unsigned int i = 0;i<ch.length()-1;++i){
        for (unsigned int j = i;j<ch.length();++j){
            if(ch[i]<ch[j]){
                char c = ch[i];
                ch[i] = ch[j];
                ch[j] = c;
            }
        }
    }
}

int main(){

    std::string ch1,ch2;

    std::cout<<"Entrez un 1er mot : ";
    std::cin>>ch1;
    std::cout<<"Entrez un 2eme mot : ";
    std::cin>>ch2;

    bool palindromes = true;
    if(ch1.length() != ch2.length()){
        palindromes = false;

        
    }else{
        trier(ch1);
        trier(ch2);
        palindromes = ch1 == ch2;
    }
    
    if(palindromes){
        std::cout<<"Les mots sont des palindromes !\n";
    }else{
        std::cout<<"Les mots ne sont pas des palindromes !\n";
    }

    return 0;
}
