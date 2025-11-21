
#include <array>
#include <ctime>
#include <cstdlib>
#include <iostream>

int const NBMAX=25;
using array=std::array<short int,NBMAX>;

void affTab(array tab){
    for(int i=0;i<NBMAX;++i){
        std::cout<<tab[i]<<" ";
    }
    std::cout<<std::endl<<std::endl;
}
//BUBBLE SORT
//le moins efficace mdr, deplace le plus grd nombre en fin de liste(plus grosses bulles remontent a la surface plus vite)
//https://fr.wikipedia.org/wiki/Tri_%C3%A0_bulles
void bubbleSort(array tab){
    int aux;
    int cptOpe=0;
    for(int i=0;i<=NBMAX;++i){
        ++cptOpe;
        for(int j=0;j<NBMAX-1-i;++j){
            ++cptOpe;
            if(tab[j]>tab[j+1]){
                ++cptOpe;
                aux=tab[j];++cptOpe;
                tab[j]=tab[j+1];++cptOpe;
                tab[j+1]=aux;++cptOpe;
            }
        }
    }
    affTab(tab);
    std::cout<<"Nombres d'operation : "<<cptOpe<<std::endl<<std::endl;
}
//SELECTION SORT
void selectionSort(array tab){
    int aux;
    int smaller;
    int j=0;
    int cptOpe=0;
    while(j<NBMAX){
        ++cptOpe;
        smaller=j;++cptOpe;
        for(int i=j+1;i<NBMAX;++i){
            ++cptOpe;
            if(tab[i]<tab[smaller]){
                ++cptOpe;
                smaller=i;++cptOpe;}
        }
        aux=tab[j];++cptOpe;;
        tab[j]=tab[smaller];++cptOpe;
        tab[smaller]=aux;++cptOpe;
        ++j;
    }
    affTab(tab);
    std::cout<<"Nombre d'operation : "<<cptOpe<<std::endl<<std::endl;
}
//INSERTION SORT (ce qu'on fait avec un jeu de carte)
//https://fr.wikipedia.org/wiki/Tri_par_insertion

void insertionSort(array tab){
    int aux;
    int valToCompare;
    int cptOpe=0;
    for(int valToVerif=1;valToVerif<NBMAX;++valToVerif)
    {
        ++cptOpe;
        aux=tab[valToVerif]; ++cptOpe;
        valToCompare=valToVerif-1;++cptOpe; //on commence a comparer la valeur juste a gauche de valToVerif
        while((aux<tab[valToCompare]) and valToCompare>=0) //faire attention à pas regarder les cases<0
        {++cptOpe;
            tab[valToCompare+1]=tab[valToCompare];++cptOpe;
            --valToCompare;++cptOpe;
        }
        tab[valToCompare+1]=aux;++cptOpe;
        // affTab(tab);
    }
    affTab(tab);
    std::cout<<"Nombre d'operation : "<<cptOpe<<std::endl<<std::endl;
}


//SHELL SORT
//insertion sort optimisé
//https://fr.wikipedia.org/wiki/Tri_de_Shell
//https://www.programiz.com/dsa/shell-sort
void shellSort(array tab){
    int aux;
    int valToCompare;
    int cptOpe=0;
    for(int interval=NBMAX/2;interval>=1;interval=interval/2)
    {++cptOpe;
        /*
         *           insertion sort sur les valeurs séparés par la variable inverval
         *           au dernier tour de boucle interval=1, insertion sort classique mais sur une liste déjà a peu près triée
         *           donc plus efficace
         */
        // for(int debut=0; debut < NBMAX-interval; ++debut) {
        for(int valToVerif=0;valToVerif<NBMAX;valToVerif+=interval)
        {   /*std::cout<<interval<<std::endl;*/
            ++cptOpe;
            aux=tab[valToVerif];++cptOpe;
            valToCompare=valToVerif-interval;++cptOpe;
            while((aux<tab[valToCompare]) and valToCompare>=0) //faire attention à ne pas regarder les cases<0
            {
                tab[valToCompare+interval]=tab[valToCompare];++cptOpe;
                valToCompare-=interval;++cptOpe;
            }
            tab[valToCompare+interval]=aux;++cptOpe;
            // affTab(tab);
        }
        // }
    }
    affTab(tab);
    std::cout<<"Nombre d'operation : "<<cptOpe<<std::endl<<std::endl;
}
/*
 * array quickSort(array tab){
 *
 * int pivot=tab[NBMAX-1];
 * int pivotSup,pivotInf;
 * int i,aux;
 *
 * for(int j=0;j<5;++j){
 *     pivotSup=-1;
 *     pivotInf=26;
 *     i=0;
 *     while((pivotSup!=-1 or pivotInf!=26) and i<NBMAX){
 *         if(tab[i]>tab[pivot] and pivotSup==-1)
 *             pivotSup=i;
 *         if(tab[i]<=tab[pivot] and pivotInf==26)
 *             pivotSup=i;
 *         ++i;
 *         }
 *         aux=tab[pivotInf];
 *         tab[pivotSup]=tab[pivotInf];
 *         tab[pivotInf]=aux;
 *
 *         affTab(tab);
 *         }
 *
 *
 *         affTab(tab);
 *         }
 */

/*BUCKET SORT
 * //j'ai compris le principe mais utilité/20 ??
 * void bucketSort (array tab){
 *     array bucketContainer;
 *
 *
 * }*/

/*
 * // MERGE SORT (tri fusion)
 *
 * void mergeSort(short int tab[]){
 *     Bon j'ai bien compris le principe je pense mais pour l'implémenter ???
 *     Trop compliqué avec les connaissances que j'ai j'pense
 *     Faut fonction récursive, autre type de tableau genre int var[]
 *     pointeurs aussi ??? J'pense y'a moyen de faire sans mais voilà
 *
 *
 * }
 */

int main(){

    std::srand(time(NULL));
    std::array<short int,NBMAX> tab;

    for(int i=0;i<NBMAX;++i){
        if((rand()%2)==2)
            tab[i]=-(rand()%100000);
        else
            tab[i]=rand()%100;
    }
    std::cout<<"Tab non triee"<<std::endl;
    affTab(tab);
    std::cout<<std::endl;

    std::cout<<"Bubble Sort"<<std::endl;
    bubbleSort(tab);
    std::cout<<std::endl;

    std::cout<<"Selection Sort"<<std::endl;
    selectionSort(tab);
    std::cout<<std::endl;

    std::cout<<"Insertion Sort"<<std::endl;
    insertionSort(tab);
    std::cout<<std::endl;

    std::cout<<"Shell Sort"<<std::endl;
    shellSort(tab);
    std::cout<<std::endl;

    // std::cout<<"Quick Sort"<<std::endl;
    // quickSort(tab);


}
