#include <iostream>
#include <ctime>
#include <cmath>


//====== 1 Message===========
struct Message{
	unsigned int* tab;
	unsigned int longueur;
};

const unsigned int TMAX_MESSAGE = 100;
const unsigned int TMAX_CLE = 50;


Message genMessageAlea(const uint & taille){
	Message message;
	message.longueur = taille;
	message.tab = new unsigned int[message.longueur];

	for(unsigned int i=0; i<message.longueur; ++i)
		message.tab[i]=rand()%TMAX_MESSAGE;

	return message;
}

void afficheMessage(const Message & message){
	for(unsigned int i=0; i<message.longueur-1; ++i)
		std::cout<<message.tab[i]<<" ";
	std::cout<<message.tab[message.longueur-1]<<"\n";
}
//=============


//========= 2 Cle ==========

struct Maillon{
	unsigned int val;
	Maillon* suiv = nullptr;
	Maillon* prec = nullptr;
};

struct Cle{
	unsigned int taille;
	Maillon* tete;
	Maillon* queue;
};


void ajouteTete(Cle & cle, unsigned int val){
	Maillon* new_maillon = new Maillon;
	new_maillon->val = val;
	new_maillon->suiv=cle.tete;
	new_maillon->prec = cle.tete;

	if(cle.tete==nullptr)
		cle.queue = new_maillon;
	else
		cle.tete->suiv=new_maillon;

	cle.tete=new_maillon;
}

Cle genCleAlea(unsigned int taille){
	Cle cle;
	cle.taille=taille;
	cle.tete= nullptr; cle.queue = nullptr;

	for(unsigned int i=0; i<taille; ++i)
		ajouteTete(cle, rand()%TMAX_CLE);

	return cle;
}

void afficheCle(const Cle & cle){
	Maillon* m = cle.tete;
	for(unsigned int i=0; i<cle.taille -1; ++i){
		std::cout<<m->val<<" ";
		m=m->suiv;
	}
	std::cout<<m->val<<"\n";
}

//=============


int main(){
	srand(time(nullptr));

	Message message = genMessageAlea(12);
	afficheMessage(message);

	Cle cle = genCleAlea(10);
	afficheCle(cle);

	return 0;
}
