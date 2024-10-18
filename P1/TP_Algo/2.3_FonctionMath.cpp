#include <iostream>

int main()
{
    float x;
    std::cout << "Programme pour calculer f(x) en fontion de x";
    std::cout << "Saissiez x : ";
    std::cin >> x;
    if((((2/3)*x*x)-6)==0.0)
        std::cout << "ERREUR :  f(x) n'est pas definie pour x= " << x;
    else{
        if(x<0){
            std::cout << "f(x)= " << (-x + 3 *x*x)/((2/3)*x*x-6) << std::endl;
        }else{
            std::cout << "f(x)= " << (x + 3 *x*x)/((2/3)*x*x-6) << std::endl;
        }
    }

    return 0;
    }
