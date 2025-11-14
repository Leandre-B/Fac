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
            ajouter(abr->sag, e);
        else
            ajouter(abr->sad, e);
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

//Q8
void fusionne(Abr & abr1, Abr & abr2){
    if(abr2!=nullptr){
        fusionne(abr1, abr2->sag);
        ajouter(abr1, abr2->elem);
        fusionne(abr1, abr2->sad);
    }
}

//Q9
int estEquilibreBis(Abr abr, bool & equi){
    if(equi!=false){
        if(abr==nullptr)
            return 0;
        if(abr->sag!=nullptr and abr->sad==nullptr)
            return -1;
        if(abr->sag==nullptr and abr->sad!=nullptr)
            return 1;
        else{
            int f_sag = estEquilibreBis(abr->sag, equi);
            int f_sad = estEquilibreBis(abr->sad, equi);
            if(f_sad-f_sag != 0 and f_sad-f_sag != 1 and f_sad-f_sag != -1)
                equi = false;
            std::cout<<f_sad+f_sag<<"\n";
            return f_sad+f_sag;
        }
    }
    return 0;
}

void estEquilibre(Abr abr){
    bool equi=true;
    estEquilibreBis(abr, equi);
    if (!equi)
        std::cout<<"Non\n";
    else
        std::cout<<"Oui\n";
}


int main(){
    Abr abr1 = nullptr;
    Element t1[] = {10, 9, 7, 13, 10, 26, 26, 23, 26, 15};
    genere(abr1, t1, 10);
    affiche(abr1);

    Abr abr2 = nullptr;
    Element t2[]= {15 , 10 , 26 , 7 , 9 , 23 , 13 , 26 , 10 , 26};
    genere(abr2, t2, 10);
    affiche(abr2);

    //fusionne(abr1, abr2);
    affiche(abr1);

    estEquilibre(abr2);



    return 0;
}