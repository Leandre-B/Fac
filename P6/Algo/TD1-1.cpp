#include <iostream>

using element = int;
struct Maillon{
    element e;
    Maillon* suiv;
};

using Liste = Maillon*;

void affiche(Liste l){
    if(l!=nullptr){
        std::cout<<l->e<<" ";
        affiche(l->suiv);
    }
}
void ajoutDebut(Liste & l, element e){
    Maillon* m = new Maillon;
    m->e=e;
    m->suiv=l;
    l=m;
}

void ajout(Liste & l, element e){
    if(l==nullptr)
        ajoutDebut(l,e);
    else{
        if(l->e>e)
            ajoutDebut(l,e);
        else
            ajout(l->suiv,e);
    }
}

//Pas de delete ??? 
void supprime(Liste & l, element e){
    if(l!=nullptr){
        if(l->e==e){
            l=l->suiv;
            supprime(l,e);
        }else
            supprime(l->suiv, e);
    }
}

//nul pas de delete + l=l->suiv->suiv
void corrige(Liste & l){
    if(l->suiv!=nullptr){
        if(l->suiv->e < l->e){
            l=l->suiv;
            corrige(l);
        }else
            corrige(l->suiv);
    }
}

void fusionne(Liste & l1, Liste l2){
    if(l2!=nullptr){
        if(l1==nullptr)
            l1=l2;
        else{
            if(l2->e < l1->e){
                ajoutDebut(l1, l2->e);
                fusionne(l1, l2->suiv);
            }else
                fusionne(l1->suiv, l2);
        }
    }
}

int main(){
    Liste l;
    l=nullptr;
    ajoutDebut(l,10);
    ajoutDebut(l,8);
    ajoutDebut(l,6);
    ajoutDebut(l,2);
    ajoutDebut(l,0);

    Liste l2;
    l2=nullptr;
    ajoutDebut(l2,14);
    ajoutDebut(l2,9);
    ajoutDebut(l2,7);
    ajoutDebut(l2,6);
    ajoutDebut(l2,3);
    ajoutDebut(l2,-2);


    affiche(l2);
    std::cout<<"\n";

    affiche(l);
    std::cout<<"\n";

    fusionne(l,l2);
    affiche(l);
    std::cout<<"\n";



    return 0;
}