#include <string>
#include <iostream>
#include <fstream>

struct Ingredient{
    std::string nom;
    float quantite;
};

struct Stock{
    unsigned int nbIngredient;
    Ingredient* tabIngredient;
};

struct Recette{
    std::string intitule;
    unsigned int portion;
    unsigned int nbIngredient;
    Ingredient* tabIngredient;
};


bool initStock(std::string ficStock,Stock & stock){
    char space;
    std::ifstream fic;
    fic.open(ficStock);
    if(fic.is_open()){
        fic>>stock.nbIngredient;
        stock.tabIngredient = new Ingredient [stock.nbIngredient];

        for(unsigned int i =0;i<stock.nbIngredient;++i){
            fic>>stock.tabIngredient[i].quantite;
            fic.get(space);
            getline(fic,stock.tabIngredient[i].nom);
        }
        return true;

    }else{
        return false;
    }
}

void affStock(Stock stock){
    std::cout<<"En stock avant de cuisiner : "<<std::endl;
    for(unsigned int i = 0;i<stock.nbIngredient;++i){
        std::cout<<stock.tabIngredient[i].quantite<<" "<<stock.tabIngredient[i].nom<<std::endl;
    }
}

bool loadRecette(std::string ficRecette,Recette & recette){
    char space;
    std::ifstream fic;
    fic.open(ficRecette);
    if(fic.is_open()){
        std::getline(fic,recette.intitule);
        fic >>recette.portion;
        fic >>recette.nbIngredient;
        recette.tabIngredient = new Ingredient [recette.nbIngredient];

        for(unsigned int i =0;i<recette.nbIngredient;++i){
            fic>>recette.tabIngredient[i].quantite;
            fic.get(space);
            getline(fic,recette.tabIngredient[i].nom);
        }
        return true;

    }else{
        return false;
    }
}


bool estPresentIngr(Ingredient i, Stock stock){
    bool present = false;
    unsigned int j = 0;
    while(!present and j<stock.nbIngredient){
        if((stock.tabIngredient[j]).nom==i.nom)
            if((stock.tabIngredient[j]).quantite>=i.quantite)
                present = true;
        ++j;
    }
    return present;
}

bool peutCuisiner(Recette recette, Stock stock){
    bool cuisiner = true;
    unsigned int j = 0;
    while(cuisiner and j<recette.nbIngredient){
        if(!estPresentIngr(recette.tabIngredient[j],stock))
            cuisiner = false;
        ++j;
    }
    return cuisiner;
}

void realRecette(Recette recette, Stock stock){
    bool trouve;
    unsigned int j;
    for(unsigned int i=0;i<recette.nbIngredient;++i){
        trouve=false;
        j=0;
        while(j<stock.nbIngredient or !trouve){
            if(recette.tabIngredient[i].nom==stock.tabIngredient[j].nom){
                trouve=true;
                stock.tabIngredient[j].quantite -= recette.tabIngredient[i].quantite;
            }
            ++j;
        }
    }
}


int main(){
    Stock stock;
    std::string ficStock="Stock.txt";
    initStock(ficStock, stock);

    affStock(stock);

    Recette crepes;
    std::string ficCrepes="Crepes.txt";
    loadRecette(ficCrepes, crepes);

    Recette donuts;
    std::string ficDonut="Donuts.txt";
    loadRecette(ficDonut, donuts);

    std::cout<<"==============================="<<std::endl;
    std::cout<<"Est-il possible de cuisiner "<<donuts.portion<<" "<<donuts.intitule<<" ? ";
    if(peutCuisiner(donuts, stock)==true){
        std::cout<<"true"<<std::endl;
        realRecette(donuts, stock);
        std::cout<<"En stock après avoir cuisiner "<<donuts.portion<<" "<<donuts.intitule<<" "<<std::endl;
        affStock(stock);
    }else{
        std::cout<<"false"<<std::endl;
    }

    std::cout<<"==============================="<<std::endl;
    std::cout<<"Est-il possible de cuisiner "<<crepes.portion<<" "<<crepes.intitule<<" ? ";
    if(peutCuisiner(crepes, stock)==true){
        std::cout<<"true"<<std::endl;
        realRecette(crepes, stock);
        std::cout<<"En stock après avoir cuisiner "<<crepes.portion<<" "<<crepes.intitule<<" "<<std::endl;
        affStock(stock);
    }else{
        std::cout<<"false"<<std::endl;
    }




    return 0;
}
