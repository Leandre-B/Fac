#include <iostream>
#include <string>


void trier(std::string &ch){
    char c;
    c=ch[0];
    for (int i = 0;i<ch.length:++i){
        if(ch[i]<c){

        }
    }
}

int main(){

    std::string ch1,ch2;

    std::cout<<"Entrez un 1er mot : ";
    std::cin>>ch1;
    std::cout<<"Entrez un 2eme mot : ";
    std::cin>>ch2;

    /*
    if(ch1.length()==ch2.length())
    {
        for(unsigned int i = 0;i<ch1.length();++i)
        {
            for(unsigned int j = 0;j<ch2.length();++j)
            {
                if(ch1[i]==ch2[j])
                    ch2.erase(j,1); //supprime 1 élément de ch2 a partir de la case mémoire j (j compris)
            }
        }
        if(ch2.length()==0)
            std::cout<<"Ces mots sont palindrome"<<std::endl;
        else
            std::cout<<"Ces mots ne sont pas palindrome"<<std::endl;
    }else
        std::cout<<"Ces mots ne sont pas palindrome"<<std::endl;

    */


        if(ch2.length()==0)
            std::cout<<"Ces mots sont palindrome"<<std::endl;
        else
            std::cout<<"Ces mots ne sont pas palindrome"<<std::endl;


    return 0;
}
