#include <iostream>
#include <ctime>
#include <cmath>


void randomise(int* t,int n,int max_val){
  if(n!=0){
    t[n-1]=std::rand()%max_val;
    randomise(t,n-1,max_val);
  }
}

void aff(int* t,int n){
  if(n>0){
    aff(t,n-1);
    std::cout<<t[n-1]<<" ";
  }
}

void quick_sort_bis(int* & t,int debut,int fin){
  
}


void quick_sort(int* & t,int n){
  quick_sort_bis(t,0,n);
}
  



int main(){
	std::srand(time(NULL));

	//int max_val=50;
	int n = 100;
	int* t = new int[n];
	randomise(t,n,max_val);
	aff(t,n);std::cout<<std::endl<<std::endl;

	quick_sort(t,n);
	aff(t,n);std::cout<<std::endl<<std::endl;
}

