#include <iostream>
#include <string>

int charEnt(char c){
    switch (c){
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
    }
    return -1;
}

char entChar(int n){
    switch (n){
        case 0 : return '0';
        case 1 : return '1';
        case 2 : return '2';
        case 3 : return '3';
        case 4 : return '4';
        case 5 : return '5';
        case 6 : return '6';
        case 7 : return '7';
        case 8 : return '8';
        case 9 : return '9';
    }
    return 'N';
}

int chEnt(std::string ch){
    int ent=0;
    int posNum;
    unsigned int i =0;
    if(ch[0]=='-'){
        i=1;
    }
    for(i;i<ch.length();++i){
        posNum=1;
        for(unsigned int j = 1;j<ch.length()-i;++j )
            posNum*=10;
        ent += charEnt(ch[i]) * posNum;
    }
    if(ch[0]=='-'){
        return -ent;
    }
    return ent;
}

std::string entCh(int n){
    std::string ch="";
    int posNum=1;
    int k =0;
    bool neg = false;
    if(n<0){
        n=-n;
        neg=true;
    }
    //nb de chiffre dans n
    while((n/posNum)!=0){
        ++k;
        posNum*=10;
    }
    for(int i = 0;i<k;++i){
        posNum=1;
        for(int j = 1;j<k-i;++j)
            posNum*=10;
        ch+= entChar((n%(posNum*10))/posNum);
    }

    if(neg)
        ch="-" + ch;
    return ch;
}

std::string entCh2(int n){
    int quotient;
    std::string ch="";

    bool neg = false;
    if(n<0){
        n=-n;
        neg=true;
    }

    quotient = n/10;
    while(quotient!=0){
        ch = entChar(n%10) + ch;
        n = quotient;
        quotient = n/10;
    }
    ch = entChar(n%10)+ch;
    if(neg)
        ch="-" + ch;
    return ch;
}

int main(){
    std::string ch;
    int n;
    // std::cout<<"Entrez une chaine de nombre : ";
    // std::cin>>ch;
    // std::cout<<ch<<" en int = "<<chEnt(ch)<<std::endl;

    std::cout<<"Entrez un nb entier : ";
    std::cin>>n;
    std::cout<<n<<" en chaine de car = "<<entCh2(n);

}
