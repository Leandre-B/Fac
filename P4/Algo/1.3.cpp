#include <iostream>
#include <cstdlib>
#include <chrono>

// ------------------ GESTION CHRONOS ET GRAINE -----------------------
auto chrono = std::chrono::system_clock::now();
void init_chrono ()
{
	chrono = std::chrono::system_clock::now();
}
float etat_chrono ()
{
	return (0.0 + std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - chrono).count()) / 1000;
}
unsigned random_seed ()
{
	return chrono.time_since_epoch().count();
}
// --------------------------------------------------------------------

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
    if(n>=2){
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
        if(l->n%multp == 0){
            Liste p=l;
            l=l->next;
            delete p;
            suprMultpl(l,multp);
        }else
            suprMultpl(l->next,multp);
    }
}

void crible(Liste & l){
    //aff(l);
    if(l!=nullptr){
        suprMultpl(l->next,l->n);
        crible(l->next);
    }
}


int main(){
    Liste liste;
    int n;
    std::cout<<"Entrer les n 1eres a vérifier : ";
    std::cin>>n;

    init(liste);
    remplir(liste,n);

    init_chrono();
    //crible(liste);
    std::cout<<"Temps crible : " <<etat_chrono()<<"s"<<std::endl;

}