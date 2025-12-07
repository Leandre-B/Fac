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
	Maillon* m;
};


void ajouteTete(Cle & cle, unsigned int val){
	Maillon* new_maillon = new Maillon;
	new_maillon->val = val;


	if(cle.m==nullptr){ //pas de maillon
		new_maillon->suiv=new_maillon;
		new_maillon->prec = new_maillon;
		cle.m = new_maillon;
	}
	else{
		new_maillon->suiv=cle.m;
		new_maillon->prec = cle.m->prec;
		cle.m->prec->suiv = new_maillon;
		cle.m->prec=new_maillon;
		cle.m = new_maillon;
	}
}

Cle genCleAlea(unsigned int taille){
	Cle cle;
	cle.taille=taille;
	cle.m= nullptr;

	for(unsigned int i=0; i<taille; ++i)
		ajouteTete(cle, rand()%TMAX_CLE);

	return cle;
}

void afficheCle(const Cle & cle){
	Maillon* m = cle.m;
	for(unsigned int i=0; i<cle.taille; ++i){
		std::cout<<m->val<<" ";
		m=m->suiv;
	}
	std::cout<<"\n";
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
		chemin->val = !(taille%2==0);
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
			std::cout<<'T';
		else
			std::cout<<'F';
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

unsigned int supprimeFeuille(MessageChiff & m, Chemin chemin){
	//si c'est un feuille
	if(m->sag == m->sad){
		unsigned int n = m->val;
		delete m;
		m=nullptr;
		return n;
	}else if(chemin==nullptr)
		return supprimeFeuille(m->sag, chemin);
	else{
		if(chemin->val)
			return supprimeFeuille(m->sad, chemin->suiv);
		else
			return supprimeFeuille(m->sag, chemin->suiv);
	}
}

//=====================

//=== Chiffrement ============
MessageChiff chiffrement(Message message, Cle cle){
	Chemin chemin;
	MessageChiff messageChiff = nullptr;
	for(unsigned int i=0; i<message.longueur; ++i){
		chemin = construireChemin(cle.m->val+i);
		//afficheChemin(chemin);std::cout<<std::endl;
		ajoutNombre(messageChiff, chemin, message.tab[i]+cle.m->val);
		cle.m=cle.m->suiv;
		supprimeChemin(chemin);
	}
	return messageChiff;
}
//==================


//====== Dechiffrement ====

void positionneCle(Cle & cle, uint l){
	for(int i=0; i<l-1; ++i)
		cle.m = cle.m->suiv;
}

Message dechiffrement(MessageChiff messageChiff, Cle cle){
	Message message;
	message.longueur = taille(messageChiff);
	message.tab = new unsigned int[message.longueur];
	positionneCle(cle, message.longueur);

	for(int i=message.longueur-1; i>=0; --i){
		Chemin chemin;
		std::cout<<"cle : "<<cle.m->val + i<<"\n";
		chemin = construireChemin(cle.m->val+i);
		unsigned int val_noeud;
		val_noeud = supprimeFeuille(messageChiff, chemin);

		std::cout<<i<<" : "<<val_noeud<<std::endl;
		message.tab[i] = val_noeud - cle.m->val;
		cle.m=cle.m->prec;
		supprimeChemin(chemin);
		std::cout<<"fin for\n";
	}
	std::cout<<"end\n";
	return message;
}

//==============

Message stringToMessage(const std::string & str){
	Message m;
	m.tab = new unsigned int [str.length()];
	m.longueur = str.length();
	for(int i=0; i<str.length(); ++i)
		m.tab[i] = int(str[i]);
	return m;
}

std::string messageToString(const Message & m){
	std::string str;
	for(int i=0; i<m.longueur; ++i)
		str += char(m.tab[i]);
	return str;
}
int main(){
	srand(time(nullptr));

	std::string mess;
	std::getline(std::cin, mess);
	Message m = stringToMessage(mess);
	Cle cle = genCleAlea(8);

	MessageChiff mChiff= chiffrement(m, cle);
	afficheMessageChiff(mChiff);
	std::cout<<std::endl;;

	Message mm = dechiffrement(mChiff, cle);
	//std::cout<<messageToString(m)<<std::endl;


	return 0;
}
