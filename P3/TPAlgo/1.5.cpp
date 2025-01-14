#include <iostream>

void bjr(int n){
    if(n>0){
        std::cout<<"Bonjour"<<std::endl;
        bjr(n-1);
    }
}

int sommeCarre(int n){
   if(n==1) return n;
   else return (n*n + sommeCarre(n-1));
}

int main(){
    int n;
    std::cout<<"Combier de fois voulez-vous afficher \"Bonjour\" ? ";
    std::cin>>n;
    bjr(n);

    std::cout<<"somme des "<<n<<" premiers carrés : "<<sommeCarre(n)<<std::endl;

    return 0;
}
