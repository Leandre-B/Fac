#include <iostream>
#include <array>
#include <stdlib.h>
#include <time.h>

const int NMAX = 10000;
using tab = std::array<int, NMAX>;

//function recursice min dans tab;
min(const tab & t, int n){
    int minim;
    if(n==1)
        return t[0];
    else{
        minim = min(t, n-1);
        if(minim>t[n-1])
            minim=t[n-1];
    }
    return minim;
}

void aff(tab t,int n){
    for(int i = 0;i<n;++i)
        std::cout<<t[i]<<" ";
    std::cout<<std::endl;
}

int c (int n){
    if(n==1) return 1;
    else return c(n-1)+2*(n-1)+1;
}


int main(){
    tab t;
    int n;
    std::cin>>n;
    // srand(time(NULL));
    // for(int i = 0; i<n;++i){
    //     t[i]=rand() % 100000 + 34;
    // }
    // // aff(t, n);
    // std::cout<<"Minimum : "<<min(t, n);
    std::cout<<c(n);


    return 0;
}
