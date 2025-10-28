//File de chaine de char
//représenter grâce un a string



#include <iostream>
#include <string>

class FileChar{
    public :
        std::string file; 
        FileChar(){
            file = "";
        }

        bool estVide(){
            return file=="";
        }

        char consulter(){
            if(!estVide())
                return file.front();
            else{
                return '?';
                std::cout<<"File vide, return \'?\'\n";
            }
        }

        void ajouter(const char & c){
            file=c+file;
        }

        void retirer(){
            file.pop_back();
        }

        void afficher(){
            for(int i=file.length(); i>=0; --i){
                std::cout<<file[i];
            }
        }
};