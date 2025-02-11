#include <iostream>
#include <string>
#include <cmath>

std::string extrait (std::string e, int pos, int lg){
    if(lg<0) return "";
    else return(extrait(e,pos,lg-1)+e[pos+lg-1]);
}

bool est_signe(char c){
    bool signe=false;

    if(c=='+' or c=='-' or c=='*' or c=='/')
        signe = true;
    return signe;
}

bool est_chiffre (char c){

    bool chiffre=false;
    int i = 0;
    while(i<10 and chiffre!=true){
        if(static_cast<int>(c)-48==i)
            chiffre = true;
        ++i;
    }
    return chiffre;
}

int parent_ouvertes (std::string e){
    //std::cout<<"string : "<<e<<std::endl;
    if(e.length()<=0)
        return 0;
    else{
        if(e[e.length()-1]=='(') return parent_ouvertes(extrait(e,1,e.length()-2)) +1;
        if(e[e.length()-1]==')') return parent_ouvertes(extrait(e,1,e.length()-2)) -1;
        else return parent_ouvertes(extrait(e,1,e.length()-2));
    }

}

int cherchesigneMult(std::string e, unsigned int pos){

    if(pos>=e.length())
        return -1;
    else{
        if(parent_ouvertes (extrait(e,1,pos))==0)
            if(e[pos]=='/' or e[pos]=='*' or e [pos]=='%')
                return pos+1;
        return cherchesigneMult(e,pos+1);
    }
}

int cherchesigne(std::string e, unsigned int pos){

    if(pos>=e.length())
        return cherchesigneMult(e,0);
    else{
        if(parent_ouvertes (extrait(e,1,pos))==0)
            if(e[pos]=='-' or e[pos]=='+')
                return pos+1;
        return cherchesigne(e,pos+1);
    }
}

int num(char c){
    return int(c)-48;
}


int puiss(int nb,int p){
    if(p==0) return 1;
    else return nb*puiss(nb,p-1);
}


int convertit (std::string n, int ind){
    if(ind==1)
        return num(n[ind-1])*puiss(10,n.length());
    else return (convertit(n,ind-1)+ num(n[ind-1])*puiss(10,n.length()-ind-1));
}

int main(){

    std::string e = "45/(5+4)*23";
    // std::cout<<extrait(e,0,4)<<std::endl; //-1 sur lg car e[pos] compris
    //std::cout<<est_signe('5')<<est_signe('/')<<est_chiffre('5')<<est_chiffre('t');
    // std::cout<<"Signe add prio : "<<cherchesigne(e,0)<<std::endl;
    std::cout<<convertit("123",3)<<std::endl;



    return 0;
}
