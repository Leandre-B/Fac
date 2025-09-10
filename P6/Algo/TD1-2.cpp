#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

const unsigned int NL=100;
const unsigned int NC=100;

using LigneMatrice = std::array<unsigned int,NC>;
using Matrice = std::array<LigneMatrice,NL>; //[NL][NC]

void gen_img(Matrice & m){
    for(unsigned int i=0; i<NL; ++i){
        unsigned int j=0;
        while(j<NC){
            int rdm_color = rand()%256;

            int rdm_sequence = rand()%10;  
            if(rdm_sequence+j>=NC) rdm_sequence=NC-j; //si on depasse 
            for(unsigned int k=j; k<rdm_sequence+j; ++k)
                m[i][k]=rdm_color;
            j+=rdm_sequence;
        }
    }
}

void afficheMatrice(const Matrice & m){
    for(unsigned int i=0; i<NL; ++i){
        for(unsigned int j=0; j<NC; ++j){
            std::cout<<"["<<m[i][j]<<"] ";
        }
        std::cout<<"\n";
    }
}

struct Maillon{
    unsigned int val;
    unsigned int n=0;
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
        std::cout<<l->val<<" ("<<l->n<<") ";
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

    int size_non_compr = NC*NL*sizeof(unsigned int);
    std::cout<<"Taille non compréssé : "<<size_non_compr<<" bits \n";


    int nb_maillon=0;
    for(unsigned int i=0; i<NC; ++i){
        nb_maillon += calcNbMaillon(img[i]);
    }
    int size_compr= nb_maillon*sizeof(Maillon);
    std::cout<<"Taille comprésé : "<<size_compr<<" bits \n";

    std::cout<<"Ration de compression : "<<static_cast<float>(size_non_compr)/size_compr<<"\n"; 

    return 0;
}