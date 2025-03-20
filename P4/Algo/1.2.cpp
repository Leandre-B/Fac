#include <iostream>

struct Personne{
    std::string nom;
    std::string prenom;
    std::string tel;
};
struct Maillon{
    Personne val;
    Maillon * suiv;
};

using Repertoire = Maillon *;

void init(Repertoire & repertoire){
    repertoire = nullptr;
}

void ajouterTete(std::string nom, std::string prenom, std::string tel, Repertoire & repertoire){
    Repertoire m;
    m=new Maillon;
    m->val.nom=nom;
    m->val.prenom=prenom;
    m->val.tel=tel;
    m->suiv = repertoire;
    repertoire=m;
}

void ajouterQueue(std::string nom, std::string prenom, std::string tel, Repertoire & repertoire){
    if(repertoire==nullptr){
        repertoire = new Maillon;
        repertoire->suiv = nullptr;
        repertoire->val.nom=nom;
        repertoire->val.prenom=prenom;
        repertoire->val.tel=tel;
    }else ajouterQueue(nom,prenom,tel,repertoire->suiv);
}

void affichePersonne(Personne p){
    std::cout<<"["<<p.nom<<","<<p.prenom<<","<<p.tel<<"] ";
}

void affRepertoire(Repertoire repertoire){
    if(repertoire==nullptr) std::cout<<std::endl;
    else{
        affichePersonne(repertoire->val);
        affRepertoire(repertoire->suiv);
    }
}

std::string telephone (std::string nom, std::string prenom, Repertoire repertoire){
    if(repertoire==nullptr) return "";
    else if(repertoire->val.nom == nom and repertoire->val.prenom == prenom)
        return repertoire->val.tel;
    else return telephone(nom,prenom,repertoire->suiv);
} 

int rechercherPositionRecur(std::string nom, std::string prenom, Repertoire repertoire){
    if(repertoire==nullptr) return 0;
    else if(repertoire->val.nom == nom and repertoire->val.prenom == prenom)
        return 1;
    else{
        //garde en tete que la 1ere val retourner est soit 0 soit 1 !!!
        //facile de faire une petite condition grace a ça :D
        int p= rechercherPositionRecur(nom,prenom,repertoire->suiv);
        if(p==0) return 0;
        else return p+1;
    }
}

int rechercherPositionIte(std::string nom, std::string prenom, Repertoire repertoire){
    int i =0;
    int trouve=false;
    bool fin=false;
    while(!trouve and !fin){
        if(repertoire==nullptr)
            fin=true;
        else{
            if(repertoire->val.nom != nom or repertoire->val.prenom != prenom){
                repertoire = repertoire->suiv;
            }
            else{
                trouve=true;
            }
        }
        ++i;
    }
    if(fin) return 0;
    else return i;
}


void ajouter(int position, std::string nom, std::string prenom, std::string tel, Repertoire & repertoire){
    if(position==0 or repertoire==nullptr)
        return ajouterTete(nom,prenom,tel,repertoire);
    else
        return ajouter(position-1,nom,prenom,tel,repertoire->suiv);
}

void supprimerPos (int position, Repertoire & repertoire){
    if(repertoire!=nullptr){
        if(position==0){
            Repertoire r=repertoire;
            repertoire=repertoire->suiv;
            delete r;
        }else
            supprimerPos(position-1,repertoire->suiv);
    }
}

void supprimerNoms(std::string nom, Repertoire & repertoire){
    if(repertoire!=nullptr){
        if(repertoire->val.nom==nom){
            Repertoire r=repertoire;
            repertoire=repertoire->suiv;
            delete r;
            supprimerNoms(nom,repertoire);
        }else
            supprimerNoms(nom,repertoire->suiv);
    }
}
int main(){

    Repertoire repertoire;
    init(repertoire);
    ajouterTete("bodo","jean","06.......",repertoire);
    ajouterQueue("bodos","albert","07.......",repertoire);
    ajouterTete("bodo","paul","0701......",repertoire);
    ajouterQueue("bodo","andre","08......",repertoire);
    affRepertoire(repertoire);
    //std::cout<<telephone("bodo","albert",repertoire)<<std::endl;
    //std::cout<<rechercherPositionIte("bodo","albert",repertoire)<<std::endl;

    //std::cout<<"Apres ajout pos donnee : "<<std::endl;
    ajouter(3,"Mr","oui","1234",repertoire);
    
    //supprimerPos(2,repertoire);
    affRepertoire(repertoire);

    supprimerNoms("bodos",repertoire);
    affRepertoire(repertoire);

    return 0;
}
