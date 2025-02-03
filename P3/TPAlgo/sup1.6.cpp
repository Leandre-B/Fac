#include <iostream>


void hanoi(int n, char t1, char t2, char t3){
    if(n>2)
        hanoi(n-1,t1,t2,t3);
    std::cout<<t1<<"-->"<<t3<<std::endl;
    std::cout<<t1<<"-->"<<t2<<std::endl;
    std::cout<<t3<<"-->"<<t2<<std::endl;
    if(n==2){
        std::cout<<t1<<"-->"<<t3<<std::endl;
    }
    hanoi(n,t3,t2,t1);



}


int main(){

    int nDisque;
    char t1= 'A', t2='B', t3='C';

    std::cout<<"Avec combien de disque voulez-vous jouer ? : ";
    std::cin>>nDisque;
    hanoi(nDisque, t1,t2,t3);


    return 0;
}
