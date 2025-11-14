#include <iostream>


using Element = int;

struct Noeud{
    Element elem;
    Noeud* sag;
    Noeud* sad;
};

using Abr = Noeud*;

//Q2
void ajouter(Abr & abr, const Element & e){
    if(abr==nullptr){
        abr = new Noeud;
        abr->elem = e;
        abr->sag=nullptr;
        abr->sad=nullptr;
    }else{
        if(e<=abr->elem)
            return ajouter(abr->sag, e);
        else
            return ajouter(abr->sad, e);
    }
}

//Q3
void genere(Abr & abr, Element* t, uint n){
    for(uint i=0; i<n; ++i){
        ajouter(abr,t[i]);
    }
}

//Q4
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

//Q5
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

//Q6
//on suppose qu'il y'a un sad
//recherche le plus grand elem de son sad
Abr predecesseur(Abr abr){
    if(abr==nullptr) return nullptr;
    if(abr->sad==nullptr)
        return abr;
    else{
        if(abr->sad!=nullptr) return predecesseur(abr->sad);
        else
            return nullptr;
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
                Noeud* aux = abr;
                abr=abr->sag;
                delete aux;
            }
            else if(abr->sag==nullptr and abr->sad!=nullptr){
                Noeud* aux = abr;
                abr=abr->sad;
                delete aux;
            }

            //si deux fils
            else{
                //on remplace sa valeur par celle de son prédécésseur
                Noeud* pred = predecesseur(abr->sag);
                abr->elem=pred->elem;
                std::cout<<"Pred : "<<abr->elem<<"\n";
                supprime(pred, pred->elem);
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


int main(){
    Abr abr = nullptr;
    Element t[] = {5, 3, 7, 1, 8, 10, 9, 5, 7, 7};
    genere(abr, t, 10);
    affiche(abr);
    supprime(abr, 3);
    affiche(abr);

    return 0;
}