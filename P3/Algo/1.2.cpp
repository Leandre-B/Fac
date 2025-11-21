#include <iostream>


int test( int n){

    if(n==0) return 1;
    else{
        --n;
        return ((n+1)*test(n));
    }
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<test(n)<<std::endl;

    return 0;
}
