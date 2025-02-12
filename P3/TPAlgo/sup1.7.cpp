#include <iostream>
#include <string>
#include <cmath>

std::string extrait (std::string e, int pos, int lg){
    if(lg<1) return "";
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
        if(e[e.length()-1]=='(') return parent_ouvertes(extrait(e,0,e.length()-1)) +1;
        if(e[e.length()-1]==')') return parent_ouvertes(extrait(e,0,e.length()-1)) -1;
        else return parent_ouvertes(extrait(e,0,e.length()-1));
    }

}

int cherchesigneMult(std::string e, unsigned int pos){

    if(pos>e.length())
        return -1;
    else{
        if(parent_ouvertes (extrait(e,0,pos+1))==0)
            if(e[pos]=='/' or e[pos]=='*' or e [pos]=='%')
                return pos;
        return cherchesigneMult(e,pos+1);
    }
}

int cherchesigne(std::string e, unsigned int pos){

    if(pos>e.length())
        return cherchesigneMult(e,0);
    else{
        if(parent_ouvertes (extrait(e,0,pos+1))==0)
            if(e[pos]=='-' or e[pos]=='+')
                return pos;
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


int convertit (std::string n, int nb){
    if(nb==1){
        return num(n[nb-1])*puiss(10,n.length()-nb);
    }
    else return (convertit(n,nb-1)+ num(n[nb-1])*puiss(10,n.length()-nb));
}


int calcule (int g, char signe, int d){
        switch (signe){
            case '+' : return g + d;
            case '-' : return g - d;
            case '*' : return g * d;
            case '/' : return g / d;
            case '%' : return g % d;
            default : return 0;
        }
}

int evalue (std::string e){
    if(e[0]=='(' and e[e.length()-1]==')')
        return evalue(extrait(e,1,e.length()-2));
    else{
        int posSigne = cherchesigne(e,0);
        if(posSigne!=-1){
            std::string g=extrait(e,0,posSigne);
            std::string d=extrait(e,posSigne+1,e.length()-posSigne-1);
            std::cout<<"signe : "<<e[posSigne]<<" | g="<<g<<" | d="<<d<<std::endl;
            return calcule(evalue(g),e[posSigne],evalue(d));
        }
        else{
            int e_conv = convertit(e,e.length());
            // std::cout<<"e.length : "<<e.length()<<" | str : \""<<e<<"\" = int :"<<e_conv<<std::endl;
            // std::cout<<"Dernier char de la chaine \""<<e<<"\" : "<<e[e.length()-1]<<std::endl;
            return e_conv;
        }
    }
}

int main(){

    std::string e = "5+(1+4)+1+(3-4)";
    // std::cout<<extrait(e,0,3)<<std::endl;
    //std::cout<<est_signe('5')<<est_signe('/')<<est_chiffre('5')<<est_chiffre('t');
    // std::cout<<"Signe prio : "<<cherchesigne(e,0)<<std::endl;
    std::cout<<e<<" = "<<std::endl<<evalue(e)<<std::endl;



    return 0;
}
