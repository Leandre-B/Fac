package test;
import program.Annuaire;
import util.Saisie;

public class Test {

	public static void main(String[] args) {
	
		Annuaire annuaire = new Annuaire();	
		
		
		int rep =0; 
		while(rep!=-1){              
			System.out.println("1 ===>  Ajouter un nouveau client"); 
			System.out.println("2 ===>  Afficher la taille de l'annuaire"); 
			System.out.println("3 ===>  Afficher l'annuaire complet"); 
			System.out.println("4 ===>  Rechercher un client par son identifiant"); 
			System.out.println("5 ===>  Supprimer un client par son identifiant"); 
			System.out.println("6 ===>  Crediter le solde d'un client"); 
			System.out.println("7 ===>  Afficher le total des soldes des clients de l'annuaire"); 
			System.out.println("-1 ===>  Quitter"); 
			rep = Saisie.lireEntier("Votre choix ?"); 
			
			if(rep == 1){              
	
				annuaire.ajouterClient("Bob");
				annuaire.ajouterClient("Barbara");
				annuaire.ajouterClient("Michelle");

				//annuaire.ajouterClient(Saisie.lireString("Saisir un nom"));
				
			} else if (rep ==2){ 
				
				annuaire.afficherTaille();
		
	
			} else if (rep ==3){ 
				
				annuaire.afficher();
				
			} else if (rep ==4){ 
				
				annuaire.afficher(Saisie.lireEntier("Numéro du client à afficher : "));
				
			} else if (rep ==5){ 
				annuaire.supprimer(Saisie.lireEntier("Numéro du client à supprimer : "));
				
			} else if (rep ==6){ 
				annuaire.Crediter(Saisie.lireEntier("Numéro du client à créditer : "),
							Saisie.lireEntier("Montant à créditer : "));
				
			} else if (rep ==7){ 
				
				annuaire.afficherTotalSolde();
				
			}
		}
		
		
	}
}
