#include <iostream>
#include <fstream>
#include <bitset>


std::string getFileContent(std::string file)
{

    std::ifstream fic(file);
    std::string ligne;
    std::string convertion;
    while(std::getline(fic, ligne))
        convertion+=ligne;
    return convertion;

}

std::string latin1ToUTF8(std::string file)
{

    std::ifstream fic(file, std::ios::binary);
    char c;
    std::string convertion = "";
    if(fic.is_open())
    {
        while(fic.good()){
            
            fic.get(c);
            if( (c & 0x80 ) != 0x80 ){
                convertion+=c;
            }else{
                convertion+= (0xC0 | ((c>>6)&0x03));
                convertion+= (c&0x3F) | 0x80;
                // std::cout<<std::bitset<8>(c)<<"\n";
                // std::cout<<std::bitset<8>(0xC0 | ((c>>6)&0x03))<<"\n";
                // std::cout<<std::bitset<8>((c&0x3F) | 0x80)<<"\n";
            }
        }
    }
    return convertion;

}


std::string UTF8ToLatin1(std::string file)
{

    std::ifstream fic(file, std::ios::binary);
    char c;
    std::string convertion = "";
    if(fic.is_open())
    {
        while(fic.good()){
            
            fic.get(c);
            if( (c & 0x80 ) != 0x80 ){
                convertion+=c;
            }else{
                // 1100
                if( (c & 0xC0) == 0xC0) {
                    //std::cout<<std::bitset<8>(c)<<"\n";
                    char conv = ((c&0x03) << 6);
                    fic.get(c);
                    //std::cout<<std::bitset<8>(c)<<"\n";
                    
                    conv |= ( c&0x3F );
                    //std::cout<<std::bitset<8>(conv)<<"\n";
                    
                    convertion += conv;
                }

                // 1110
                else if( (c & 0xE0) == 0xE0) {
                    for(int j=0 ; j<2; ++j){
                        fic.ignore();
                        convertion+='?';
                    }
                }

                // 1111
                else if( (c & 0xF0) == 0xF0) {
                    for(int j=0 ; j<3; ++j){
                        fic.ignore();
                        convertion+='?';
                    }
                }
            }
        }
    }
    return convertion;

}


int main(int argc, char **argv){

    if( argc != 4)
    {
        std::cerr<<"Wrong usage.\n";
        return 0;
    }
    if(argv[2] == "utf8" && argv[3] == "latin1")
        std::cout<<UTF8ToLatin1(argv[4]);
    else if(argv[2] == "latin1" && argv[3] == "utf8")
        std::cout<<latin1ToUTF8(argv[4]);
    else if(argv[2] == argv[3])
        std::cout<<getFileContent(argv[4]);
    std::cout<<UTF8ToLatin1("text.utf8-2.txt");


    return 0;
}