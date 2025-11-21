#include <array>
#include <iostream>

const int COL=4;
const int LIGN=10;

void affMastermind (std::array<std::array<int,COL>,LIGN> &tab,std::array<std::array<char,COL>,LIGN> &tabHint,int essaie){
    int nb=0;
    for(int i = 0;i<LIGN;++i){
        for(int j=0;j<COL;++j){
            std::cout<<tab[i][j];
        }
        std::cout<<" ";
        if(nb<=essaie){
            for(int k=0;k<COL;++k){
                std::cout<<tabHint[i][k];
            }
            ++nb;
        }
        std::cout<<std::endl;
    }
}

void saisieCodeSecret(std::array<int,COL > &code){
    int symb;
    bool valide;
    for(int i=0;i<4;++i){
        valide=false;
        while(!valide){
            std::cout<<"Entrez le symbole num "<<i+1<<" : ";
            std::cin>>symb;

            if (symb<1 or symb>6)
                std::cout<<"Valeur incorectte, veuillez recommencer."<<std::endl;
            else{
                code[i]=symb;
                valide=true;
            }
        }
    }
}

void saisieCode(std::array<std::array<int,COL >,LIGN> &mastermind,int &essaie){
    int symb;
    bool valide;
    for(int i=0;i<4;++i){
        valide=false;
        while(!valide){
            std::cout<<"Entrez le symbole num "<<i+1<<" : ";
            std::cin>>symb;

            if (symb<1 or symb>6)
                std::cout<<"Valeur incorectte, veuillez recommencer."<<std::endl;
            else{
                mastermind[essaie][i]=symb;
                valide=true;
            }
        }
    }
}

std::array<std::array<char,COL >,LIGN> hints(std::array<std::array<int,COL >,LIGN> &mastermind,std::array<int,COL > &code,std::array<std::array<char,COL >,LIGN> tabHint,int &essaie){
    int j;
    bool trouve;
    bool verif[]={false,false,false,false};

    for(int cpt=0;cpt<4;++cpt){
        trouve=false;
        j=0;
        if(mastermind[essaie][cpt]==code[cpt]){
            tabHint[essaie][cpt]='P';
            verif[cpt]=true;
        }
        while(!trouve and j<4){
            if((mastermind[essaie][cpt]==code[j]and j!=cpt and !verif[j])){
                tabHint[essaie][cpt]='G';
                verif[j]=true;
                trouve=true;
            }
            ++j;
        }
        if(mastermind[essaie][cpt]==code[cpt]){
            tabHint[essaie][cpt]='P';
            verif[cpt]=true;
        }
    }
    return tabHint;
}

bool winCheck(std::array<std::array<int, COL>,LIGN> mastermind,std::array<int, COL> code,int essaie){
    for(int i=0;i<COL;++i){
        if(mastermind[essaie][i]!=code[i])
            return false;
    }

    return true;
}

void trier(std::array<int,COL > &code){
    char c;
    for (unsigned int j = 0;j<COL;++j){
        for (unsigned int i =0;i<COL;++i){
            if(code[i]>code[i+1]){
                c=code[i];
                code[i]=code[i+1];
                code[i+1]=c;
            }
        }
    }
}

void game(std::array<int, COL> code , std::array<std::array<int, COL>,LIGN> mastermind,std::array<std::array<char, COL>,LIGN> tabHint){

    int essaie=0;
    bool win=false;

    std::cout<<std::endl<<"Bienvenue dans le jeu Mastermind ! "<<std::endl
    <<"Un premier joueur, le codificateur, va secretement, entrer un code secret contenant des chiffres pouvant aller de 1 a 6."<<std::endl
    <<"Le deuxieme joueur, le decodeur va devoir dechifrer a l'aide de deductions successives le code ! "<<std::endl
    <<"Des indices seront donnes en fonction de la position et de la nature du code entre !"<<std::endl
    <<"N si rien n'est bon"<<std::endl<<"G si un chiffre est bon mais a la mauvaise place"<<std::endl<<"P si un chiffre est bon et a la bonne place."<<std::endl
    <<"Amusez-vous bien !!!!!! :D"<<std::endl<<std::endl;

    std::cout<<"Au tour du codificateur (joueur 1) d'entrer un code secret !"<<std::endl;
    saisieCodeSecret(code);

    std::cout<<std::endl<<"Au tour du codificateur (joueur 2) de trouver le code secret !"<<std::endl;

    while(essaie<10 and !win){

        saisieCode(mastermind,essaie);
        tabHint=hints(mastermind,code,tabHint,essaie);
        trier(code);
        affMastermind(mastermind,tabHint,essaie);
        win=winCheck(mastermind,code,essaie);
        if(win){
            std::cout<<"Bravo tu as trouvé le code (";
            for(int i=0;i<COL;++i){
                std::cout<<code[i];
            }
            std::cout<<") en "<<essaie+1<<"essaie(s)!"<<std::endl;
        }
        essaie++;
    }


}

int main(){
    using TLigne=std::array<int, COL>;
    using tab=std::array<TLigne,LIGN>;
    std::array<std::array<char,COL >,LIGN> tabHint;
    tab mastermind;
    TLigne code;


    for(int i = 0;i<LIGN;++i){
        for(int j=0;j<COL;++j){
            mastermind[i][j]=0;
            tabHint[i][j]='N';
        }
    }
    game(code,mastermind,tabHint);

    return 0;
}
