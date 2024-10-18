#include <iostream>

int main(){

    float note, somme=0,min=20,max=0;
    int nbNote=0;

    do{
        std::cout<< "Entrez une note (saisir -1 pour arreter) : ";
        std::cin>>note;

        if((note>=0) and (note <= 20)){
            somme=somme+note;

            if(note>max){
                max=note;
            }

            if(note<min){
                min=note;
            }
            nbNote++;

        }  else
            std::cout<<"Valeur incorecte, veuillez reesayer!"<<std::endl;

    }while(note!=-1);

    std::cout<<"La moyenne est : " << (somme/nbNote)<<std::endl
            << "La note maximale est : " << max << std::endl
            << "La note minimal est : " << min<<std::endl;

    return 0;
}
