#include <iostream>


using Element = int;

struct NoeudAbr{
    Element elem;
    NoeudAbr* sag;
    NoeudAbr* sad;
};

using Abr = NoeudAbr*;

//Q2 ---------------------
void ajouter(Abr & abr, const Element & e){
    if(abr==nullptr){
        abr = new NoeudAbr;
        abr->elem = e;
        abr->sag=nullptr;
        abr->sad=nullptr;
    }else{
        if(e<=abr->elem)
            ajouter(abr->sag, e);
        else
            ajouter(abr->sad, e);
    }
}
//---------------------Q2



//Q3 ---------------------
void genere(Abr & abr, Element* t, uint n){
    for(uint i=0; i<n; ++i){
        ajouter(abr,t[i]);
    }
}
//--------------------- Q3


//Q4 ---------------------
void afficheBis(Abr & abr){
    if(abr!=nullptr){
        afficheBis(abr->sag);
        std::cout<<abr->elem<<" ";
        afficheBis(abr->sad);
    }
}

void affiche(Abr & abr){
    std::cout<<"\n";
    afficheBis(abr);
    std::cout<<"\n";
}
//--------------------- Q4


//Q5 ---------------------
bool recherche(Abr abr, const Element & n){
    if(abr==nullptr){
        return false;
    }else if(abr->elem==n)
        return true;
    else{
        if(n<abr->elem)
            return recherche(abr->sag, n);
        else
            return recherche(abr->sad, n);
    }
}
//--------------------- Q5


//Q6
//supprime un noeud
//on suppose qu'il y'a un sad
//recherche le plus grand elem de son sad
Abr predecesseur(Abr abr){
    if(abr==nullptr) return nullptr;
    if(abr->sad==nullptr)
        return abr;
    else{
        while(abr->sad!=nullptr)
            abr=abr->sad;
        return abr;
    }
}

void supprime(Abr & abr, const Element & n){
    if(abr!=nullptr){
        if(abr->elem==n){
            //si c'est une feuille
            if(abr->sag==nullptr and abr->sad==nullptr){
                delete abr;
                abr=nullptr;
            }

            //si qu'un seul fils
            else if(abr->sag!=nullptr and abr->sad==nullptr){
                NoeudAbr* aux = abr;
                abr=abr->sag;
                delete aux;
            }
            else if(abr->sag==nullptr and abr->sad!=nullptr){
                NoeudAbr* aux = abr;
                abr=abr->sad;
                delete aux;
            }

            //si deux fils
            else{
                //on remplace sa valeur par celle de son prédécésseur
                NoeudAbr* pred = predecesseur(abr->sag);
                abr->elem=pred->elem;
                std::cout<<"Pred : "<<abr->elem<<"\n";
                supprime(abr->sag, pred->elem);
            }
        }
        else{
            if(n<abr->elem)
                return supprime(abr->sag, n);
            else
                return supprime(abr->sad, n);
        }
    }
}
//------------------- Q6

//Q7
//somme de toute les valeurs d'un arbre dont la val max est e
int sommeAbre(Abr abr, Element e){
    if(abr==nullptr){
        return 0;
    }else{
        int sum = 0;
        if(abr->elem < e)
            sum+=abr->elem;
        sum+=sommeAbre(abr->sag, e);
        return sum+sommeAbre(abr->sad, e);
    }
}

int somme(Abr abr, Element e){
    if(abr==nullptr)
        return 0;
    else{
        int sum=0;
        if(abr->elem < e){
            sum+=abr->elem;
            sum+=somme(abr->sad, e);
        }
        if(abr->elem <= e){
            sum+=sommeAbre(abr->sag, e);
        }
        return sum;
    }
}
//-------------------- Q7

//Q8 --------------
void fusionne(Abr & abr1, Abr & abr2){
    if(abr2!=nullptr){
        fusionne(abr1, abr2->sag);
        ajouter(abr1, abr2->elem);
        fusionne(abr1, abr2->sad);
    }
}
//------------- Q8

//Q9 -------------------
int estEquilibreBis(Abr abr){
    if(abr==nullptr)
        return 0;
    else{
        int f_sag = 1+estEquilibreBis(abr->sag);
        int f_sad = 1+estEquilibreBis(abr->sad);

        if(f_sad==0 or f_sag==0)
            return -1;

        if(f_sad-f_sag != 0 and f_sad-f_sag != 1 and f_sad-f_sag != -1){
            return -1;
        }
        //std::cout<<"Facteur equi : "<<f_sad-f_sag<<"\n";

        //hauteur = max de sous arbres
        if(f_sad>f_sag)
            return f_sad;
        else
            return f_sag;
    }
}

bool estEquilibre(Abr abr){
    return estEquilibreBis(abr)!=-1;
}
//---------- Q9

//Q10
void detruit(Abr & abr){
    if(abr!=nullptr){
        detruit(abr->sag);
        detruit(abr->sad);

        std::cout<<"Delete : "<<abr<<" : "<<abr->elem<<"\n";
        delete abr;
        abr=nullptr;
    }
}
//------------ Q10
