#include <iostream>
#include <ctime>
#include <cmath>
#include <chrono>

//======= Fonction annexes randomise, aff, echange======

void randomise(int* t,int n){
  if(n!=0){
    t[n-1]=std::rand()%100;
    randomise(t,n-1);
  }
}

void randomise_cap(int* t,int n,int max_val){
  if(n!=0){
    t[n-1]=std::rand()%max_val;
    randomise_cap(t,n-1,max_val);
  }
}

void aff(int* t,int n){
  if(n>0){
    aff(t,n-1);
    std::cout<<t[n-1]<<" ";
  }
}

void echange(int & a, int & b){
  int aux = a;
  a=b;
  b=aux;
}


//==============Selection Sort============

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

void selection_sort(int* & t, int n){
  for(int i = 0;i<n;++i){
    int maxi=ind_max(t,n-i);
    echange(t[n-i],t[maxi]);
  }
}


//==================Insertion Sort ======================

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
//======= Tri Casier=======
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

//============Quick Sort=============

int partitionnement(int* & t, int d, int f){
  int p = t[f]; //pivot = dernier elem de la liste a partionner
  //j = indice d'elem juste après la partie bien partionnée
  int j = d;
  for(int i = d;i<f;++i){
    if(t[i]<p){
      echange(t[i],t[j]);
      ++j;
    }
  }
  //on met le pivot a sa bonne place
  echange(t[j],t[f]);
  
  //j = indice du pivot
  return j;
}
    

void quick_sort_bis(int* & t,int d,int f){
  if(f-d>0){
    int ind_p = partitionnement(t,d,f);
    quick_sort_bis(t,d, ind_p-1);
    quick_sort_bis(t,ind_p+1,f);
  }
}


void quick_sort(int* & t,int n){
  quick_sort_bis(t,0,n);
}
  

//======= Calcul temps tri=====
float temps_tri(int* & t, int n,void(*f)(int*&,int)){
  std::chrono::time_point moment_debut = std::chrono::system_clock::now();
  f(t,n);
  std::chrono::time_point moment_fin = std::chrono::system_clock::now();
  return std::chrono::duration<float>(moment_fin - moment_debut).count();
 }

//======Copie==========
void copie (int* const & t, int* & copie,int n){
  for(int i = 0;i<n;++i)
    copie[i]=t[i];
}

//=======Compare tri============
void compare_tri(){
  for(int i = 100000;i<=1000000;i+=1000){
    std::cout<<"Taille = "<<i<<std::endl;
    
    int* t = new int[i];
    //randomise(t,i);
    int max_val=500000;
    randomise_cap(t,i,max_val);
    
    int* t_copie  = new int[i];

//    if(i<=30000){
//      copie(t,t_copie,i);
//      std::cout<<"Selection sort :"<<temps_tri(t_copie,i,&selection_sort)<<"s"<<std::endl;
//    }
//    
//    copie(t,t_copie,i);
//    std::cout<<"Insertion sort :"<<temps_tri(t_copie,i,&insertion_sort)<<"s"<<std::endl;
//
    copie(t,t_copie,i);
    
    std::chrono::time_point moment_debut = std::chrono::system_clock::now();
    tri_casier(t,i,max_val);
    std::chrono::time_point moment_fin = std::chrono::system_clock::now();
    auto temps= std::chrono::duration<float>(moment_fin - moment_debut).count();
    std::cout<<"Tri casier :"<<temps<<"s"<<std::endl;
    
    delete t_copie;
    std::cout<<std::endl;
    
  }
}

int main(){
	std::srand(time(NULL));

	compare_tri();
}

