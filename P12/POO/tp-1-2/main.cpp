#include <iostream>
#include <string>

int nbVoyelles(const std::string & s) {
    std::string voyelles = "aeiuoyAEIUOY";
    int cpt = 0;
    for(char c : s)
        for(char v : voyelles ) {
            cpt += (c == v);
        }
    return cpt;
}

bool est_palindrome(const std::string & s1, const std::string & s2) {
    if(s1.size() != s2.size()) return false;
    for(unsigned int i=0; i<s1.size()/2; ++i)
        if(s1[i] != s2[s2.size() -1 - i]) return false;
    return true;
}

std::string chiffre(const std::string & s, int d) {
    std::string s_chiffrer;
    for(char c : s) {
        if(c>=65 && c<=90) {
            s_chiffrer+=((c-65+d)%26 + 65);
        }
        else if(c>=97 && c<=122) {
            s_chiffrer+=((c-97+d)%26 + 97);
        }else
            s_chiffrer += c;
    }
    return s_chiffrer;
}

std::string dechiffrer(const std::string & s, int d) {
    std::string s_dechiffrer;
    for(char c : s) {
        if(c>=65 && c<=90) {
            s_dechiffrer+=((c-65-d)%26 + 65);
        }
        else if(c>=97 && c<=122) {
            s_dechiffrer+=((c-97-d)%26 + 97);
        }else
            s_dechiffrer += c;
    }
    return s_dechiffrer;
}

int main() {

    std::cout<<nbVoyelles("azuirhaifnaoefn")<<"\n";
    std::cout<<est_palindrome("azerty", "ytreza")<<"\n";
    std::cout<<chiffre("abCdeF&.0", 4)<<"\n";
    std::cout<<dechiffrer("efGhiJ&.0", 4)<<"\n";
    return 0;
}
