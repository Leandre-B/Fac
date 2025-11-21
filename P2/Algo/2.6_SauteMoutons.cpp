#include <iostream>
#include <array>

const int M = 3;
using jeu = std::array<char,M*2+1>;

void init (jeu & plateau){
    for(int i = 0;i<M;++i){
        plateau[i]='B';
    }
    plateau[M]=' ';
    for(int i = M+1;i<M*2+1;++i){
        plateau[i]='N';
    }
}

void afficher(const jeu & plateau){
    for(int i = 0;i<M*2+1;++i){
        std::cout<<plateau[i];
    }
}

bool gagne(const jeu & plateau){
    for(int i = 0;i<M;++i){
        if(plateau[i]!='N')
            return false;
    }
    for(int i = M+1;i<M*2+1;++i){
        if(plateau[i]!='B')
            return false;
    }
    std::cout<<"GG";
    return true;
}

bool caseVide(const jeu & plateau, int mouton){
    if(plateau[mouton-1]==' ')
        return true;
    return false;
}

bool estJouable(const jeu & plateau, int mouton){
    if(!(mouton<0 or mouton>(M*2+1) or caseVide(plateau,mouton))){
        if(mouton!=M*2+1){
            if((plateau[mouton-1]=='B') and (plateau[mouton]==' ' or plateau[mouton+1]==' '))
                return true;
        }
        if(mouton!=0){
            if((plateau[mouton-1]=='N') and (plateau[mouton-2]==' ' or plateau[mouton-3]==' '))
                return true;
        }

    }
    return false;
}

bool perdu(const jeu & plateau){
    for(int i = 0;i<=M*2+1;++i){
        if((plateau[i]=='B') and (plateau[i+1]==' ' or plateau[i+2]==' '))
                return false;
        if((plateau[i]=='N') and (plateau[i-1]==' ' or plateau[i-2]==' '))
            return false;
    }
    std::cout<<"Perdu ! , plus aucun mouvement possible ! :(";
    return true;
}

void joue(jeu & plateau){
    int mouton;
    while(!(gagne(plateau) or perdu(plateau) )){
        do{
            std::cout<<"Quel mouton voulez-vous deplacer ? (saisir emplacement) ";
            std::cin>>mouton;
            if(!(estJouable(plateau, mouton)))
                std::cout<<"Valeur invialide."<<std::endl<<std::endl;
        }while(!(estJouable(plateau, mouton)));

        if(plateau[mouton-1]=='B'){
            if(plateau[mouton]==' '){
                plateau[mouton]='B';
                plateau[mouton-1]=' ';
            }
            if(plateau[mouton+1]==' '){
                plateau[mouton+1]='B';
                plateau[mouton-1]=' ';
            }
        }

        if(plateau[mouton-1]=='N'){
            if(plateau[mouton-2]==' '){
                plateau[mouton-2]='N';
                plateau[mouton-1]=' ';
            }
            if(plateau[mouton-3]==' '){
                plateau[mouton-3]='N';
                plateau[mouton-1]=' ';
            }
        }
        afficher(plateau);
        std::cout<<std::endl<<std::endl;
    }

}

int main(){

    jeu plateau;
    init(plateau);
    afficher(plateau);
    std::cout<<std::endl;
    joue(plateau);


    return 0;
}
