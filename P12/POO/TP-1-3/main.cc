#include "sequence.hh"
#include <chrono>
#include <iostream>


// "opti" :  293213 ms
// normal : 4724287 ms
int main() {
	auto start =
        std::chrono::high_resolution_clock::now();

	Sequence a, b;
	sc_initialiservide(a); // 3
	sc_initialiservide(b);
	for(int i = 0; i<50000; ++i)
		sc_ajouter(a, Couleur::Rouge);
	sc_copier(b, a); // Copie a dans b // 5
	sc_afficher(sc_acces(a, 0)); std::cout << "\n"; // 6 et 7
	for (indicesequence i=0; i<a.taille; ++i) {
		sc_afficher(sc_acces(a,i));
		std::cout << " ";
	}
	std::cout << "\n";
	sc_vider(a); // 8
	std::cout << "A: "; sc_afficher(a); std::cout << "\n"; // 9
	std::cout << "B: "; sc_afficher(b); std::cout << "\n";
	std::cout << sc_comparer(a,b) << "\n"; // 0
	sc_copier(a,b);
	std::cout << sc_comparer(a,b) << "\n";
	
	
	// Record ending time
    auto stop =
	std::chrono::high_resolution_clock::now();
	
    auto duration =
	std::chrono::duration_cast<std::chrono::microseconds>(
		stop - start);
		
		std::cout << "Time taken: "
		<< duration.count()
		<< " microseconds\n";
		
		return 0;
}
