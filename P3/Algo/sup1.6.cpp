#include <iostream>

/*
 * AHAHAHALCEST TROOOP NUL
 * TU FAIS DE LA RECUSIVITE TU SAIS MEME PAS COMMENT CA FONCTIONNE A 100%
 * TU COMMENCES A ESSAYER D'AVOIR UNE VISION PARFAITE DU TRUC AVANT DE COMMENCER
 * MAIS TU TE CASSES LA TETE HORRIIIIIIIBLE
 * POUR AU FINAL AVOIR JUSTE UNE VAGUE IDEE ET FAIRE GENRE
 * "ouaaais ça doit etre vite fait un truc comme ça..."
 * ET CA MARCHE ! C'EST N'IMPORTE QUOI
 * TU COMPRENDS AU GRAND MAX 60% DE CE QUE TA FONCTION FAIT
 * MAIS OSEEEEF CA FONCTIONNE :) :) :) :) :)
*/



void hanoi(int n, char t1, char t2, char t3){
    if(n>0){
        hanoi(n-1,t1,t3,t2); //foutre la partie n-1 sur celle du milleu
        std::cout<<t1<<"->"<<t3<<std::endl;//foutre la piece en dessous a la bonne place
        hanoi(n-1,t2,t1,t3);
    }
}

int main(){

    int nDisque;
    char t1= 'A', t2='B', t3='C';

    std::cout<<"Avec combien de disque voulez-vous jouer ? : ";
    std::cin>>nDisque;
    hanoi(nDisque, t1,t2,t3);


    return 0;
}
