#include <iostream>
// Element peut être n'importe quel type.
// Avec un using, une seule ligne à changer au début pour passer à float , uint, string ....
// on doit quand même avoir < <= == implémentés pour le type.
using Element = int;

//Une liste triée, c'est une liste ...
// au programmeur de vérifier que les opérations maintiennent les listes triées, pas dans les conteneurs.

struct maillon
{
	Element val;
	maillon * suiv = nullptr;
};
using liste = maillon *;

// 1

//versions récursives

//version plus pédagogique en decomposant
void ajouterEnTete (Element e, liste &  L)
{
		liste aux = new maillon;
		aux->val = e;
		aux->suiv = L;
		L = aux;
}

//Que se passe t'il lorsqu'on écrit:
void ajouterEnTete_bis (Element e, liste  L)
{
		liste aux = new maillon;
		aux->val = e;
		aux->suiv = L;
		L = aux;
}

// on a ajouté un maillon avant la tete de liste, on ne peut plus y accéder -> fuite mémoire
// L pointe toujours sur l'element initial, c'est comme si on n'avait rien fait... fuite mémoire ce n'est pas rien.


void ajouter_v0 (Element e, liste &  L)
{
	if ((L == nullptr) or (L->val > e))
	{
		ajouterEnTete (e,L);
	}
	else ajouter_v0(e,L->suiv);
}


void ajouter_iter_v0 (Element e, liste &  L)
{
	maillon* Laux = L;
	while (Laux != nullptr)
	{
		if (Laux->val > e) {
			ajouterEnTete (e,Laux);
			return;

		}
		else Laux = Laux->suiv;
	}
	ajouterEnTete (e,Laux);
}


//Que se passe t'il lorsqu'on  déclare ajouter_iter_v0 (Element e, liste  L) sans le & ?
// ici, ça marche !!!!
// on fait une copie du pointeur de la liste dans le code, c'est juste rajouter une copie supplémentaire de ce pointeur sans le modifier


//mieux:
void ajouter_iter_v1 (Element e, liste  L)
{
	while (L != nullptr)
	{
		if (L->val > e) {
			ajouterEnTete (e,L);
			return;

		}
		else L = L->suiv;
	}
	ajouterEnTete (e,L);
}

// ici on n'altère pas la liste initiale (ie le pointeur vers le premeir élément de la liste ), la copie de maillon se fait sans le &.
// écriture plus concise, mais piégeuse.


//version corrigée directe
void ajouter (Element e, liste &  L)
{
	if ((L == nullptr) or (L->val > e))
	{
		liste aux = new maillon;
		aux->val = e;
		aux->suiv = L;
		L = aux;
	}
	else ajouter(e,L->suiv);
}




// 2

//version corrigée
void supprimer (Element e, liste & L)
{
	if (L != nullptr)
	{
		if (L->val == e)
		{
			liste aux = L;
			L = L->suiv;
			delete aux;
			supprimer(e,L);
		}
		else if (L->val < e)
			supprimer(e,L->suiv);
	}
}

//version pedagogique

// fonction intermédiaire: supprimer en tête de liste

void supprEnTete ( liste &  L)
{
		maillon* aux = L->suiv;
		delete L;
		L = aux;
}

//ou

void supprEnTete_v2 ( liste &  L)
{
		maillon* aux = L;
		L = L->suiv;
		delete aux;
}

// mauvaise version

void supprEnTete_bad ( liste &  L)
{
		maillon* aux = new maillon; // cree un maillon inutile, qui ne pourra plus être accédé
		aux = L->suiv;
		delete L;
		L = aux;
}


//incorrect: pourquoi ??
void supprimer_v0 (Element e, liste &  L)
{
	if (L == nullptr) return;
	if (L->val == e)
        supprEnTete (L);
	else  supprimer_v0(e,L->suiv);
}

//pb: ne supprime que la première occurence -> erreur de validité
// pb mineur: si pas d'occurence, on parcourt toute la liste, au lieu de s'arreter au premier element qui depasse, alors rien ) faire


void supprimer_v1 (Element e, liste &  L)
{
	if (L == nullptr) return;
	if (L->val > e) return;

	if (L->val == e)
	{
         supprEnTete (L);
		 supprimer_v1(e,L);
	}
	else  supprimer_v1(e,L->suiv);
}

//version iterative: on stocke le premier maillon  supérieur strictement à e, et le plus grand maillon  < e, on supprime les maillons intermediaires et on lie ces deux maillons
void  supprimer_iteratif_ND (Element e, liste &  L)
{
	if (L == nullptr) return;
	if (L->suiv == nullptr){
		if (L->val ==e) supprEnTete(L);
		return;
	}
	maillon * inf  = nullptr; // dernier maillon de valeur < e
	maillon *  Laux = L; //copie pour parcours
	while (Laux != nullptr && Laux->val <= e)
	{
		if (Laux->val < e) inf = Laux;
        if (Laux->val == e) {
            maillon * aux = Laux;
            Laux=Laux->suiv;
            delete aux;}
	}

    if (inf  == nullptr && Laux == nullptr) L=nullptr; // cas avec que des e dans la liste
	else if  (inf  == nullptr) L=Laux; // cas où la liste commence par des e
	else if  (Laux  == nullptr) return; // cas où la liste se termine  par des e
	else inf->suiv=Laux; // cas general

}



// 3
// algo de base: pour chaque element, y a t'il avant lui un élement plus grand? Si oui, on le supprime
// astuce: les elements parcourus restants sont forcement croissants, le plus grand est le dernier element, pas de parcours linéaire

void corriger (liste & L)
{
	if ((L != nullptr) and (L->suiv != nullptr))
	{
		if (L->val > L->suiv->val)
		{
			maillon* aux = L->suiv;
			L->suiv = L->suiv->suiv;
			delete aux;
			corriger(L);
		}
		else corriger(L->suiv);
	}
}

void corriger_ND (liste & L)
{
	if ((L == nullptr) or (L->suiv == nullptr)) return;

	if (L->val > L->suiv->val){
		supprEnTete(L->suiv);
		corriger_ND(L);
	}
	else corriger_ND(L->suiv);

}

//N.B: avec (L->val > L->suiv->val) on autorise les egalités, liste croissante, pas focement strictement croissante


void corriger_envers_test (liste & L)
{
	if ((L == nullptr) or (L->suiv == nullptr)) return;

	if (L->val > L->suiv->val){
		supprEnTete(L);
		corriger_ND(L);
	}
	else corriger_ND(L->suiv);

}

//ça l'air de marcher sur des exemples simples. Preuve formelle de validité?

//non contre-exemple: liste 1-2 - 4 - 3  -0

// TODO: version de droite à gauche, on supprime en parcourant la liste de gauche à droite.
// ici version constructive, on cree une nouvelle liste

liste corriger_par_la_fin_ND (liste & L)
{
	if (L == nullptr)  return nullptr;
	liste temp = nullptr;
    if (L->suiv == nullptr){
		ajouterEnTete (L->val,temp);
		return temp;
	}
	temp = corriger_par_la_fin_ND(L->suiv);

	if (L->val > L->suiv->val) return temp;
	ajouterEnTete (L->val,temp);
	return temp;

}

liste corriger_par_la_fin_ND_factor (liste & L)
{
	if (L == nullptr)  return nullptr;

	liste temp = corriger_par_la_fin_ND_factor(L->suiv);

	if ((L->suiv != nullptr) and (L->val > L->suiv->val)) return temp;
	ajouterEnTete (L->val,temp);
	return temp;

}


// analogue difference entre affichage d'une liste de gauche à doite versus de droite a gauche

void affiche_gauche_doite(liste & L) // NB: & optionnel, revient au meme
{
	if (L == nullptr)  return;
	std::cout<< L->val << " ";
	affiche_gauche_doite(L->suiv);
}

void affiche_droite_gauche(liste & L) // NB: & optionnel, revient au meme
{
	if (L == nullptr)  return;
	affiche_droite_gauche(L->suiv);
	std::cout<< L->val << " ";
}

// NB: faire cela en iteratif en gardant une liste simplement chainee se ferait avec une pile additionnelle.
// La pile d'appels récursifs est équivalente à cette pile additionnelle.



// 4

//version corrigee plus difficile
liste fusionner (liste & L1, liste & L2)
{
	if (L1 == nullptr) return L2;
	else if (L2 == nullptr) return L1;
	else if (L1->val <= L2->val)
	{
		L1->suiv = fusionner(L1->suiv,L2);
		return L1;
	}
	else // (L1->val > L2->val)
	{
        L2->suiv = fusionner(L1,L2->suiv);
		return L2;		
	}
}

//version plus pédagogique?


liste fusionner_ND (liste & L1, liste & L2)
{
	if (L1 == nullptr) return L2;
	if (L2 == nullptr) return L1;

    liste L=nullptr;

	if (L1->val <= L2->val)
	{
        L=fusionner_ND(L1->suiv,L2);
        ajouterEnTete(L1->val, L);

	}
	else // (L1->val > L2->val)
	{
        L=fusionner_ND(L1, L2->suiv);
        ajouterEnTete(L2->val, L);

	}
    return L;
}

//question: que se passe-til si on elnlève les & en déclarant
// liste fusionner_ND (liste  L1, liste  L2) ?
//pas de difference notable.. juste deux copies de poiteurs en plus.


//TODO: version itérative?

//solution 1: il faudrait un ajouter en fin de la liste en construction.

void ajouterEnFin (Element e, liste &  L)
{
	//TODO: pb en O(n), il faut parcourir toute la liste
	// en iteratif ici, plus simple en recursif
	if (L == nullptr) {
		ajouterEnTete(e, L);
		return ;
	}
	maillon *  iter = L;
	while (iter->suiv != nullptr)
		iter = iter->suiv;
	ajouterEnTete(e, iter->suiv);

}


liste fusionner_iter_bad (liste & L1, liste & L2)
{
	if (L1 == nullptr) return L2;
	if (L2 == nullptr) return L1;

    liste fusion=nullptr; //le resultat
    maillon* c1=L1; // pour iterer sur le parcours de liste L1
	maillon* c2=L2; // pour iterer sur le parcours de liste L2

	while(c1!= nullptr && c2 != nullptr){
		if (c2==nullptr) {ajouterEnFin(c1->val, fusion);
			c1 = c1->suiv;
		}
		else if (c1==nullptr) {ajouterEnFin(c2->val, fusion);
			c2 = c2->suiv;
		}
		else if (c1->val <= c2->val)){
			ajouterEnFin(c1->val, fusion);
			c1 = c1->suiv;
		}
		else{
			ajouterEnFin(c2->val, fusion);
			c2 = c2->suiv;
		}
	}


    return fusion;
}

// probleme: complexité quadratique a cause de l'ajout en fin en O(n)



// solution1: en itératif, il vaut mieux avoir une structure de liste plus riche. Liste doublement chaînée, aucun problème. Ici, juste ajout en fin en O(1) suffit, liste simplement chaînée avec accès en O(1) au début et à la fin, en mettant à jour les deux pointeurs dans cette structure de liste. ex: crible d'Erathostène par une telle structure de liste.

// solution 2: est ce qu'on peut faire des ajout en d"but de liste et garder liste simplement chainee avece acces au debut de liste uniquement?

liste fusionner_iter_bad (liste & L1, liste & L2)
{
	if (L1 == nullptr) return L2;
	if (L2 == nullptr) return L1;

    liste fusion=nullptr; //le resultat
    maillon * dernier = fusion; // dernier maillon de liste temps

    maillon* c1=L1; // pour iterer sur le parcours de liste L1
	maillon* c2=L2; // pour iterer sur le parcours de liste L2

	while(c1!= nullptr && c2 != nullptr){
		if (c2==nullptr) {ajouterEnTete(c1->val, dernier->suiv);
			c1 = c1->suiv;
			dernier = dernier->suiv;
		}
		else if (c1==nullptr) {ajouterEnFin(c2->val, dernier->suiv);
			c2 = c2->suiv;
			dernier = dernier->suiv;
		}
		else if (c1->val <= c2->val)){
			ajouterEnFin(c1->val, dernier->suiv);
			c1 = c1->suiv;
			dernier = dernier->suiv;
		}
		else{
			ajouterEnFin(c2->val, dernier->suiv);
			c2 = c2->suiv;
			dernier = dernier->suiv;
		}
	}


    return fusion;
}



//
// ------------------------------------------
// TEST
void afficher (liste L)
{
	liste p = L;
	while (p != nullptr)
	{
		std::cout << p->val << " ";
		p = p->suiv;
	}
	std::cout << std::endl;
}

int main ()
{
	liste A = nullptr;
	// a
	ajouter(8,A);
	ajouter(15,A);
	ajouter(3,A);
	ajouter(7,A);
	ajouter(8,A);
	ajouter(5,A);
	afficher(A);
	// b
	supprimer(15,A);
	supprimer(8,A);
	supprimer(3,A);
	afficher(A);
	// c
	liste B = nullptr;
	ajouter(5,B);
	ajouter(9,B);
	ajouter(1,B);
	ajouter(4,B);
	ajouter(12,B);
	B->val = 4;
	B->suiv->suiv->val = 11;
	afficher(B);
	corriger(B);
	afficher(B);
	// d;
	liste C = fusionner_ND(A,B);
	afficher(C);
	//afficher(A);
	//afficher(B);
	while (C != nullptr)
		supprimer(C->val,C);
		
	return 0;
}
