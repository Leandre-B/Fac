#include <iostream>
#include <array>
#include <fstream>

struct Date{
    int an;
    int mois;
    int jour;
};

struct Maillon{
    Date date;
    Maillon* suiv;
};

using ListeDate = Maillon*;

using Tirage = std::array<int, 5>;

struct Noeud{
    Tirage tirage;
    ListeDate l_dates;

    Noeud* sag;
    Noeud* sad;
};

using Historique = Noeud*;

void afficheDate(Date date){
    std::cout<<date.jour<<"\\"<<date.mois<<"\\"<<date.an;
}

void afficheListeDate(ListeDate l_date){
    if(l_date!=nullptr){
        afficheDate(l_date->date);
        afficheListeDate(l_date->suiv);
    }
}

void initListeDate(ListeDate & l_date){
    l_date = nullptr;
}

void initHistorique(Historique & h){
    h=nullptr;
}

int ordreDate(Date d1, Date d2){
    int ordre = 0;
    if(d1.an<d2.an)
        ordre = -1;
    else if(d1.an>d2.an)
        ordre = 1;
    else{
        if(d1.mois<d2.mois)
            ordre = -1;
        else if(d1.mois>d2.mois)
            ordre = 1;
        else{
            if(d1.jour<d2.jour)
                ordre = -1;
            else if(d1.jour>d2.jour)
                ordre = 1;
        }
    }
    return ordre;
}

int ordreTirage(Tirage t1, Tirage t2){
    int fact = 1;
    for(int i=0; i<5; ++i){
        if(t1[i]<t2[i])
            return -1;
        if(t1[i]>t2[i])
            return 1;
    }
    return 0;
}

void ajoutDate(ListeDate & l, Date d){
    if(l==nullptr){
        l = new Maillon;
        l->date = d;
        l->suiv = nullptr;
    }
    else if(ordreDate(l->date, d)!=0)
    {
        if(ordreDate(l->date, d)==1){ //l->date < d
            Maillon* m = new Maillon;
            m->date = d;
            m->suiv = l;
            l=m;
        }else
            ajoutDate(l->suiv, d);
    }
}


void ajoutTirage(Historique & h, Tirage t, Date d){
    if(h==nullptr){
        h = new Noeud;
        h->tirage = t;
        initListeDate(h->l_dates);
        ajoutDate(h->l_dates, d);
        h->sag = nullptr;
        h->sad = nullptr;
    }else{
        if(ordreTirage(t, h->tirage)==-1) //si t < h->tirage
            ajoutTirage(h->sag, t, d);
        else if(ordreTirage(t, h->tirage)==1)
            ajoutTirage(h->sad, t, d);
        else //meme tirage
            ajoutDate(h->l_dates, d);
    }
}

void memoriseHistorique(Historique & h,  std::string nom_fichier){
    std::ifstream fic;
    fic.open(nom_fichier);
    int n;
    fic>>n;
    while(fic.good()){
        Date d;
        d.jour = n;
        fic>>n;
        d.mois = n;
        fic>>n;
        d.an = n;

        Tirage t;
        fic>>n;
        for(int i=0; i<5; ++i){
            t[i]=n;
            fic>>n;
        }
        ajoutTirage(h, t, d);
    }
}

void afficheTirage(Historique h, Tirage t){
    if(h==nullptr)
        std::cout<<"Tirage inédit\n";
    else{
        if(ordreTirage(t, h->tirage)==-1) //si t < h->tirage
            afficheTirage(h->sag, t);
        else if(ordreTirage(t, h->tirage)==1)
            afficheTirage(h->sad, t);
        else{
            std::cout<<"Tirage du ";
            afficheListeDate(h->l_dates);
            std::cout<<std::endl;
        }
    }
}

void afficheSuiteTirage(Historique h,  std::string nom_fichier){
    std::ifstream fic;
    fic.open(nom_fichier);

    int n;
    fic>>n;
    while(fic.good()){
        Tirage t;
        for(int i=0; i<5; ++i){
            t[i]=n;
            std::cout<<t[i]<<" ";
            fic>>n;
        }
        afficheTirage(h, t);
    }
}

int nbTirageMemeDate(ListeDate l){
    if(l==nullptr)
        return 0;
    else{
        return 1+nbTirageMemeDate(l->suiv);
    }
}
int nbTirages(Historique h){
    if(h==nullptr)
        return 0;
    else{
        int n = nbTirageMemeDate(h->l_dates);
        n+=nbTirages(h->sag);
        n+=nbTirages(h->sad);
        return n;
    }
}

void frequenceNumBis(Historique h, std::array<int, 50> & freqNum){
    if(h!=nullptr){
        int n = nbTirageMemeDate(h->l_dates);
        for(int i=0; i<5; ++i){
            freqNum[h->tirage[i]-1]+= n;
        }
        frequenceNumBis(h->sag,freqNum);
        frequenceNumBis(h->sad, freqNum);
    }
}

void frequenceNum(Historique h){
    int tot = nbTirages(h);
    std::array<int, 50> freqNum;
    for(int i=0; i<50; ++i)
        freqNum[i]=0;
    frequenceNumBis(h, freqNum);
    for(int i=0; i<50; ++i){
        //<std::cout<<freqNum[i]<<"\n";
        std::cout<<i+1<<" : "<<((static_cast<float>(freqNum[i])/tot)) * 100<<"\n";
    }
}
int main(){
    // Date d1, d2;
    // ListeDate l = nullptr;
    // d1.an = 1000; d1.mois = 3; d1.jour = 10;
    // d2.an = 1000; d2.mois = 2; d2.jour = 10;
    //
    // std::cout<<ordreDate(d1, d2)<<"\n";
    // ajoutDate(l, d2);
    // afficheListeDate(l);
    // ajoutDate(l, d1);
    // afficheListeDate(l);

    Historique histo;
    initHistorique(histo);
    memoriseHistorique(histo, "fake_loto.txt");

    //afficheSuiteTirage(histo, "tirages.txt");
    //std::cout<<nbTirages(histo);
    frequenceNum(histo);

    return 0;
}

