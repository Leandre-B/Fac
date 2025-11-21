#include <iostream>
#include <array>

const int N=4;

int main(){

    float proche,ref;
    using tab=std::array<float, N>;
    tab listeNombre;

    std::cout<<"Entrez "<<N<<" nombres réels"<<std::endl;
    for (int i = 0;i<N;++i){
        std::cout<<"Nombre num "<<i<<" : ";
        std::cin>>listeNombre[i];
        std::cout<<std::endl;
    }

    std::cout<<"Entrez un nombres de référence : ";
    std::cin>>ref;

    int petiteDif=abs(ref-listeNombre[0]);

    for (int i = 1;i<N;++i){
        if(abs(ref-listeNombre[i])<=petiteDif){

                petiteDif = abs(ref-listeNombre[i]);
                proche = (listeNombre[i]);
        }
    }
    std::cout<<"Le nombre de votre liste le plus proche de votre nombre de référence est : "<<proche<<std::endl;

    return 0;
}
