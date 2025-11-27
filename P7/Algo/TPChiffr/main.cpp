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

//======= Chemin =========
struct MaillonBool{
	bool val;
	MaillonBool* suiv;
};

using Chemin = MaillonBool*;

void construireBis(Chemin & chemin, unsigned int taille){
	if(taille==0 or taille==1){
		chemin = new MaillonBool;
		chemin->val = taille!=0;
		chemin->suiv=nullptr;
	}else{
		chemin = new MaillonBool;
		chemin->val = taille%2!=0;
		construireBis(chemin->suiv, taille/2);
	}
}

Chemin construireChemin(unsigned int taille){
	Chemin chemin = nullptr;
	construireBis(chemin, taille);
	return chemin;
}

void afficheCheminBis(Chemin chemin){
	if(chemin!=nullptr){
		if(chemin->val)
			std::cout<<'F';
		else
			std::cout<<'T';
		afficheCheminBis(chemin->suiv);
	}
}

void afficheChemin(Chemin chemin){
	afficheCheminBis(chemin);
	std::cout<<std::endl;
}
void supprimeChemin(Chemin & chemin){
	if(chemin!=nullptr){
		Chemin bis = chemin;
		chemin = chemin->suiv;
		delete bis;
		supprimeChemin(chemin);
	}
}
//===============

//===== Message Chiffre =======
struct NoeudInt{
	unsigned int val;
	NoeudInt* sag;
	NoeudInt* sad;
};

using MessageChiff = NoeudInt*;

void ajoutNombre(MessageChiff & m, Chemin chemin, const unsigned int val){
	if(m==nullptr){
		m= new NoeudInt;
		m->val = val;
		m->sad = nullptr;
		m->sag = nullptr;
	}else if(chemin==nullptr)
		ajoutNombre(m->sag, chemin, val);
	else{
		if(chemin->val)
			ajoutNombre(m->sad, chemin->suiv, val);
		else
			ajoutNombre(m->sag, chemin->suiv, val);
	}
}



void afficheMessageChiff(MessageChiff m){
	if(m!=nullptr){
		afficheMessageChiff(m->sag);
		std::cout<<(m->val)<<" ";
		afficheMessageChiff(m->sad);
	}
}

int taille(MessageChiff m){
	if(m==nullptr)
		return 0;
	else{
		int n = 1 + taille(m->sag);
		return n + taille(m->sad);
	}
}

void supprimeFeuille(MessageChiff & m, Chemin chemin){
	//si c'est un feuille
	if(m->sag == m->sad){
		delete m;
		m=nullptr;
	}else if(chemin==nullptr)
		supprimeFeuille(m->sag, chemin);
	else{
		if(chemin->val)
			supprimeFeuille(m->sad, chemin->suiv);
		else
			supprimeFeuille(m->sag, chemin->suiv);
	}
}

//=====================


MessageChiff chiffrement(Message message, Cle cle){
	Chemin chemin;
	MessageChiff messageChiff;
	for(int i=0; i<message.longueur; ++i){
		chemin = construireChemin(message.tab[i]+i);
		ajoutNombre(messageChiff, chemin, message.tab[i]+cle.tete->val);
		cle.tete=cle.tete->suiv;
		supprimeChemin(chemin);
	}
	return messageChiff;
}


int main(){
	srand(time(nullptr));

	Message message = genMessageAlea(12);
	afficheMessage(message);

	Cle cle = genCleAlea(10);
	afficheCle(cle);
	
	Chemin chemin = construireChemin(8);
	afficheChemin(chemin);

	MessageChiff messageChiff = nullptr;
	ajoutNombre(messageChiff, chemin, 10);
	ajoutNombre(messageChiff, chemin, 2);
	ajoutNombre(messageChiff, chemin, 1);
	ajoutNombre(messageChiff, chemin, 1203);
	afficheMessageChiff(messageChiff);
	supprimeFeuille(messageChiff,chemin);
	std::cout<<"\n"<<taille(messageChiff);
	supprimeChemin(chemin);

	return 0;
}
