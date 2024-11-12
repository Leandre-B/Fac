#include <iostream>
#include <array>

using tabPrecipitation = std::array<int, 3>;

tabPrecipitation precAngers, precNantes, precRennes;

void saisiePrec(tabPrecipitation & precVille){
    for(int i = 0;i<3;++i){
        std::cin >> precVille[i];
    }
}

void affTabPrec(tabPrecipitation precVille){
    for(int i = 0;i<3;++i){
        std::cout << precVille[i]<<" ";
    }
}
int mini(tabPrecipitation precVille){
    int mini=precVille[0];
    for(int i = 1;i<3;++i){
        if(mini>precVille[i])
            mini=precVille[i];
    }
    return mini;
}

int miniVilles(){
/*------------------------
Version peut-etre plus lisible et compréhensible, mais moins efficace (appel a la meme fonction plusieurs fois)

    int mini = mini(precAngers);

    if (mini>mini(precNantes))
        mini = mini(precNantes);
    if(mini>mini(precRennes)
        mini= mini(precRennes).
    )
    return mini;
-----------------------*/

    int miniAngers = mini(precAngers);
    int miniNantes = mini(precNantes);
    int miniRennes = mini(precRennes);

    if (miniAngers<miniNantes and miniAngers<miniRennes)
        return miniAngers;
    if (miniNantes<miniAngers and miniNantes<miniRennes)
        return miniNantes;
    return miniRennes;
}

int maxi(tabPrecipitation precVille){
    int maxi=precVille[0];
    for(int i = 1;i<3;++i){
        if(maxi<precVille[i])
            maxi=precVille[i];
    }
    return maxi;
}
int maxiVilles(){
    int maxiAngers = maxi(precAngers);
    int maxiNantes = maxi(precNantes);
    int maxiRennes = maxi(precRennes);

    if (maxiAngers>maxiNantes and maxiAngers>maxiRennes)
        return maxiAngers;
    if (maxiNantes>maxiAngers and maxiNantes>maxiRennes)
        return maxiNantes;
    //if (maxiRennes>maxiAngers and maxiRennes>maxiNantes)
        return maxiRennes;
}

int main(){

    std::cout << "Saisir les precipitaions de chaque mois pour la ville de : "<<std::endl;
    std::cout <<"Angers : " <<std::endl;
    saisiePrec(precAngers);
    std::cout <<"Nantes : " <<std::endl;
    saisiePrec(precNantes);
    std::cout <<"Rennes : " <<std::endl;
    saisiePrec(precRennes);

    std::cout <<std::endl<<"Angers : ";
    affTabPrec(precAngers);
    std::cout <<std::endl<<"Nantes : ";
    affTabPrec(precNantes);
    std::cout <<std::endl<<"Rennes : ";
    affTabPrec(precRennes);

    std::cout<<std::endl<<"Petite : "<<miniVilles() <<" Grande : "<<maxiVilles();


    return 0;
}
