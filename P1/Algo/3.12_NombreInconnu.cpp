#include <iostream>
#include<cstdlib>
#include<ctime>

int main(){

    /*
    int randomInt,nb,essai=0;

    std::cout<<"J'ai généré un nombre aléatoire entre 1 et 100, a toi de le retrouver !!!!"<< std::endl;
    srand=time(NULL);
    randomInt = rand() % 100 +1;

    do{
        ++essaie;
        std::cout << "Essaie num " << essai << std::endl;
        std::cin>>nb;
        if(nb<randomInt)
            std::cout<<"Trop petit ! "<<std::endl;
        if(nb>randomInt)
            std::cout<<"Trop grand ! "<<std::endl;
    }while(nb!=randomInt);

    std::cout<<"Bravo ! Tu l'as trouve en " << essai << " esssaie(s)";
    */

    char pm;
    int max=100,min=0,nb;
    srand(time(NULL));
    std::cout<<"Pensez à un nombre a faire deviner (entre 1 et 100) à l'ordinateur : \n";
    do{
        nb = (max-min)/2 + min;  
        std::cout<<"Ordi : Je pense au "<<nb<<std::endl
                 <<"Plus (P) ou Moins (M) ('O' si bon) ? "<<nb<<std::endl;
        std::cin>>pm;

        if(pm=='M')
            max = nb;
        if(pm=='P')
            min = nb;
    }while(pm != 'O');

    std::cout<<"Ordi : Youhou j'ai trouvé, c'était le "<<nb<<"\n";


    return 0;
}
