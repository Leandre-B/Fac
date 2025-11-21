#include <iostream>

float puiss(float x, int n){
    if(n==1) return x;
    else{
        if(n%2==1)
            return (puiss(x*x,n/2)*x);
        else
            return (puiss(x*x,n/2));
    }
}

int main(){
    int n;
    float x;
    std::cout<<"Entrer le nb a mettre a la puissance : ";
    std::cin >>x;
    std::cout<<"Entrez la puissance : ";
    std::cin>>n;

    std::cout<<x<<"^"<<n<<" = " <<puiss(x,n);

    return 0;
}
