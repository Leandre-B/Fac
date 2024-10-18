#include <iostream>
#include <string>

int main(){

    std::string motMyst,motJeu;
    int essaie=1;
    char lettre;

    std::cout<<"Entrez un votre mot mystère:";
    std::cin>>motMyst;

    std::system("CLS"); //clear terminal windows
    //std::systeme("clear") // clear terminal Linus


    motJeu=motMyst; //initialise motJeu pour qu'il est la meme taille que motMyst
    for(unsigned int i=0;i<motMyst.length();++i){
        motJeu[i]='_';
    }

    /*
     * motJeu = std::string(motMyst.lenght(), '_'); //meme chose que ligne 17-20, penser que string=tableau de char
     */

    std::cout<<motJeu<<std::endl;

    //boucle tant que l'utilisateur n'a pas deviné le mot mystère
    while(motMyst!=motJeu){

        std::cout<<"Entrez une lettre:";
        std::cin>>lettre;

        for(unsigned int i = 0;i<motMyst.length();++i){
            if(motMyst[i]==lettre)
                motJeu[i]=motMyst[i];
        }
        std::cout<<"Après "<<essaie<<"essaies, voici le mot mystère: "<<motJeu<<std::endl<<std::endl;

        ++essaie;
    }

    std::cout<<"Bravo ! Vous avez découvert le mot mystère en " << essaie<< " essaies !"<<std::endl;

    return 0;
}
