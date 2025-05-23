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
	int nbAffect = 0;
	
	//init t_occ
	for(int i = 0;i<max_val;++i)
		t_occ[i]=0;
	nbAffect+=max_val;
	
	//remplie t_occ
	for(int i = 0;i<n;++i)
		++t_occ[t[i]];
	nbAffect+=n;
	
	//on refait le tab t bien trié
	//bref, je vois bien comment ça fonctionne mdr
	int ind=0;
	for(int i = 0;i<max_val;++i){
		for(int j=0;j<t_occ[i];++j){
			t[ind]=i;
			++ind;
			++nbAffect;
		}
	}
	std::cout<<"Nombre d'ope sur des tableaux : "<<nbAffect<<std::endl;
}
	

int main(){
	std::srand(time(NULL));

	int k=310000003;
	int n = 100;
	int* t = new int[n];
	randomise(t,n,k);
	aff(t,n);std::cout<<std::endl<<std::endl;

	tri_casier(t,n,k);
	aff(t,n);std::cout<<std::endl<<std::endl;
}
