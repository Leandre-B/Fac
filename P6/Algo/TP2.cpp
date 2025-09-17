//Listes doublement chainées

#include <iostream>

using Elem=int;

struct Maillon{
    Elem elem;
    Maillon* suiv;
    Maillon* prec;
};

struct Liste{
    Maillon* tete;
    Maillon* queue;
};

Liste init(){
    Liste l;
    l.tete=nullptr;
    l.queue=nullptr;

    return l;
}

bool estVide(const Liste & l){
    return l.tete==nullptr;
}

void ajoutTete(Liste & l, const Elem & e){
    Maillon* new_m = new Maillon;
    new_m->elem=e;
    new_m->suiv=l.tete;
    new_m->prec=nullptr;

    if(estVide(l)){
        l.queue= new_m;
    }else{
        l.tete->prec=new_m;
    }
    l.tete=new_m;
}

void ajoutQueue(Liste & l, const Elem & e){
    if(l.queue==nullptr){
         //si la liste est vide
         ajoutTete(l,e);
    }else{
        l.queue->suiv = new Maillon;
        l.queue->suiv->elem = e;
        l.queue->suiv->suiv = nullptr;
        l.queue->suiv->prec = l.queue;
        l.queue=l.queue->suiv;
    }
}

void aff_tete_to_queue_rec_bis(Maillon* m){
    if(m!=nullptr){
        std::cout<<m->elem<<"\n";
        aff_tete_to_queue_rec_bis(m->suiv);
    }
}
void aff_tete_to_queue_rec(const Liste & l){
    std::cout<<"⌜ Tete ⌝\n";
    if(!estVide(l)){ 
        aff_tete_to_queue_rec_bis(l.tete);
    }
    std::cout<<"L Queue ⅃\n";
}

void aff_tete_to_queue_ite(Liste l){
    std::cout<<"⌜ Tete ⌝\n";
    while(l.tete!=nullptr){
        std::cout<<l.tete->elem<<"\n";
        l.tete=l.tete->suiv;
    }
    std::cout<<"L Queue ⅃\n";
}


void aff_queue_to_tete_bis(Maillon * m){
    if(m!=nullptr){
        std::cout<<m->elem<<"\n";
        aff_queue_to_tete_bis(m->prec);
    }
}
void aff_queue_to_tete(const Liste & l){
    std::cout<<"⌜ Queue ⌝\n";
    if(!estVide(l)){ 
        aff_queue_to_tete_bis(l.queue);
    }
    std::cout<<"L Tete ⅃\n";
}

int longueur(Liste l){
    int lg=0;
    while(l.tete!=nullptr){
        ++lg;
        l.tete=l.tete->suiv;
    }
    return lg;
}

void suppr_tete(Liste & l){
    if(!estVide(l)){ 
        Maillon* aux = l.tete;
        l.tete=l.tete->suiv;
        if(l.tete==nullptr)//il n'y a plus de maillon
            l.queue =nullptr;
        else
            l.tete->prec=nullptr;
        delete(aux);
    }
}

void suppr_queue(Liste & l){
    if(!estVide(l)){ 
        Maillon* aux = l.queue;
        if(l.queue->prec==nullptr){//il n'y a qu'un maillon dans la liste
            l.queue=nullptr;
            l.tete=nullptr;
        }else{
            l.queue = l.queue->prec;
            l.queue->suiv=nullptr;
        }
        
        delete(aux);
    }
}

Maillon* rechercheBis(Maillon* m, const Elem & x){
    if(m==nullptr){
        return nullptr;
    }else{
        if(m->elem==x)
            return m;
        else
            return rechercheBis(m->suiv, x);
    }
}

Maillon* recherche(Liste l, const Elem & x){
    return rechercheBis(l.tete, x);
}



void inserer_apres_1st_occ(Liste & l, const Elem & x, const Elem & y){
    Maillon* m =recherche(l,x);

    //si on a trouve l'elem
    if(m!=nullptr){
        //si c'est la queue
        if(m->suiv==nullptr)
            ajoutQueue(l,y);
        else{
            Maillon* new_m=new Maillon;
            new_m->elem=y;
            new_m->suiv=m->suiv;
            new_m->prec=m;

            m->suiv->prec=new_m;
            m->suiv=new_m;
        }
    }
}

void inserer_avant_1st_occ(Liste & l, const Elem & x, const Elem & y){
    Maillon* m = recherche(l,x);
    //si l'elem existe dans la liste
    if(m!=nullptr){
        //si c'est la tete
        if(m->prec==nullptr)
            ajoutTete(l,y);
        else{
            Maillon* new_m = new Maillon;
            new_m->elem=y;
            new_m->suiv=m;
            new_m->prec=m->prec;

            m->prec->suiv=new_m;
            m->prec=new_m;
            
        }
    }
}

void suppr_1st_occ(Liste & l, Elem e){
    Maillon* m = recherche(l,e);
    //si elem trouve
    if(m!=nullptr and !estVide(l)){
        //si 1 seul maillon
        if(l.queue==l.tete)
            l=init();

        //si 1er maillon
        else if(m->prec==nullptr){
            l.tete=l.tete->suiv;
            l.tete->prec=nullptr;
        }

        //si c'est le dernier maillon
        else if(m->suiv==nullptr){
            l.queue=l.queue->prec;
            l.queue->suiv=nullptr;
        }
        else{
            m->prec->suiv=m->suiv;
            m->suiv->prec=m->prec;
        }
        delete m;    
    }
}

void suppr(Liste & l){
    if(l.tete==nullptr){
        l.queue=nullptr;
    }
    else{
        Maillon* m =l.tete;
        l.tete=l.tete->suiv;
        delete m;
        suppr(l);
    }
}

void suppr_after_maillon_bis(Maillon* & m){
    if(m!=nullptr){
        Maillon* aux = m;
        m=m->suiv;
        delete(aux);
        suppr_after_maillon_bis(m);
    }
}

void suppr_after_maillon(Liste & l, Maillon* p){
    //si il n'y a plus d'un maillon ou il n'y a rien apres p
    if(l.queue!=nullptr and p!=nullptr and l.tete!=l.queue and p->suiv!=nullptr){

        l.queue=p;
        if(l.queue==nullptr)
            l.tete=nullptr;
        suppr_after_maillon_bis(p->suiv);
    }
}

int main(){

    Liste l = init();
    ajoutTete(l,1);
    ajoutTete(l,2);
    ajoutTete(l,3);
    ajoutTete(l,4);

    //std::cout<<recherche(l,12)/*->elem*/<<"\n";
    //inserer_avant_1st_occ(l,3,7);

    aff_queue_to_tete(l);std::cout<<"\n";
    aff_tete_to_queue_rec(l);std::cout<<"\n";

    suppr_after_maillon(l, recherche(l,4));
    aff_queue_to_tete(l);std::cout<<"\n";
    aff_tete_to_queue_rec(l);std::cout<<"\n";

    return 0;
}