#include <iostream>

int main(){

    char inputChar,mostChar;
    char carTemp='\0'; //char avec un code nunmerique=0 -> char "vide"
    int consecutifChar=1,mostConsecutifChar=1;

    for(int i=0;i<21;++i){

        std::cout<<"Entre un caratere : ";
        std::cin>>inputChar;

        if(inputChar==carTemp){
            ++consecutifChar; //compte le nombre de char consécutif

            // si le nombre de char consecutif est le plus grand
            // on stocke le char en question et le nombre de fois qu'il apparait
            if(consecutifChar>=mostConsecutifChar){
                mostConsecutifChar=consecutifChar;
                mostChar=inputChar;
            }
        }
        else
            consecutifChar=1;
        carTemp=inputChar;

    }

    std::cout<<"Le caractere qui apparait le plus de fois consecutivement et le \""<<mostChar<<"\" ("<<mostConsecutifChar<<" fois)"<<std::endl;

    return 0;
}
