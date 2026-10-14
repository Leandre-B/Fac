#include <iostream>
#include <string>

int nbVoyelles(const std::string & s) {
    int cpt = 0;
    std::string voyelles = "aeiouyAEIOUY";
    for(char c : s)
        for(char v : voyelles) {
            if(c == v){
                cpt++;
                break;
            }
        }

    return cpt;
}

bool estPalindrome(const std::string & s) {
    for(int i = 0; i<s.size() / 2; ++i) {
        if(s[i] != s[s.size() -1 -i])
            return false;
    }
    return true;
}

std::string chiffrer(const std::string & s, int d) {
    std::string s_chiffre;

    for(char c : s ){
        if( c >= 'a' && c<= 'z') {
            s_chiffre += (c - 'a' +  d) % 26 + 'a';
        }
        else if( c >= 'A' && c<= 'Z') {
            s_chiffre += (c - 'A' +  d) % 26 + 'A';
        }
        else
            s_chiffre += c;
    }
    return s_chiffre;
}

unsigned int chaineVersEntier(const std::string & s) {
    unsigned int nb = 0;
    unsigned int factor = 1;
    for(unsigned int i = s.size(); i>0 ; --i) {
        if(s[i-1] < '0' || s[i-1] > '9') {
            return 0;
        }
        nb += (s[i-1] - '0') * factor;
        factor*=10;
    }
    return nb;
}

int main(){
    std::cout<<nbVoyelles("ajznfaijfnkca")<<"\n";
    std::cout<<estPalindrome("a")<<"\n";
    std::cout<<chiffrer("a", 9128390)<<"\n";
    std::cout<<chaineVersEntier("11232")<<"\n";
    return 0;
}