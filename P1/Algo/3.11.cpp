#include <iostream>

int main() {

	int n,i=1; //n le nombre de numéro de la suite que l'on veut afficher
	std::cin >> n;


	/*
	calcul i = combien de fois on a une partie de suite "complete" et n le nombre de numéro qu'il reste.
	Exemple : dans la suite 1  12  123  1234  12, i=4 et n=2.
        La boucle trouve i et n en sachant le nombre de nombre de numéros dans la suite (dans l'exemple 11).

    */

    while(n>=i) {
		n = n - i;
		i++;
	}


	//on affiche les i parties de la suite "complète"
	for (int j = 1; j <= i-1; j++) {
		for (int k = 1; k <= j; k++) {
			std::cout << k << " ";
		}
	}


	//on affiche le reste de la suite (soit les n numéros restant)
	for(int j=1;j<=n;j++){
        std::cout<<j<<" ";
	}

	return 0;
}
