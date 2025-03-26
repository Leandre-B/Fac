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
        //si a=0 faut le supprimer
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
//
//Polynome produitPoly_Mono(Polynome p, Monome m){
//    Polynome temp=p;
//    while(p!=nullptr){
//        p->m.a *= m.a;
//        p->m.b+=m.b;
//        p=p->next;
//    }
//    //affichePolynome(temp);
//    return temp;
//}
//

Polynome produit(Polynome p1, Polynome p2){
    Polynome p=nullptr;
    
    Polynome copie_p2 = nullptr;
    copie_p2=somme(copie_p2,p2);
    
    while(p1!=nullptr){
        p2=copie_p2; //bien copié
        while(p2!=nullptr){
            Polynome temp_p=new Maillon;
            temp_p->m.a=p1->m.a * p2->m.a;
            temp_p->m.b=p1->m.b + p2->m.b;
            temp_p->next=nullptr;
            
            p=somme(p,temp_p);
            p2=p2->next;
        }
        std::cout<<"etape p produit"<<std::endl;
        affichePolynome(p);
        p1=p1->next;
    }
    return p;
}


void ordonne(Polynome &p){
    //basé sur tri a bulles (pas trop le choix vu que c'est des listes je pense)

    //polynome fixe, 
    Polynome p_fixe = nullptr;
    p_fixe = somme(p_fixe,p);

    Polynome p_temp = nullptr;
    p_temp = somme(p_temp,p);
    
    while(p_temp!=nullptr)
    {
        while(p->next!=nullptr)
        {
            if(p->m.b < p->next->m.b)
            {
                //maillon temp
                Monome m;
                m.a = p->m.a;
                m.b = p->m.b;

                //echange
                p->m.a = p->next->m.a;
                p->m.b = p->next->m.b;

                p->next->m.a=m.a;
                p->next->m.b=m.b;

            }
            p=p->next;
        }
        p=p_fixe;
        p_temp=p_temp->next;
    }
}
        
        
        

int main(){
    //exemple poly saisie : 3 2 1 5 7 0 -6 4
    
    Polynome p=nullptr;
    saisie(p);
    affichePolynome(p);
    ///*
    //std::cout<<"Degre : "<<degre(p)<<std::endl;
    //
    //float x=-1.5;
    //std::cout<<"Valeur de X en : "<<x<<" = "<<valeurEn(p,x)<<std::endl;
    //*/
    //Polynome p_deri = derive(p);
    //std::cout<<"Derive : ";
    //affichePolynome(p_deri);
    ///*
    //Polynome p_somme = somme(p,p_deri);
    //std::cout<<"Somme des 2 polynomes : ";
    //affichePolynome(p_somme);
    //*/
    //
    //Polynome p_produit = produit(p,p_deri);
    //std::cout<<"Produit des 2 polynomes : ";
    //affichePolynome(p_produit);

    std::cout<<"p ordonne par degres : "<<std::endl;
    ordonne(p);
    affichePolynome(p);
}

