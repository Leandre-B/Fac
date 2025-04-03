#include <iostream>
#include <ctime>
#include <cstdlib>


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
  
  if(m!=nullptr){
    if(m->next==nullptr){
      aff_domino(m->domino);
      std::cout<<std::endl;
    }
    else{
      aff_domino(m->domino);
      std::cout<<" - ";
      aff_main(m->next);
    }
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
    Domino d;
    saisieDomino(d);
    ajoute_droite(m,d);
    
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

void supprime_premier(Liste & m){
  if(m!=nullptr){
    Liste aux = m;
    m=m->next;
    delete aux;
  }
}

int nb_dominos(Liste m){
  if(m==nullptr) return 0;
  else return 1+nb_dominos(m->next);
}

void init_pioche(Liste & pioche){
  init(pioche);
  for(int i=0;i<=6;++i){
    for(int j = i;j<=6;++j){
      Domino d;
      d.x=i;
      d.y=j;
      ajoute_gauche(pioche, d);
    }
  }
}

void supr_domino(Liste & l, Domino & domino_supr,int n_to_supr,int n){
  if(l!=nullptr){
    if(n+1==n_to_supr){
      domino_supr.x= l->domino.x;
      domino_supr.y = l->domino.y;
      
      Liste aux = l;
      l=l->next;
      delete aux;
    }else
      supr_domino(l->next,domino_supr,n_to_supr,++n);
  }
}

void piocher(Liste & pioche, Liste & l){
  Domino d;
  int rdm = rand()%nb_dominos(pioche) +1;
  
  supr_domino(pioche,d,rdm,0);
  std::cout<<"Domino pioché : "<<d.x<<" "<<d.y<<std::endl;
  ajoute_gauche(l,d);
}

void genere_main(Liste & main, Liste & pioche, int n){
  for(int i = 0;i<n;++i){
    piocher(pioche,main);
  }
}

int nb_points(Liste & l){
  if(l==nullptr) return 0;
  else
    return nb_points(l->next) + l->domino.x + l->domino.y;
}

void retourne(Domino d){
  int aux = d.x;
  d.x=d.y;
  d.y=aux;
}

int aGauche(Liste l){
  if(l==nullptr) return -1;
  else
    return l->domino.x;
}

int aDroite(Liste l){
  if(l==nullptr) return -1;
  else{
    if(l->next == nullptr) return l->domino.y;
    else
      return aDroite(l->next);
  }
}

void jouer (Liste & m, Liste & j, bool & bloque){
  if(m==nullptr)
    bloque =  true;
  else{
    if(m->domino.x == aGauche(j)){
        retourne(m->domino);
        ajoute_gauche(j, m->domino);
        supprime_premier(m);
        
    }else if(m->domino.x == aDroite(j)){
      retourne(m->domino);
      ajoute_droite(j,m->domino);
      supprime_premier(m);
      
    }else if (m->domino.y == aGauche(j)){
      retourne(m->domino);
      ajoute_gauche(j, m->domino);
      supprime_premier(m);
      
    }else if(m->domino.y == aDroite(j)){
      retourne(m->domino);
      ajoute_droite(j, m->domino);
      supprime_premier(m);
      
    }else
      jouer(m->next,j,bloque);
  }
}
    

int main(){
  std::srand(time(nullptr));
  
  Liste main,pioche,jeu;
  bool bloque  = false;
  int tour = 0;

  init(pioche);init(main);init(jeu);
  init_pioche(pioche);

  //initialise le jeu (1 domino)&
  piocher(pioche,jeu);

  int n;
  std::cout<<"Combien voulez-vous de dominos dans votre main ? ";
  std::cin>>n;
  genere_main(main,pioche,n);

  while(nb_dominos(pioche)!=0){
    bloque = false;
    ++tour;
    
    std::cout<<std::endl<<"======= TOUR N° "<<tour<<" ==========="<<std::endl;
    std::cout<<"Jeu : ";
    aff_main(jeu);
    std::cout<<std::endl;
    
    std::cout<<"Main : ";
    aff_main(main);
    std::cout<<std::endl;

    
    jouer(main,jeu,bloque);
    if(bloque){
      std::cout<<"Le joueur doit piocher ! "<<std::endl;
      piocher(pioche,main);
    }
  }

  std::cout<<"Fin du jeu ! Nombre de points : "<<nb_points(main)<<std::endl;
  

  
  
  return 0;
}
