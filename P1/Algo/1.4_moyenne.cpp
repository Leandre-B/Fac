#include <iostream>

int main()
{

    const float noteAnglais, noteMath, noteInfo;

    std::cout << "Note en anglais (coeff.2) : ";
    std::cin>>noteAnglais;

    std::cout << "Note en mathématiques (coeff.5) : ";
    std::cin>>noteMath;

    std::cout << "Note en informatique (coeff.3) : ";
    std::cin>>noteInfo;

    std::cout<<"Moyenne obtenue : " << (noteAnglais*2 + noteMath*5 + noteInfo*3)/10 << std::endl;
     return 0;
}
