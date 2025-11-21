#include <iostream>
#include <array>

using tab = std::array<float, 100>;

void aff(tab T, int n){
    for (int i=0;i<n;++i)
        std::cout<<T[i]<<" ";
    std::cout<<std::endl;
}

void remplir (tab & T, int & n){
    n=0;
    std::cout<<"Combien de valeurs voulez-vous rentrez ? ";
    std::cin>>n;
    std::cout<<"Entrez les valeurs : ";
    for(int i = 0; i <n;++i)
        std::cin>>T[i];
}

int occurence(tab T, int n, float nb){
    int occu=0;
    for(int i=0; i<n;++i){
        if(T[i]==nb){
            ++occu;
        }
    }
    return occu;
}
/* pas ouf car on parcours tout le tab meme si on trouve l'element
bool appartient(tab T, int n, float nb){
    return (occurence(T, n, nb)>0);
}*/

//mieux car stop dès qu'on trouve l'element
bool appartient(tab T, int n,float nb){
    for(int i=0; i<n;++i){
        if(T[i]==nb){
            return true;
        }
    }
    return false;
}
 // Encore pas opti car stop pas dès qu'on sait que la tab ne code pas un ensemble
bool ensemble(tab T, int n){
    for(int i = 0;i<n;++i){
        if(occurence(T, n, T[i])>1)
            return false;
    }
    return true;
}

/*TODO opti fct ensemble
ensemble(tab T, int n){

}*/

//possible de faire sans 2eme tab
void devient_ensemble(tab t1, int n1, tab & t2, int & n2){
    for(int i = 0;i<n1;++i){
        if(!(appartient(t2,n2,t1[i]))){
            ++n2;
            t2[n2-1]=t1[i];
        }
    }
}

void devient_ensemble2(tab & t, int & n){
    int i = 1;
    while(i<n){
        if(appartient(t,i,t[i])){
            t[i]=t[n-1];
            --n;
        }
        else
            ++i;
    }
}

//conserve l'ordre des element
void devient_ensemble3(tab & t, int & n){
    int i=1;
    int j=1;
    while(i<n){
        t[j]=t[i];
        if(!(appartient(t,j,t[i])))
            ++j;
    }
    n = j;
}

//NAZE double for pas opti du tout...
void inter_ens(tab t1, tab t2, tab & t3,int n1,int n2,int & n3){
    n3=0;
    for(int i=0;i<n1;++i){
        for(int j = 0;j<n2;++j){
            if(t1[i]==t2[j] /* and !(appartient(t3,n3,t1[i]))*/){
                t3[n3]=t1[i];
                ++n3;
            }
        }
    }
}

void inter_ens2(tab t1, tab t2, tab & t3,int n1,int n2,int & n3){
    n3=0;
    for(int i = 0;i<n1;++i){
        if(appartient(t2,n2,t1[i])){
            t3[n3]=t1[i];
            ++n3;
        }
    }
}

/* pas opti
void union_ens(tab t1, tab t2, tab & t3, int n1, int n2, int & n3){
    n3=0;
    tab t12;
    int n12 = n1+n2;
    // std::cout<<"n12 = "<<n12<<std::endl;
    for(int i = 0;i<n1;++i)
        t12[i]=t1[i];

    for(int i = 0;i<n2;++i)
        t12[n1+i]=t2[i];

    // std::cout<<"T12 : ";
    // aff(t12,n12);
    devient_ensemble(t12,n12,t3,n3);
    n2 = n12;
}*/

void union_ens2(tab t1, tab t2, tab & t3, int n1, int n2, int & n3){
    n3=n1;
    for(int i = 0;i<n1;++i)
        t3[i]=t1[i];
    for(int i = 0;i<n2;++i){
        if(!appartient(t3,n3,t2[i])){
            ++n3;
            t3[n3-1]=t2[i];
        }
    }
}

int main(){

    tab t1,t2,tI,tU;
    int n1,n2,nI,nU;

    std::cout<<std::endl<<"---- Entrez les val du 1er ensemble : ----"<<std::endl;
    do{
        remplir(t1,n1);
        if(!ensemble(t1,n1))
            std::cout<<"Ce n'est pas un ensemble, veuillez re-entrer les valeurs : "<<std::endl;
    }while(!ensemble(t1,n1));

    std::cout<<std::endl<<"---- Entrez les val du 2eme ensemble : ----"<<std::endl;
    do{
        remplir(t2,n2);
        if(!ensemble(t2,n2))
            std::cout<<"Ce n'est pas un ensemble, veuillez re-entrer les valeurs : "<<std::endl;
    }while(!ensemble(t2,n2));

    inter_ens2(t1,t2,tI,n1,n2,nI);
    std::cout<<std::endl<<"Voici l'intersection de ces deux ensembles : "<<std::endl;
    aff(tI,nI);
    std::cout<<std::endl<<"Voici l'union de ces deux ensembles : "<<std::endl;
    union_ens2(t1,t2,tU,n1,n2,nU);
    aff(tU,nU);


/*
    tab t1, t2;
    int n1, n2;
    remplir(t1,n1);
    devient_ensemble2(t1,n1);
    aff(t1,n1);*/


/*
    tab T;
    int n;
    float nb;
    remplir(T, n);
    aff(T, n);
    std::cout<<"Entrer le nombre à rechercher dans le tableau : ";
    std::cin>>nb;
    std::cout<<"Le nombre "<<nb<<" apparait "<<occurence(T, n,nb)<<" fois dans le tableau"<<std::endl;

    std::cout<<"Entrer le nombre à rechercher dans le tableau : ";
    std::cin>>nb;
    if(appartient(T, n, nb))
        std::cout<<"Le nombre "<<nb<<" appartient au tableau"<<std::endl;
    else
        std::cout<<"Le nombre "<<nb<<" n'appartient pas au tableau"<<std::endl;

    if(ensemble(T,n))
        std::cout<<"Le tableau code un ensemble !";
    else
        std::cout<<"Le tableau ne code pas un ensemble :(";*/

}
