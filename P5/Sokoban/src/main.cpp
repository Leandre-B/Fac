#include <iostream>

#include "graphique/menu.h"

int main()
{ 

    //ouvre la fenetre SFML du menu
    if(!ouvre_menu())
        std::cout<<"Erreur lors de l'ouverture du menu !"<<std::endl;

    return 0;
    
}
