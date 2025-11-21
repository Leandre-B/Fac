/*
**TD pas du tout fini
*/

#include <iostream>


struct Maillon{
    Maillon* suiv=nullptr;
    int e;
};

using File = Maillon*;

bool estVide(File & file){
    return file==nullptr;
}

void ajoute(File & file, int e){
    if(estVide(file)){
        file = new Maillon;
        file->e=e;
        file->suiv=file;
    }else{
        File aux=file->suiv;
        file->suiv = new Maillon;
        file->suiv->e=e;
        file->suiv->suiv=aux;
        file=file->suiv;
    }
}


void afficheRec(File & file, const File & q){
    if(file->suiv!=q){
        std::cout<<file->suiv->e<<"\n";
        afficheRec(file->suiv, q);
    }else
        std::cout<<file->suiv->e<<"\n";
}

void afficheIte(const File & file){
    if(file!=nullptr){
        File aux = file;
        do{
            aux = aux->suiv;
            std::cout<<aux->e<<"\n";
        }while(aux!=file);
    }
}

int longueurRec(File & file, const File & q){
    if(file==nullptr)
        return 0;
    else if(file->suiv!=q){
        return 1+ longueurRec(file->suiv, q);
    }else
        return 1;
}
int longueurIte(const File & file){
    File aux = file;
    int cpt;
    if(file==nullptr)
        cpt=0;
    else{
        cpt=1;
        while(file!=aux->suiv){
            ++cpt;
            aux=aux->suiv;
        }
    }
    return cpt;
}


int main(){
    File file = nullptr;
    ajoute(file,1);
    ajoute(file,2);
    ajoute(file,3);
    ajoute(file,5);
    ajoute(file,10);

    afficheRec(file, file);
    afficheIte(file);
    std::cout<<longueurIte(file)<<"\n";
    return 0;
}