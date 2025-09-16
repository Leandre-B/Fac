#include <iostream>
#include <chrono>

// implementation de liste qui permet d'acceder à la fin en O(1).

// 1
struct maillon
{
	uint val;
	maillon * suiv=nullptr;
};

struct liste  {
  maillon * tete=nullptr; // pointeur vers premier maillon
  maillon * queue=nullptr; // pointeur vers dernier maillon
  uint longueur=0;	// longueur de la liste
};

void supprime_premier (maillon* & L)
// on suppose que L != nullptr
{
       maillon* p;
       p = L;
       L = L->suiv;
       delete p;
}

void vide (liste & L)
{
     while (L.tete != nullptr)
          supprime_premier(L.tete);
	L.queue=nullptr;
	L.longueur=0;
}


void initialiser (liste & L)
{
      if (L.tete != nullptr) vide(L);
	  L.tete = nullptr;
 	 L.queue = nullptr;
	 L.longueur = 0;
}

void ajout_debut (liste & L, uint v)
{
      maillon* p = new maillon;
      p->val = v;
      p->suiv = L.tete;
      L.tete = p;
	  if (L.longueur == 0) L.queue = p;
	  L.longueur++;
}

//ajout fin, en O(1)!
//N.B: propriété suffisante pour une implémentation de file
void ajout_fin (liste & L, uint e)
{

	if (L.longueur==0){ // operation en O(1)
		ajout_debut(L,e);// operation en O(1)
	}
	else{
		maillon * dernier =  L.queue; // operation en O(1)
		maillon * m = new maillon; // operation en O(1)
		m->val = e; // operation en O(1)
		m->suiv = nullptr; // operation en O(1)
		dernier->suiv = m; // operation en O(1)
		L.queue = m;
		L.longueur ++;
	}
}



	
void affiche (maillon* p)
{
	while (p != nullptr)
	{
		std::cout << p->val << " ";
		p = p->suiv;
	}
	std::cout <<"\n";
}

liste crible(uint n){
	liste L; // l'initialisation par defaut fonctionne bien
	for (uint i=2; i<n; i++){
			bool prime= true;
			bool not_finished = true;
			maillon * p = L.tete;
			while(p!=nullptr && prime && not_finished){
					if (p->val * p->val > i) not_finished=false;
					else {
					//std::cout << p->val << " est teste comme diviseur  pour "<< i << " !\n";
					prime = (i% p->val != 0);
					p = p->suiv;
					};
			}
			if (prime) {ajout_fin(L,i);
				//std::cout << i << " est premier !\n";
			}
	}
	return L;
}

liste crible2(uint n){
	liste L; // l'initialisation par defaut fonctionne bien
	 if (n>=7) ajout_debut(L,7);
	 if (n>=5) ajout_debut(L,5);
	 if (n>=3) ajout_debut(L,3);
	 if (n<=10)   {
		  if (n>=2) ajout_debut(L,2);
		 return L;
	 }
	for (uint i=11; i<n; i=i+2){
			bool prime= true;
			bool not_finished = true;
			maillon * p = L.tete;
			while(p!=nullptr && prime && not_finished){
					if (p->val * p->val > i) not_finished=false;
					else {
					//std::cout << p->val << " est teste comme diviseur  pour "<< i << " !\n";
					prime = (i% p->val != 0);
					p = p->suiv;
					};
			}
			if (prime) {ajout_fin(L,i);
				//std::cout << i << " est premier !\n";
			}
	}
   ajout_debut(L,2);
	return L;
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

	int n;
	
	std::cout << "n = ";
	std::cin >> n;
	std::cout << "Nombres premiers <= n : " << std::endl;
	init_chrono();
	liste L = crible(n);
	 std::cout << "Calculé par crible_v0 en " << etat_chrono() << " ms"<<std::endl;
	//affiche(L.tete);
	 std::cout << "Il y a  " << L.longueur << " nombres premiers inférieurs ou égaux à " << n<<std::endl;

	vide(L);

	std::cout << "Nombres premiers <= n par crible2: " << std::endl;
    init_chrono();
	L = crible2(n);
	 std::cout << "Calculé par crible2 en " << etat_chrono() << " ms"<<std::endl;
	//affiche(L.tete);
    std::cout << "Il y a  " << L.longueur << " nombres premiers inférieurs ou égaux à " << n<<std::endl;

	vide(L);

	return 0;
}

