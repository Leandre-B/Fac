#include <iostream>
#include <array>

const int N=4;

int main(){

    float ref;
    using tab=std::array<float, N>;
    tab listeNombre;

    std::cout<<"Entrez "<<N<<" nombres réels"<<std::endl;
    for (int i = 0;i<N;++i){
        std::cout<<"Nombre "<<i<<" : ";
        std::cin>>listeNombre[i];
        std::cout<<std::endl;
    }

    std::cout<<"Entrez un nombres de référence : ";
    std::cin>>ref;

    int plus_proche=0;

    for (int i = 1;i<N;++i){
        if(std::abs(ref-listeNombre[i]) <= std::abs(ref-listeNombre[plus_proche])){
                plus_proche = (i);
        }
    }
    std::cout<<"Le nombre de votre liste le plus proche de votre nombre de référence est : "<<listeNombre[plus_proche]<<std::endl;

    return 0;
}
