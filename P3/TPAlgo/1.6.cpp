#include <iostream>


int diviseur(int n, int d){
    if(n%(d+1)==0) return d+1;
    else return (diviseur(n, d+1));
}

bool est_premier(int n){
    if(diviseur(n,1)==n) return true;
    else return false;
}

void affiche_premier(int n){
    if(n>2){ //boucle dans fonction diviseur() si n==2
        --n;
        if(est_premier(n))
            std::cout<<n<<std::endl;
        affiche_premier(n);
    }
}

int main(){
    int n;
    std::cout<<"Entrer un nombre positif : ";
    std::cin>>n;

    affiche_premier(n);

}
