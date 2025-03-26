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
  if(n!=0){
    aff(t,n-1);
    std::cout<<t[n]<<" ";
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

void selection_sort(int* t, int n){
  for(int i = 0;i<n;++n){
    max=ind_max(t,n-i);
    echange(t[i],t[max]);
//pas test a finir !!!!!
    


int main(){
  std::srand(time(NULL));

  int n = 100;
  int* t = new int[n];
  randomise(t,n);
  aff(t,n);
  std::cout<<std::endl;
  //int imax =ind_max(t,n);
  //std::cout<<"t["<<imax<<"] = "<<t[imax]<<std::endl;
  
  
}
