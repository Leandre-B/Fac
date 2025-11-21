#include <iostream>
#include <array>
#include <string>


const int NMAX = 100;
using tab  = std::array<int, NMAX>;

void saisie(tab & t, int n ){
    if(n==0) return;
    else{
        saisie(t,n-1);
        std::cout<<"Saisie case  "<<n<<" : ";
        std::cin>>t[n-1]; //appelle recursif en 1er : saisie a la remonté
    }
}

void aff(tab t, int n){
    if(n!=0){ //alternative a (if cas d'arret else aff)
        aff(t, n-1); //appelle recursif en 1er : affichage a la remonté
        std::cout<<"case "<<n<< " : " <<t[n-1]<<std::endl;
    }
}


bool appartient(tab t, int n, int nb){

    if(n==0) return false;
    else if(t[n-1]==nb) return true;
    else return appartient(t,n-1, nb);
}

int position(tab t, int n, int nb){

    if(n==0) return -1;
    else if(t[n-1]==nb) return (n);
    else return position(t,n-1, nb);
}

bool appartientDichoto(const tab & t, int d, int f, int nb){
    if(d>f) return false;
    else{
        int m = (d+f)/2;
        if(t[m]==nb) return true;
        else if(t[m]>nb) return appartientDichoto(t, 0, m-1,nb);
        else return appartientDichoto(t,m+1,f,nb);
    }
}

int positionDicho(const tab & t, int d, int f, int nb){
    if(d>f) return -1;
    else{
        int m = (d+f)/2;
        if(t[m]==nb) return m+1;
        else if(t[m]>nb) return positionDicho(t, 0, m-1,nb);
        else return positionDicho(t,m+1,f,nb);
    }
}

bool apparait(std::string str, unsigned int ind, char lettre){
    if(ind>=str.length()) return false;
    else if(str[ind]==lettre) return true;
    else return apparait(str, ++ind ,lettre);
}

void chercheChar(){
    std::string str="abcdefghijklmnopqrstuvwxyz";
    char lettre;
    unsigned int ind;

    std::cout<<"Donner un lettre a rechercher : ";
    std::cin>>lettre;

    std::cout<<"A partir de quel lettre voulez-vous rechercher cette lettre ? ";
    std::cin>>ind;
    if(apparait(str, ind-1, lettre))
        std::cout<<"\'"<<lettre<<"\' est dans \""<<str<<"\" a partir de la lettre num "<<ind<<std::endl;
    else
        std::cout<<"\'"<<lettre<<"\' "<<"\033["<<"31mn"<<
                  "\033[m"<<"\'est "<<
                  "\033["<<"31mpas"<<
                  "\033[m"<<
                  " dans \""<<str<<"\" a partir de la lettre num "<<ind<<std::endl;
}

void valTab(){
    int n;
    tab t;
    std::cout<<"Combien de valeur a saisir dans tab ? ";
    std::cin>>n;

    saisie(t,n);
    aff(t, n);

    int nb;
    std::cout<<"Quel nbr voulez vous rechercher ? ";
    std::cin>>nb;
    if( appartient(t, n, nb))
        std::cout<<nb<<" appartient au tableau."<<std::endl;
    else
        std::cout<<nb<<" n'appartient pas au tableau."<<std::endl;
    std::cout<<nb<<" est dans la case num "<<position(t,n,nb)<<std::endl;
}
int main(){

    // valTab();

    std::cout<<std::endl;

    chercheChar();

    return 0;
}
