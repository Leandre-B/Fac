#include <iostream>

int main()
{

    int v1, v2, v3,v4, vAux;

    std::cout << "Entrer 4 valeurs : ";
    std::cin >> v1 >> v2 >>v3>>v4;
    vAux = v1;
    v1=v2;
    v2=v3;
    v3=v4;
    v4=vAux;

    std::cout << "v1 = " << v1 << std::endl <<
                " v2 = " << v2 << std::endl <<
                " v3= " << v3 << std::endl <<
                " v4 = " << v4 << std::endl;

    return 0;
}
