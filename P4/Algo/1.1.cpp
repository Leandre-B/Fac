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


void supr_val(Liste & l, int val){
    if (l==nullptr) return;
    else if(l->val == val){
        Liste p =l;
        l=l->next;
        delete p;
    }else
         supr_val(l->next,val);
}

void affIte(Liste l){
    while(l!=nullptr){
        std::cout<<l->val<<" ";
        l=l->next;
    }
    std::cout<<std::endl;
}

void ajouter_fin_ite(Liste & l,int n){
    if(l==nullptr){
        l=new Maillon;
        l->val=n;
        l->next=nullptr;
    }else{
        Liste aux_l=l;
        while(aux_l->next!=nullptr)
            aux_l=aux_l->next;
        aux_l->next=new Maillon;
        aux_l->next->val=n;
        aux_l->next->next = nullptr;
    }
}

void liste_to_tab(Liste l, int* & t, int n,int & taille){
    if(l!=nullptr){
        if(l->next==nullptr){
            t=new int[n+1];
            t[n]=l->val;
            taille=n+1;
        }else{
            liste_to_tab(l->next,t,n+1,taille);
            t[n]=l->val;
        }
    }
}


//meme plus simple en iteratif,
//ou plutot plus cohérent vu qu'on
//utilise des tableaux
void tab_to_liste(Liste & l, int* tab,int n){
    if(n>0){
        ajouter_debut(l,tab[n-1]);
        tab_to_liste(l,tab,n-1);
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

    int n =5;
    std::cout<<"On suppr : "<<n<<std::endl;
    supr_val(l,n);
    affIte(l);

    ajouter_fin_ite(l,42);
    affIte(l);
    
    int* tab=nullptr;
    int taille;
    liste_to_tab(l,tab,0,taille);

    std::cout<<taille<<std::endl;

    for(int i =0;i<taille;++i){
        std::cout<<tab[i]<<" ";
    }
    std::cout<<std::endl;

    Liste l2;
    init(l2);
    tab_to_liste(l2,tab,taille);
    aff(l2);

    return 0;
}