#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>
const int NMAX =9;
void aff(std::array<int,NMAX> t, int n){
	if(n>0){
		aff(t,n-1);
		std::cout<<t[n-1]<<" ";
	}
}

void suffle(std::array<int,NMAX> & t,int n){
	for(int i = n-1;i>=0;--i){
		int rdm=std::rand()%n;
		int aux=t[rdm];
		t[rdm]=t[i];
		t[i]=aux;
	}
}

bool is_sorted(std::array<int,NMAX> t, int n){
	for(int i = 0;i<n-1;++i){
		if(t[i]>t[i+1])
			return false;
	}
	return true;
}


long unsigned int bongo_sort(std::array<int,NMAX> t, int n){
	long unsigned int nb=0;
	while(!is_sorted(t,n)){
		suffle(t,n);
		//aff(t,n);
		//std::cout<<std::endl;
		++nb;
	}
	//std::cout<<nb<<std::endl;
	return nb;
}

int main(){
	std::srand(time(nullptr));
	int n=NMAX;
	std::array<int,NMAX> rdm_tab;
	for (int i = 0;i<n;++i){
		rdm_tab[i]=std::rand()%(n*10);
	}
	aff(rdm_tab,n);
	std::cout<<std::endl;
	long unsigned int moy=0;
	int nb_genere=10000;
	for(int i=0;i<nb_genere;++i){
		moy+=bongo_sort(rdm_tab,n);
	}
	std::cout<<NMAX<<"! = "<<moy/nb_genere<<std::endl;
	//aff(rdm_tab,n);
	//std::cout<<std::endl;

}
	
