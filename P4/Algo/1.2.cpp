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
    std::cout<<"["<<p.nom<<","<<p.prenom<<","<<p.tel<<"]";
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

//en recursif mais pb qd on est au bout de la liste... :/
int rechercherPositionRecur(std::string nom, std::string prenom, Repertoire repertoire){
    if(repertoire==nullptr) return 0;
    else if(repertoire->val.nom == nom and repertoire->val.prenom == prenom)
        return 1;
    else return rechercherPositionRecur(nom,prenom,repertoire->suiv)*2;
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

//y'a pas mal de probleme là mdr
void ajouter(int position, std::string nom, std::string prenom, std::string tel, Repertoire & repertoire){
    int i =1;
    int trouve=false;
    bool fin=false;
    Repertoire r=repertoire;
    while(!trouve and !fin){
        repertoire=repertoire->suiv;
        if(repertoire==nullptr)
            fin=true;
        else{
            if(i==position){
                std::cout<<"on ajouter après "<<repertoire->val.prenom<<std::endl;
                //ajout de la personne
                Repertoire m;
                m=new Maillon;

                m->val.nom=nom;
                m->val.prenom=prenom;
                m->val.tel=tel;

                m->suiv=repertoire;
                repertoire=m;
                trouve=true;
            }
        }
        ++i;
    }
    if(fin){
        //on ajoute a la fin
        repertoire = new Maillon;
        repertoire->suiv = nullptr;
        repertoire->val.nom=nom;
        repertoire->val.prenom=prenom;
        repertoire->val.tel=tel;
    }
}

int main(){

    Repertoire repertoire;
    init(repertoire);
    ajouterTete("bodo","jean","06.......",repertoire);
    ajouterQueue("bodo","albert","07.......",repertoire);
    ajouterTete("bodo","paul","0701......",repertoire);
    ajouterQueue("bodo","andre","08......",repertoire);
    affRepertoire(repertoire);
    //std::cout<<telephone("bodo","albert",repertoire)<<std::endl;
    //std::cout<<rechercherPositionIte("bodo","albert",repertoire)<<std::endl;

    std::cout<<"Apres ajout pos donnee : "<<std::endl;
    ajouter(3,"Mr","oui","1234",repertoire);
    affRepertoire(repertoire);

    return 0;
}