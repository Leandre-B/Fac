#include <string>
#include <iostream>

int nb_occ(std::string s, int p,char c){
    if(p==0) return 0;
    else if(s[p-1]!=c) return 0;
    else return nb_occ(s,p-1,c)+1;
}

std::string rl(std::string s, int ind){
    if(ind<0) return "";
    else{
        return rl(s,ind-nb_occ(s,ind+1,s[ind])) +
               std::to_string(nb_occ(s,ind+1,s[ind]))+s[ind];
               }
}

std::string suiteCn(int n){
    if(n==0) return "1";
    else return rl(suiteCn(n-1),suiteCn(n-1).length());
}

int main(){
    for(int n = 0;n<=10;++n){
        std::cout<<"Cn(n="<<n<<") = "<<suiteCn(n)<<std::endl;
    }
}
