#include <iostream>
#include <cmath>
#include <ctime>

void init(int* & t, int n){
  if(n>0){
    t[n-1]= std::rand()%5;
    init(t,n-1);
  }
}

void aff(int* t, int n){
  if(n>0){
    aff(t,n-1);
    std::cout<<" "<<t[n-1];
  }
}

void echange(int & a, int & b){
  int aux = a;
  a=b;
  b=aux;
}

//==== Méthode 'partition' du quick sort ====
void move_zeros1(int* & t, int n){
  int j=0;
  //boucle while pour passer les zeros au debut
  for(int i = 0;i<n;++i){
    if(t[i]==0){
      //pas besoin d'échange, tu sais que tu vas mettre un zero
      
      int aux = t[i];
      t[i]=t[j];
      t[j]=aux;

      ++j;
    }
  }
  std::cout<<"Nombre de zeros : "<<j<<std::endl;
}

//==== Creation d'un nouveau tableau ====
void move_zeros2(int* & t, int n){
  int* t2 = new int [n];
  int j=0,k=0;
  for(int i = 0;i<n;++i){
    if(t[i]==0){
      t2[j]=0;
      ++j;
    }else{
      t2[n-1-k]=t[i];
      ++k;
    }
  }
  std::cout<<"Nombre de zeros : "<<j<<std::endl;
  t=t2;
}

//==== Type bubble sort mdr ===
void move_zeros3(int* & t,int n){
  int k = 0;
  for(int i = n-1;i>0;--i){
    if(t[i]==0) ++k;
    for(int j = n-1;j>0;--j){
      if(t[j]==0){
        echange(t[j],t[j-1]);
      }
    }
  }  
  std::cout<<"Nombre de zeros : "<<k<<std::endl;
}

/*
  Avec une liste : 
  Dès qu'on trouve un zero,
  on stocke le maillon
  on le supprime en racrohant les maillons avant et après
  on le racroche au début de la liste
*/
  

int main(){
  std::srand(time(nullptr));
  int n = 100;
  int* t = new int [n];
  init(t,n);
  t[n-1]=0;
  t[0]=0;
  aff(t,n);
  std::cout<<std::endl;
  
  move_zeros1(t,n);
  aff(t,n);
  std::cout<<std::endl;

}
