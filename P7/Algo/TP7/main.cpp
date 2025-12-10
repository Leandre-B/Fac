#include <iostream>
#include <fstream>

struct OccMot{
    std::string mot;
    uint occ=0;
};

struct Alveole{
    bool occupe=false;
    OccMot mot;
    int suiv=-1;
};

struct TabHachage{
    Alveole* alv;
    uint m;
    int pos_libre;
};

TabHachage initTabHachage(uint m){
    TabHachage t;
    t.m = m;
    int r = m*0.15;
    t.alv = new Alveole [r+m];
    t.pos_libre = (m+r) - 1;
    return t;
}

int fctBerstein(std::string mot, uint m){
    int h= 5381;
    for(int i=0; i<mot.length(); ++i)
        h = (33  * h + int(mot[i]))%m;
    return h;
}

void ajout(TabHachage & t, std::string mot){
    uint index = fctBerstein(mot, t.m);
    bool placed = false;
    while(!placed and t.pos_libre>=0){
        std::cout<<t.pos_libre<<"\n";
        if(t.alv[index].occupe)
        {
            if(t.alv[index].mot.mot==mot)
            {
                    ++t.alv[index].mot.occ;
                    placed = true;
            }
            else
            {
                if(t.alv[index].suiv==-1)
                {
                    t.alv[index].suiv = t.pos_libre;
                    index = t.pos_libre;
                    --t.pos_libre;
                    while(t.alv[t.pos_libre].occupe and t.pos_libre>=0)
                        --t.pos_libre;
                }
                else //si y'a un suivant
                {
                    index = t.alv[index].suiv;
                }

            }
        }
        else
        {
            t.alv[index].mot.mot = mot;
            t.alv[index].mot.occ = 1;
            t.alv[index].occupe = true;
            placed = true;
        }
    }
    if(t.pos_libre<0)
        std::cout<<"ERREUR : TABLE PLEINE !!!!\n";
}

uint nbOcc(TabHachage t, std::string mot){
    uint index = fctBerstein(mot, t.m);

    while(index!=-1){
        if(t.alv[index].mot.mot==mot)
            return t.alv[index].mot.occ;
        else{
            index = t.alv[index].suiv;
        }

    }
    return -1;
}

void information(TabHachage t){
    for(int i=0; i<t.m; ++i)
        if(t.alv[i].occupe)
            std::cout<<i<<" : "<<t.alv[i].mot.mot<<" "<<nbOcc(t, t.alv[i].mot.mot)<<"\n";

    float m = t.m;
    uint n_primaire_occ=0;
    for(int i=0; i<m/1.15; ++i)
        if(t.alv[i].occupe)
            ++n_primaire_occ;

    uint n_reserve_occ=0;
    for(int i=m/1.15; i<m; ++i)
        if(t.alv[i].occupe)
            ++n_reserve_occ;

    uint max = 0;
    uint cur = 0;
    for(int i=0; i<m; ++i){
        if(t.alv[i].occupe)
            ++cur;
        else{
            if(cur>max)
                max = cur;
            cur = 0;
        }
    }
    std::cout<<"Taille du plus grand paquet : "<<max<<" \n";
    std::cout<<"Zone primaire remplie a : "<<(n_primaire_occ/(m/1.15))*100<<"%\n";
    std::cout<<"Reserve remplie a : "<<(n_reserve_occ/(m-m/1.15))*100<<"%\n";
    std::cout<<"Table remplie a : "<<((n_reserve_occ+n_primaire_occ)/m)*100<<"%\n";
}

int main(){
    TabHachage t = initTabHachage(10000);

    std::ifstream fic;
    fic.open("bouledesuif.txt");
    std::string mot;
    while(fic>>mot){
        //std::cout<<mot<<std::end;
        ajout(t, mot);
    }
    information(t);


    return 0;
}
