#include <string>
#include <iostream>


void sameLength(std::string & nb1, std::string & nb2){
    if(nb1.length()>nb2.length()){
        for(unsigned int i = 0;i<=(nb1.length()-nb2.length());++i){
            nb2="0"+nb2;
        }
    }
    else{
        for(unsigned int i = 0;i<=(nb2.length()-nb1.length());++i){
            nb1="0"+nb1;
        }
    }
}



void add(std::string nb1, std::string nb2,std::string & nb3){
    nb3="";
    char retenue = '0';
    if(nb1.length()!=nb2.length())
        sameLength(nb1,nb2);

    for(int i = nb1.length()-1;i>=0;--i){
        if(48+(int(nb1[i])-48 + int(nb2[i])-48 + int(retenue)-48)>57){
            nb3=char(( 48+(int(nb1[i])-48 + int(nb2[i])-48 +int(retenue)-48) )%58 + 48) +nb3;
            retenue='1';

        }
        else{
            nb3=char(48+(int(nb1[i])-48 + int(nb2[i])-48 + int(retenue)-48))+nb3;
            retenue='0';

        }
        if(i==0 and retenue=='1')
            nb3="1"+nb3;
    }
}

int main(){
    std::string nb1,nb2,nb3;
    std::cout<<"Entrez les nbrs a additionner : ";
    std::cin>>nb1>>nb2;
    add(nb1,nb2,nb3);
    std::cout<<nb1<<" + "<<nb2<<" = "<<nb3;

}
