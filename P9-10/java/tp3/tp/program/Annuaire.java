package program;
import java.util.ArrayList;
import java.util.List;


public class Annuaire {

    List<Client> liste;

    public Annuaire(){
        liste = new ArrayList<Client>();
    }
	
    public void ajouterClient(String nom){
        liste.add(new Client(nom));
    }

    public void ajouterClient(Client c){
        liste.add(c);
    }

//A completer
    public void afficherTaille(){
        System.out.println(liste.size());
    }

    public void afficher(){
        for (Client client : liste) {
            System.out.println(client.toString());
        }
    }

    public void afficher(int numeroClient){
        for (Client client : liste) {
            if(client.getNumeroClient() == numeroClient){
                System.out.println(client.toString());
                return;
            }
        }
    }

    public void supprimer(int numeroClient){
        for (Client client : liste) {
            if(client.getNumeroClient() == numeroClient){
                liste.remove(client);
                return;
            }
        }
    }

    public void Crediter(int numeroClient, int a_crediter){
        for (Client client : liste) {
            if(client.getNumeroClient() == numeroClient){
                client.setSolde(client.getSolde() + a_crediter);
                return;
            }
        }
    }

    public void afficherTotalSolde(){
        int tot = 0;
        for (Client client : liste) {
            tot+=client.getSolde();
        }
        System.out.println(tot);
    }

    public Boolean contient(Client c){
        return liste.contains(c);
    }



}
