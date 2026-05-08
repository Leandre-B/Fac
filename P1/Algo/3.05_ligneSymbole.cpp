#include <iostream>

int main(){

    int n;
    std::cout << "Combien de lignes ? ";
    std::cin>>n;

    // for(int i=1;i<=n;i++){
    //     if(i%2==1)
    //         std::cout << "*";
    //     else
    //         std::cout<<"!";
    // }

    bool toggle = true;
    for(int i=1;i<=n;i++){

        // condition ternaire
        toggle ? std::cout << "*" : std::cout << "!";

        //équivalent
        // if(toggle)
        //     std::cout << "*";
        // else
        //     std::cout<<"!";
        
        toggle = !toggle;
    }

    return 0;
}
