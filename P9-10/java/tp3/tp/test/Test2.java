package test;

import program.Annuaire;
import program.Client;

public class Test2 {

	public static void main(String[] args) {
        Client c1 = new Client("Bob");
        Client c2  = new Client ("Bob");

        Annuaire annuaire = new Annuaire();
        annuaire.ajouterClient(c1);
        System.out.println(annuaire.contient(c2));

    }
}