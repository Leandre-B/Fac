#include <iostream>

struct Maillon{
    int val;
    Maillon * next;
};
using Liste = Maillon*;

void init(Liste & l){
    l=nullptr;
}

void aff(Liste l){
    if(l==nullptr) std::cout<<std::endl;
    else{
        std::cout<<l->val<<" ";
        aff(l->next);
    }
}

void ajouter_debut(Liste & l, int n){
    Liste p;
    p=new Maillon;
    p->val = n;
    p->next=l;
    l=p;
}

void ajouter_fin(Liste & l,int n){
    if(l==nullptr){
        l=new Maillon;
        l->val=n;
        l->next=nullptr;
    }else{
        ajouter_fin(l->next,n);
    }
}

void supprimer_debut(Liste & l){
    Liste p=l;
    l=l->next;
    delete p;
}

//A tester
void suppr_after_val(Liste & l, int val){
    if(l->val == val){
        Liste p =l;
        l=l->next;
        delete p;
    }else{
        suppr_after_val(l->next,val);
    }
}

int main(){
    Liste l;
    init(l);

    std::cout<<"Liste sans rien : ";
    aff(l);

    ajouter_debut(l,4);
    ajouter_debut(l,9);
    ajouter_debut(l,12);
    aff(l);

    std::cout<<"On ajouter a la fin : ";
    ajouter_fin(l,20);
    aff(l);

    std::cout<<"On suppr au début : ";
    supprimer_debut(l);
    aff(l);


}