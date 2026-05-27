package test;

import program.*;
import java.util.ArrayList;

public class Gestionnaire {
    public static void main(String[] args) {
        ArrayList<Mediatheque> mediatheques = new ArrayList<Mediatheque>();
        mediatheques.add(new Mediatheque("Mediatheque 1"));
        mediatheques.add(new Mediatheque("Mediatheque 2"));

        mediatheques.get(0).ajouterDocumentsFromFile("/home/leand/Fac/P9-10/java/Biblio/biblio1.csv");
        mediatheques.get(1).ajouterDocumentsFromFile("/home/leand/Fac/P9-10/java/Biblio/biblio2.csv");

        for(int i=1; i<=10; ++i){
            try{
                if(i<=5)
                    mediatheques.get(0).ajouterClient(new Client("client"+i));
                else
                    mediatheques.get(1).ajouterClient(new Client("client"+i));
            }catch(Exception e){
                System.err.println(e.getMessage());
            }
        }

        System.out.println(mediatheques.get(0).toString());
        System.out.println(mediatheques.get(1).toString());

        //mediatheques.get(1).afficherDocumentSorted();

        //test suppression
        try{
            mediatheques.get(0).supprimerClientById(2);
        }catch(Exception e){
            System.err.println("Suppresion impossible !");
        }

        try{
            mediatheques.get(1).supprimerClientById(2);
        }catch(Exception e){
            System.err.println("Suppresion impossible !");
        }

        //test ajout

        try{
            mediatheques.get(1).ajouterClient(new Client("Benoit"));
        }catch(Exception e){
            System.err.println("ajout client impossible ! ");
        }

        try{
            mediatheques.get(1).ajouterClient(new Client("Raymond"));
        }catch(Exception e){
            System.err.println("ajout client impossible ! ");
        }

        mediatheques.get(0).saveConsultable();
        mediatheques.get(1).saveConsultable();

    }
}
 