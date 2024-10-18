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

    int pm,max=100,min=0,nb;
    srand(time(NULL));
    std::cout<<"Quel nombre a faire deviner : ";
    do{
        nb=(std::rand()%(max - min)+min);
        std::cout<<"Je pense au "<<nb<<std::endl;
        std::cin>>pm;

        if(pm==0)
            max=nb;
        if(pm==1)
            min = nb;
    }while(pm!=-1);

    std::cout<<"Youhou j'ai trouvé, c'était le "<<nb;


    return 0;
}
