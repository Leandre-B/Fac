#include <iostream>

#include <chrono>

#include <ctime>
#include <cstdlib>

using Element = int;

struct Noeud{
    Element elem;
    Noeud* sag;
    Noeud* sad;
    int hauteur; //hauteur de l'arbre dont il est la racine
};

using Arbre = Noeud*;

//Q2 ---------------------
void ajouter(Arbre & abr, const Element & e){
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
//---------------------Q2



//Q3 ---------------------
void genere(Arbre & abr, Element* t, uint n){
    for(uint i=0; i<n; ++i){
        ajouter(abr,t[i]);
    }
}
//--------------------- Q3


//Q4 ---------------------
void afficheBis(Arbre & abr){
    if(abr!=nullptr){
        afficheBis(abr->sag);
        std::cout<<abr->elem<<" ";
        afficheBis(abr->sad);
    }
}

void affiche(Arbre & abr){
    std::cout<<"\n";
    afficheBis(abr);
    std::cout<<"\n";
}
//--------------------- Q4


//Q5 ---------------------
bool recherche(Arbre abr, const Element & n){
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
Arbre predecesseur(Arbre abr){
    if(abr==nullptr) return nullptr;
    if(abr->sad==nullptr)
        return abr;
    else{
        while(abr->sad!=nullptr)
            abr=abr->sad;
        return abr;
    }
}

void supprime(Arbre & abr, const Element & n){
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
//------------------- Q6

//Q7
//somme de toute les valeurs d'un arbre dont la val max est e
int sommeAbre(Arbre abr, Element e){
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

int somme(Arbre abr, Element e){
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
void fusionne(Arbre & abr1, Arbre & abr2){
    if(abr2!=nullptr){
        fusionne(abr1, abr2->sag);
        ajouter(abr1, abr2->elem);
        fusionne(abr1, abr2->sad);
    }
}
//------------- Q8

//Q9 -------------------
int estEquilibreBis(Arbre abr){
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

bool estEquilibre(Arbre abr){
    return estEquilibreBis(abr)!=-1;
}
//---------- Q9

//Q10
void detruit(Arbre & abr){
    if(abr!=nullptr){
        detruit(abr->sag);
        detruit(abr->sad);

        //std::cout<<"Delete : "<<abr<<" : "<<abr->elem<<"\n";
        delete abr;
        abr=nullptr;
    }
}
//------------ Q10


//============ PART 2 =============
int hauteur(Arbre a){
    if(a==nullptr)
        return -1;
    else
        return a->hauteur;
}

// maj de la hauteur de l'arbre de racine a
// à partir de ses sous-arbres
int majHauteur(Arbre a){
    if(a==nullptr) return -1;
        a->hauteur = 1 + std::max(majHauteur(a->sag),majHauteur(a->sad));
    return a->hauteur;
}

void rotationDroite(Arbre & a){
    Noeud* b=a->sag;
    Noeud* c=b->sad;

    b->sad = a;
    a->sag = c;

    a=b;

}

void rotationGauche(Arbre & a){
    Noeud* b=a->sad;
    Noeud* c=b->sag;

    b->sag = a;
    a->sad = c;

    a=b;
}

void rotationGaucheDroite(Arbre & a){
    rotationGauche(a->sag);
    rotationDroite(a);
}

void rotationDroiteGauche(Arbre & a){
    rotationDroite(a->sad);
    rotationGauche(a);
}

//suppose que les sous arbres de a sont équilibrés
void reequilibre(Arbre & a){
    int fact_a = hauteur(a->sad) - hauteur(a->sag);
    if(fact_a==-2){
        int fact_sag = hauteur(a->sag->sad) - hauteur(a->sag->sag);
        if(fact_sag==-1   or fact_sag==0)
            rotationDroite(a);
        else if(fact_sag==1)
            rotationGaucheDroite(a);
        //majHauteur(a);

    }else if(fact_a==2){
        int fact_sad = hauteur(a->sad->sad) - hauteur(a->sad->sag);
        if(fact_sad==1 or fact_sad==0)
            rotationGauche(a);
        else if(fact_sad==-1)
            rotationDroiteGauche(a);
        //majHauteur(a);
    }
    majHauteur(a);
}


void ajouterAVL(Arbre & a, Element e){
    if(a==nullptr){
        a = new Noeud;
        a->elem = e;
        a->sag=nullptr;
        a->sad=nullptr;
        a->hauteur = 0;
    }else{
        if(e<=a->elem)
            ajouterAVL(a->sag, e);
        else if(e>a->elem)
            ajouterAVL(a->sad, e);
        else
            return;
        //majHauteur(a);
        reequilibre(a);
    }
}


void aff(Arbre a){
    if(a!=nullptr){
        aff(a->sag);
        std::cout<<"Val : "<<a->elem<<" Hauteur : "<<a->hauteur<<"\n";
        aff(a->sad);
    }
}

void genereAVL(Arbre & a, Element* t, uint n){
    for(uint i=0; i<n; ++i){
        ajouterAVL(a,t[i]);
    }
}
//===============================


int hauteurArb(Arbre a){
    if(a==nullptr)
        return -1;
    else
        return 1+std::max(hauteurArb(a->sag), hauteurArb(a->sad));
}

void comparer(int* t, uint n){
    std::cout<<"--------------------\n";

    // std::cout<<"Valeurs :\n";
    // for(uint i=0; i<n; ++i)
    //     std::cout<<t[i]<<" ";

    Arbre avl = nullptr;
    Arbre abr = nullptr;

    std::chrono::time_point moment_debut = std::chrono::system_clock::now();
    genere(abr, t, n);
    std::chrono::time_point moment_fin = std::chrono::system_clock::now();

    std::cout<<"\n\nAbr : \n duree gen :" <<std::chrono::duration<float>(moment_fin - moment_debut).count()
    <<"\nhauteur "<<hauteurArb(abr)<<"\nEst equilibre ? "<<estEquilibre(abr);

    majHauteur(abr);
    //affiche(abr);

    moment_debut = std::chrono::system_clock::now();
    genereAVL(avl, t, n);
    moment_fin = std::chrono::system_clock::now();

    std::cout<<"\n\nAvl : \n duree gen :" <<std::chrono::duration<float>(moment_fin - moment_debut).count()
    <<"\nhauteur "<<hauteurArb(avl)<<"\nEst equilibre ? "<<estEquilibre(avl);
    //affiche(avl);
    detruit(abr); detruit(avl);
    std::cout<<"\n\n";
}


int main(){
    std::srand(time(nullptr));

    int t1[] = {5 , 3 , 7 , 1 , 8 , 10 , 9 , 5 , 7 , 7};
    int t2[] = {1, 3, 5, 5, 7, 7, 7, 8, 9, 10 };
    int t3[] = {5 , 10 , 26 , 7 , 9 , 23 , 13 , 26 , 10 , 26 }; 
    int* t4 = new int[100000];

    for(int i=0; i<100000; ++i)
        t4[i]=rand()%100000;

    comparer(t4, 100000);

    for(int i=0; i<10000; ++i)
        t4[i]=i;
    comparer(t4, 100000);
    // comparer(t1, 10);
    // comparer(t2, 10);
    // comparer(t3, 10);
    
}