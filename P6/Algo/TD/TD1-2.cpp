#include <iostream>

//rdm()
#include <cstdlib>
#include <ctime>

#include <array>
#include <cstdint> //uint_8

const unsigned int NL=100;
const unsigned int NC=90;

using LigneMatrice = std::array<unsigned int,NC>;
using Matrice = std::array<LigneMatrice,NL>; //[NL][NC]

void gen_img(Matrice & m){
    for(unsigned int i=0; i<NL; ++i){
        int nb_of_same_color = 0;
        int rdm_color;
        for(unsigned int j=0; j<NC; ++j){
            if(nb_of_same_color==0){
                nb_of_same_color = rand()%50;
                rdm_color = rand()%255 + 1;
            }
            m[i][j]=rdm_color;
            --nb_of_same_color;
        }
    }
}

void afficheMatrice(const Matrice & m){
    for(unsigned int i=0; i<NL; ++i){
        for(unsigned int j=0; j<NC; ++j){
            std::cout<<"["<<static_cast<int>(m[i][j])<<"] ";
        }
        std::cout<<"\n";
    }
}

struct Maillon{
    uint8_t val;
    uint8_t n=0; //nbr de val
    Maillon* suiv=nullptr;
};

using LignePixels = Maillon*;
using Image = std::array<LignePixels,NC>;

void compresseLigne(const LigneMatrice & lm, LignePixels & lp){
    lp=new Maillon;
    LignePixels aux_lp = lp;
    lp->val=lm[0];
    ++lp->n;
    lp->suiv=nullptr;

    for(unsigned int i=1; i<NC; ++i){
        if(lm[i]==lp->val)
            ++lp->n;
        else{
            lp->suiv = new Maillon;
            lp=lp->suiv;
            lp->val=lm[i];
            ++lp->n;
            lp->suiv=nullptr;
        }
    }
    lp=aux_lp;
}

void compresse(const Matrice & m, Image & img){
    for(unsigned int i=0; i<NC; ++i)
        compresseLigne(m[i],img[i]);
}

void afficheLignePixel(const LignePixels & l){
    if(l!=nullptr){
        std::cout<<static_cast<int>(l->val)<<" ("<<static_cast<int>(l->n)<<") ";
        afficheLignePixel(l->suiv);
    }
}

void afficheImg(const Image & img){
    for(unsigned int i=0; i<NC; ++i){
        afficheLignePixel(img[i]);
        std::cout<<"\n";
    }
}

int calcNbMaillon(LignePixels lp){
    if(lp==nullptr)
        return 0;
    else{
        return 1+calcNbMaillon(lp->suiv);
    }
}

int main(){
    srand(time(nullptr));

    Matrice m;
    gen_img(m);
    afficheMatrice(m);
    std::cout<<"\n";

    Image img;
    compresse(m,img);
    afficheImg(img);

    int size_non_compr = NC*NL*sizeof(uint8_t);
    std::cout<<"Taille non compréssé : "<<size_non_compr<<" bits \n";


    int nb_maillon=0;
    for(unsigned int i=0; i<NC; ++i){
        nb_maillon += calcNbMaillon(img[i]);
    }
    int size_compr= nb_maillon*sizeof(Maillon);
    std::cout<<"Taille comprésé : "<<size_compr<<" bits \n";

    std::cout<<"Ration de compression : "<<static_cast<float>(size_non_compr)/size_compr<<"\n";
    //la compression dépend beaucoup du nombre du nombre couleur semblable cote a cote [12,12,12,56,56,56].
    //si celui ci est faible, l'img compréssée prendra plus de place que celle qui ne l'est pas à cause de place en mémoire que
    //prend un ptr (64bits)
    return 0;
}