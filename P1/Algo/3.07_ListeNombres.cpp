#include <iostream>

int main(){

    for(int i=0;i<=9;++i){
        for(int j=0;j<=9;++j){
            for(int k=0;k<=9;++k){
                if(i+j+k==9)
                    std::cout<<i<<j<<k<<std::endl;
            }
        }
    }

    return 0;
}
