#include <iostream>
#include <ctime>
#include <cmath>



void randomise(int* t,int n){
  if(n!=0){
    t[n-1]=std::rand()%100;
    randomise(t,n-1);
  }
}

void aff(int* t,int n){
  if(n>0){
    aff(t,n-1);
    std::cout<<t[n-1]<<" ";
  }
}

int ind_max(int* t, int n){
  if(n==0) return n;
  else{
    int imax=ind_max(t,n-1);
    if(t[n]>t[imax])
      return n;
    else
      return imax;
    }
}

void echange(int & a, int & b){
  int aux = a;
  a=b;
  b=aux;
}

void selection_sort(int* & t, int n){
  for(int i = 0;i<n;++i){
    int maxi=ind_max(t,n-i);
    echange(t[n-i],t[maxi]);
  }
}

void inserer(int* & t,int x,int n){
  int j =n;
  while((t[j-1])>x and j>=0){
    t[j]=t[j-1];
    --j;
  }
  t[j]=x;
}


void insertion_sort(int* & t, int n){
  for(int i = 1; i<n; ++i){
    inserer(t,t[i],i);
  }
}

int main(){
  std::srand(time(NULL));

  int n = 100;
  int* t = new int[n];
  randomise(t,n);
  aff(t,n); std::cout<<std::endl;
  /*
  std::cout<<std::endl<<"Selection sort : "<<std::endl;
  selection_sort(t,n);
  aff(t,n);std::cout<<std::endl<<std::endl;
  */
  std::cout<<std::endl<<"Insertion sort : "<<std::endl;
  insertion_sort(t,n);
  aff(t,n);std::cout<<std::endl<<std::endl;
  
  
}
