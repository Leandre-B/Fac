#include <iostream>

int main(){

    for(int i=0;i<=9;++i){
        for(int j=0;j<=9;++j){
            for(int k=0;k<=9;++k){
                if(i+j+k==9 and i!=j and j!=k and k!=i){
                    //std::cout<<i<<j<<k<<std::endl;
                    std::cout<<i*100+j*10+k<<std::endl;
                }
            }
        }
    }

    return 0;
}
