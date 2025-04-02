#include <iostream>

struct Domino{
  int x;
  int y;
};

struct Maillon{
  Domino domino;
  Maillon* next;
};

using Liste = Maillon*;

void saisieDomino(Domino & d){
  std::cout<<"Entrez les valeurs des deux parties du domino [1,6] : ";
  std::cin>>d.x>>d.y;
}

void aff_domino(Domino d){
  std::cout<<d.x<<":"<<d.y;
}

void aff_main(Liste m){
  /*
  if(m!=nullptr){
    if(m->next==nullptr)
      aff_domino(m->domino);
    else{
      aff_domino(m->domino);
      std::cout<<" - ";
      aff_main(m->next);
    }
  }

  */
  
  if(m!=nullptr){
    aff_domino(m->domino);
    std::cout<<" ";
    aff_main(m->next);
  }
}


void init(Liste & l){
  l=nullptr;
}

void ajoute_gauche(Liste & l,Domino d){
  /*
  std::cout<<"Ajoute domino : ";
  aff_domino(d);
  std::cout<<std::endl;
  */
  
  Liste aux = new Maillon;
  aux->domino.x=d.x;
  aux->domino.y=d.y;
  aux->next=l;
  l=aux;
}

void ajoute_droite(Liste &  l,Domino d){
  if(l==nullptr){
    l = new Maillon;
    l->domino.x=d.x;
    l->domino.y=d.y;
    l->next=nullptr;
  }
  else
    ajoute_droite(l->next,d);
}

void saisie_main_bis(Liste & m, int n){  
  if(n>0){
    m=new Maillon;
    Domino d;
    saisieDomino(d);
    ajoute_gauche(m,d);
    
    saisie_main_bis(m->next,n-1);
  }
}


void saisie_main(Liste & m){
  init(m);
  
  int nb_d;
  std::cout<<"Combien de dominos voulez-vous insérer ? ";
  std::cin>>nb_d;

  saisie_main_bis(m,nb_d);
  std::cout<<std::endl;
  
}
  
int main(){

  Liste main;
  saisie_main(main);
  std::cout<<main<<" "<<main->domino.x<<" "<<main->domino.y<<" "<<main->next<<" "<<std::endl;
  aff_main(main);

  
  return 0;
}
