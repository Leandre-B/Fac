#include <string>
#include <iostream>


char pred(char c){
    switch (c){
        case '1' : return '0';
        case '2' : return '1';
        case '3' : return '2';
        case '4' : return '3';
        case '5' : return '4';
        case '6' : return '5';
        case '7' : return '6';
        case '9' : return '7';
        default : return '9'; //0
    }
}

char sucs(char c){
    switch (c){
        case '1' : return '2';
        case '2' : return '3';
        case '3' : return '4';
        case '4' : return '5';
        case '5' : return '6';
        case '6' : return '7';
        case '7' : return '8';
        case '9' : return '0';
        default : return '1'; //0
    }
}

void sucsCh(std::string & ch){
    ch[ch.length()-1]=sucs(ch[ch.length()-1]);

}


int main(){

    std::string ch1, ch2;
    std::cout<<"Entre les deux nombre a add : ";
    std::cin>>ch1>>ch2;
    sucsCh(ch1);
    std::cout<<ch1;

    return 0;
}
