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


void tri_casier(int* & t,int n,int max_val){
	int* t_occ = new int[max_val];

	//init t_occ
	for(int i = 0;i<max_val;++i)
		t_occ[i]=0;

	//remplie t_occ
	for(int i = 0;i<n;++i)
		++t_occ[t[i]];
		
	//on refait le tab t trié
	//bref, je vois bien comment ça fonctionne mdr
	int ind=0;
	for(int i = 0;i<max_val;++i){
		for(int j=0;j<t_occ[i];++j){
			t[ind]=i;
			++ind;
		}
	}
}
	

int main(){
	std::srand(time(NULL));

	int max_val=50;
	int n = 100;
	int* t = new int[n];
	randomise(t,n,max_val);
	aff(t,n);std::cout<<std::endl<<std::endl;

	tri_casier(t,n,max_val);
	aff(t,n);std::cout<<std::endl<<std::endl;
}
