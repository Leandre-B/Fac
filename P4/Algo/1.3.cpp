#include <iostream>

struct Maillon{
    int n;
    bool premier;
    Maillon* next;
};

using Liste = Maillon*;

void init(Liste & l){
    l=nullptr;
}

void aff(Liste l){
    if(l==nullptr)
        std::cout<<std::endl;
    else{
        std::cout<<l->n<<" ";
        aff(l->next);
    }
}

void remplir(Liste & l, int n){
    if(n>=0){
        Liste p;
        p=new Maillon;
        p->n=n;
        p->next=l;
        p->premier=true;
        l=p;
        remplir(l,n-1);
    }
}
/*
void initTab(bool* & t,int n){
    if(n>=0){
        t[n-1]=true;
        initTab(t,n-1);
    }
}
*/

void suprMultpl(Liste & l , int multp){
    if(l!=nullptr){
        
    }
}

void crible(Liste l){
    /*
    bool* tab;
    tab=new bool [n];
    initTab(tab,n);
    tab[0] = false;
    tab[1] = false;
    for(int i =2;i<n;++i){
        if(tab[i]==true)
            for(int j =i+i;j<n;j+=i)
                tab[j]=false;
    }
    */

    for(int i =0;i<n;++i){
        if(tab[i]==true)
            ajouterTete(l,i);
    }
    
}

int main(){
    Liste liste;
    int n;
    std::cout<<"Entrer les n 1eres a vérifier : ";
    std::cin>>n;

    init(liste);

    remplir(liste,n);
    aff(liste);

    crible(liste,n);


}