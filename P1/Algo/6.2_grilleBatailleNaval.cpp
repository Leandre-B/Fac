#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

const int TAILLE=10;

//affiche la grille de bataille navalse
void affGrile(std::array<std::array<int, TAILLE>,TAILLE> &gameBoard){
    for (int i =0;i<TAILLE;++i){
        for (int j =0;j<TAILLE;++j){
            std::cout<<gameBoard[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

//vérifie si deux bateaux se chevauche
bool chevauchement(std::array<std::array<int, TAILLE>,TAILLE> &gameBoard,int debutBateauVert,int debutBateauHor, int longBateau,int orientationBateau)
{
    bool chevauche;
    int j=0;
    if(orientationBateau==0){
        while(j<longBateau and !chevauche){
            if(gameBoard[debutBateauVert+j][debutBateauHor]!=0)
                chevauche= true;
            else
                chevauche=false;
            ++j;
        }
    }else{
        j=0;
        while(j<longBateau and !chevauche){
            if(gameBoard[debutBateauVert][debutBateauHor+j]!=0)
                chevauche= true;
            else
                chevauche=false;
            ++j;
        }
    }
    return chevauche;
}


int main(){
    using TLigne=std::array<int,TAILLE>;
    using tab =std::array<TLigne,TAILLE>;
    tab gameBoard;

    int nbBateaux;
    int longBateau;
    short unsigned int orientationBateau; //ne prendra que 2 valeur 0(=vertical) ou 1(=horizontal)
    int debutBateauVert,debutBateauHor;
    int cpt;
    std::srand(time(NULL));

    //rempli la grille de 0
    for (int i =0;i<TAILLE;++i){
        for (int j =0;j<TAILLE;++j){
            gameBoard[i][j]=0;
        }
    }

    std::cout<<"Nombre de bateaux : ";
    std::cin>>nbBateaux;

    int i=1;
    while(i<=nbBateaux)
    {
        //vérifie que la longueur entrée d'un bateau est valide
        do
        {
            std::cout << "Longueur du bateu no."<<i<<" : ";
            std::cin>>longBateau;

            if (!(longBateau<10 and longBateau>0))
                std::cout<<"Valeur incorrecte"<<std::endl;

        }while(!(longBateau<10 and longBateau>0));

        cpt=0;
        do{ //cherche un emplacement valide pour un bateau (50 fois maximum)
            orientationBateau=(std::rand() % 2); //génére random nbr [0;1]
            if (orientationBateau==0){//bateau vertical
                debutBateauVert=(std::rand()%(10-longBateau));//génére random nbr [0;9-longBateau[ pour ne pas sortir de la grille
                debutBateauHor=(std::rand()%(10));
            }else{//bateau horizontal
                debutBateauVert=(std::rand()%(10));
                debutBateauHor=(std::rand()%(10-longBateau));
            }
            ++cpt;
        }while(chevauchement(gameBoard,debutBateauVert,debutBateauHor ,longBateau ,orientationBateau)and cpt<50);

        if(cpt==50){ //si au bout de 50 essaies aucun emplacement valide n'a été trouvé, on redemande un taille(on revien ligne 60 sans incrémenter i)
            std::cout<<"Entrées non valides, veuillez recommencer (pas assez de place pour le bateau)"<<std::endl;
        }
        else{//sinon on affiche le bateau selon son orientation (0=verticalement, 1=horizontalement)
            if(orientationBateau==0)
            {
                for (int j =0;j<longBateau;++j)
                {

                    gameBoard[debutBateauVert+j][debutBateauHor]=i;
                }
            }else{
                for (int j =0;j<longBateau;++j){
                    gameBoard[debutBateauVert][debutBateauHor+ j]=i;
                }
            }
            ++i;
        }
        affGrile(gameBoard);
    }

    std::cout<<"Voici votre grille de bataille navale"<<std::endl;
    affGrile(gameBoard);



    return 0;
}
