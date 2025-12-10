#include <iostream>
#include <cmath>
#include <ctime>
#include <cmath>
#include <chrono>


bool isSorted(int * t, uint n){
    for(uint i=0; i<n-1; ++i)
        if(t[i]>t[i+1])
            return false;
    return true;
}
void randomize(int* & t, uint n){
    for(uint i=0; i<n; ++i)
        t[i] = std::rand()%10000000;
}

void affiche(int* & t, uint n){
    for(uint i=0; i<n; ++i)
        std::cout<<t[i]<<" ";
    std::cout<<"\n";
}

void echange(int & a, int & b){
  int aux = a;
  a=b;
  b=aux;
}

//====== quick sort =========
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
//===============


//====== Insertion Sort =========
void inserer(int* & t,int x,int n){
  int j =n;
  while((t[j-1])>x and j>=0){
    t[j]=t[j-1];
    --j;
  }
  t[j]=x;
}


void insertion_sort(int* & t, int d, int f){
  for(int i = d+1; i<f; ++i){
    inserer(t,t[i],i);
  }
}

//====== HEAP / TAS =========
//tri par tas, de i a n incluent !!
void tamisage(int* & t, int i, int n, int offset){
    int f=2*i +1 ;
    while(f<=n){
        if(f<n and t[f+offset+1]>t[f+offset])
            ++f;
        if(t[f+offset]>t[i+offset]){
            echange(t[f+offset], t[i+offset]);
            i=f;
            f=2*i +1;
        }else
            f=n+1;
    }
}
void heap_sort(int* & t, int d, int f){
    for(int i=(f-d)/2 -1; i>=0; --i){
        tamisage(t, i, (f-d), d);
    }
    for(int i=(f-d)-1; i>=1; --i){
        echange(t[d],t[i+d]);
        tamisage(t,0, i-1, d);
    }
}
//===============


//======= introsort ========

void introsort_bis(int* & t,int d,int f, int prof_recur, int t_tab){
    if(f-d > 15){
        if(prof_recur>2*std::log(t_tab))
            heap_sort(t, d, f+1);
        else{
            if(f-d>0){
                int ind_p = partitionnement(t,d,f);
                introsort_bis(t,d, ind_p-1, prof_recur+1, t_tab);
                introsort_bis(t,ind_p+1,f, prof_recur+1, t_tab);
            }
        }
    }else
        insertion_sort(t, d, f+1);
}

void introsort(int* & t,int n){
  introsort_bis(t,0,n, 0, n);
}
//===============


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
for(int i = 1024; i<=10000000000; i*=2){
    std::cout<<"Taille = "<<i<<std::endl;

    int* t = new int[i];
    randomize(t,i);

    int* t_copie  = new int[i];

    copie(t,t_copie,i);
    std::cout<<"introsort sort :"<<std::endl;
    std::chrono::time_point moment_debut = std::chrono::system_clock::now();
    introsort(t_copie, i);
    std::chrono::time_point moment_fin = std::chrono::system_clock::now();
    std::cout<< std::chrono::duration<float>(moment_fin - moment_debut).count() <<"s\n";

    copie(t,t_copie,i);
    std::cout<<"quick_sort :"<<std::endl;
    moment_debut = std::chrono::system_clock::now();
    //quick_sort(t_copie, i);
    moment_fin = std::chrono::system_clock::now();
    std::cout<< std::chrono::duration<float>(moment_fin - moment_debut).count() <<"s\n";


    delete t_copie;
    std::cout<<std::endl;

    }
}


int main(){
    srand(1);
    compare_tri();
    // int n=10;
    // int* t = new int [n];
    // randomize(t, n);
    // affiche(t, n);
    // heap_sort(t, 3, n);
    // affiche(t, n);
    return 0;
}
