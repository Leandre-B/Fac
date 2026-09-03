#include <iostream>
#include <fstream>

// DOM ?


int main(int argc, char **argv) {
    if(argc == 1)
    {   
        std::cout<<"Need at least 1 argument\n.";
        return 0;
    }

    for(int i=1; i<argc; ++i) {
        std::ifstream fic(argv[i], std::ios::binary);
        char c;
        if(fic.is_open())
        {
            bool isUTF8 = false;
            bool isLatin1 = false;
            while(fic.good() && !isLatin1)
            {
                fic.get(c);
                // si le 1er bit est à 1 -> pas ascii
                if((c & 0x80) == 0x80){
                    // Get current cursor position
                    
                    // On regarde le bit suivant pour déterminer si UTF-8
                    char next_c;

                    // 1100
                    if( (c & 0xC0) == 0xC0) {    
                        fic.get(next_c);
                        if( (next_c & 0xC0) == 0x80 )
                            isUTF8 = true;
                        else
                            isLatin1 = true;
                    }

                    // 1110
                    else if( (c & 0xE0) == 0xE0) {
                        for(int j=0 && !isLatin1; j<2; ++j){
                            fic.get(next_c);
                            if( (next_c & 0xC0) == 0x80 )
                                isUTF8 = true;
                            else
                                isLatin1 = true;
                        }
                    }

                    // 1111
                    else if( (c & 0xF0) == 0xF0) {
                        for(int j=0 && !isLatin1; j<3; ++j){
                            fic.get(next_c);
                            if( (next_c & 0xC0) == 0x80 )
                                isUTF8 = true;
                            else
                                isLatin1 = true;
                        }
                    }
                    else
                        isLatin1 = true;

                }
            }
            if(isLatin1)
                std::cout<<argv[i]<<" est en LATIN1\n";
            else if(isUTF8)
                std::cout<<argv[i]<<" est en UTF8\n";
            else
                std::cout<<argv[i]<<" est en ASCII\n";
        }else
        {
            std::cerr<<"Can't open file \""<<argv[i]<<"\"\n";
        }
    }

    return 0;
}