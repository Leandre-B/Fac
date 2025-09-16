#include <iostream>
#include <chrono>

struct maillon
{
	int val;
	maillon * suiv;
};
using liste = maillon *;

liste construit (int vmin, int vmax)
{
	liste L;
	if (vmin <= vmax)
	{
		L = new maillon;
		L->val = vmin;
		L->suiv = construit(vmin+1,vmax);
	}
	else L = nullptr;
	return L;
}

//construit de 2 a n
liste construit (int n)
{
	liste L= nullptr;
	for (int i=n ; i>=2 ; i--){
		maillon * aux = new maillon;
		aux->val = i;
		aux->suiv =L;
		L=aux;
	}
	return L;
}

void supprime_premier (liste & L)
{
	liste aux;
	aux = L;
	L = L->suiv;
	delete aux;
}

void supprime_multiples (int d, liste & L)
{
	if (L != nullptr)
	{
		supprime_multiples(d,L->suiv);
		if (L->val%d == 0)
			supprime_premier(L);
	}
}

void supprime_multiples (liste & L)
{
	if (L != nullptr)
	{
		supprime_multiples(L->val,L->suiv);
		supprime_multiples(L->suiv);
	}
}
	
void affiche (liste L)
{
	if (L!=nullptr){
		std::cout << L->val << " ";
		affiche(L->suiv);
	}
	else std::cout <<std::endl;
}

// ------------------ GESTION CHRONOS -----------------------
auto chrono = std::chrono::system_clock::now();
void init_chrono ()
{
	chrono = std::chrono::system_clock::now();
}
float etat_chrono ()
{
	return (0.0 + std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - chrono).count());
}


int main ()
{
	liste L;
	int n;
	
	std::cout << "n = ";
	std::cin >> n;
	std::cout << "Nombre premiers <= n : " << std::endl;
	init_chrono();
	L = construit(n);
	supprime_multiples(L);
	std::cout << "Calculé par crible Erathostene en " << etat_chrono() << " ms"<<std::endl;
	affiche(L);
	
	return 0;
}

