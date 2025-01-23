#include <iostream>

int fibo(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return(fibo(n-1)+fibo(n-2));
}


int main(){
    int n;
    std::cout<<"Entrez le n de la suite de fibo  a calculer : ";
    std::cin>>n;
    std::cout<<"Fibo a n ="<<n<<" est : "<<fibo(n)<<std::endl;
}
