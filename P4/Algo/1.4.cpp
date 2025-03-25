#include <iostream>

struct Monome{
    float a;
    float b;
};

struct Maillon{
    Monome m;
    Maillon* next;
};

using Polynome = Maillon*;

void saisieBis(Polynome & p, int n){
    if(n==0) p=nullptr;
    else
    {
        p=new Maillon;
        std::cin>>p->m.a;
        std::cin>>p->m.b;
        if(p->m.a==0)
            saisieBis(p,n-1);
        else
            saisieBis(p->next,n-1);
    }
}

void saisie(Polynome & p){
    int n;
    std::cout<<"Nombre de monomes : ";
    std::cin>>n;
    std::cout<<"Saisir le polynome (coeff puis degre de chaque monome) :";
    saisieBis(p,n);
}

void afficheMonome(Monome m){
    if(m.a!=0){
        if(m.b==0){
            if(m.a==1)
                std::cout<<"+1 ";
            else if(m.a>0)
                std::cout<<"+"<<m.a<<" ";
            else
                std::cout<<m.a<<" ";
        }else if(m.b==1){
            if(m.a>0)
                std::cout<<"+"<<m.a<<"X"<<" ";
            else
                std::cout<<m.a<<"X"<<" ";
        }else if(m.b<0){
            if(m.a==1)
                std::cout<<"+X"<<"1/"<<m.b<<" ";
            else if(m.a>0)
                std::cout<<"+"<<m.a<<"X"<<"1/"<<m.b<<" ";
            else
                std::cout<<m.a<<"X"<<"1/"<<m.b<<" ";
        }else if(m.b>0){
            if(m.a==1)
                std::cout<<"+X"<<m.b<<" ";
            else if(m.a>0)
                std::cout<<"+"<<m.a<<"X"<<m.b<<" ";
            else
                std::cout<<m.a<<"X"<<m.b<<" ";
        }
    }
    //std::cout<<std::endl<<"aff pas : "<<m.a<<" "<<m.b<<std::endl;
}

void affichePolynomeBis(Polynome p){
    if(p!=nullptr)
    {
        afficheMonome(p->m);
        affichePolynomeBis(p->next);
    }
}

void affichePolynome(Polynome p){
    std::cout<<"P(x)= ";
    if(p!=nullptr)
        affichePolynomeBis(p);
    std::cout<<std::endl;
}

void supprime(Polynome & p){
    if(p!=nullptr)
    {
        supprime(p->next);
        //std::cout<<"delete "<<p->m.a<<std::endl;
        delete(p);
        p=nullptr; //FAUT PAS L'OUBLIER !!!!!
    }
}

float degre(Polynome p){
    if(p==nullptr)
        return 0; //Nan mieux jpense
    else if(p->next==nullptr)
        return p->m.b;
    else
    {
        float max = degre(p->next);
        if(p->m.b>max)
            return p->m.b;
        else
            return max;
    }

}

float puiss(float x,float n){
    if(n==0) return 1;
    else if(n<0){
        return 1/puiss(x,-n);
    }
    else return x*puiss(x,n-1);
}

float valeurEn(Polynome p, float x){
    if(p==nullptr) return 0;
    else
        return p->m.a * puiss(x,p->m.b) + valeurEn(p->next,x);
}

Polynome derive(Polynome p){
    if(p==nullptr) return nullptr;
    else if(p->m.b==0) return derive(p->next);
    else{
        Polynome aux = new Maillon;
        aux->m.a = p->m.a * p->m.b;
        aux->m.b = p->m.b -1;
        aux->next = derive(p->next);
        return aux;
    }
}

void ajoutMonome(Polynome & p, Monome m){
    if(p==nullptr){
        p=new Maillon;
        p->m = m;
        p->next=nullptr;
    }else if(p->m.b == m.b)
        p->m.a+=m.a;
    else
        ajoutMonome(p->next,m);
}


Polynome somme(Polynome p1, Polynome p2){
    while(p2!=nullptr){
        ajoutMonome(p1,p2->m);
        p2=p2->next;
    }
    return p1;
}


int main(){
    Polynome p=nullptr;
    saisie(p);
    affichePolynome(p);
    /*
    std::cout<<"Degre : "<<degre(p)<<std::endl;
    
    float x=-1.5;
    std::cout<<"Valeur de X en : "<<x<<" = "<<valeurEn(p,x)<<std::endl;
    */
    Polynome p_deri = derive(p);
    std::cout<<"Derive : ";
    affichePolynome(p_deri);
    /*
    Polynome p_somme = somme(p,p_deri);
    std::cout<<"Somme des 2 polynomes : ";
    affichePolynome(p_somme);
    */
    Polynome p_produit = produit(p,p_deri);
    std::cout<<"Produit des 2 polynomes : ";
    affichePolynome(p_produit);
    
}

