#include <iostream>

int main(){

    int n;
    std::cout << "Combien de lignes ? ";
    std::cin>>n;

    for(int i=1;i<=n;i++){
        if(i%2==1)
            std::cout << "*";
        else
            std::cout<<"!";
    }

    return 0;
}
