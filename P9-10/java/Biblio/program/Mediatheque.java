package program;

import java.lang.annotation.Documented;
import java.util.ArrayList;

import javax.print.Doc;
import exeptions.*;

public class Mediatheque {
    private Client[] clients;
    private ArrayList<Document> documents;
    private String nom;

    Mediatheque(String nom){
        this.nom = nom;

        clients = new Client[100];
        for (int i = 0; i < 100; i++) {
            clients[0] = null;
        }

        documents = new ArrayList<Document>();
    }

    @Override
    public String toString() {
        String info = "nom : "+nom+"\n Clients : \n";
        int nbClient = 0;
        for (Client c : clients) {
            if(c != null){
                info += c.toString()+"\n";
                ++nbClient;
            }
        }
        info+="Total clients : "+nbClient+"\n";

        info+="Documents : ";
        for (Document d : documents) {
            info+=d.toString() + "\n";
        }

        return info;
    }

    public void ajouterClient(Client c) throws MediathequeException{
        int nbClient = 0;
        for (Client cl : clients) {
            if(cl.getId() == c.getId()){
                throw new MediathequeException();
            }
            if(c != null)
                nbClient++;
        }
        if(nbClient == 100){
            throw new MediathequeException();
        }

        for (int i=0; i<100; ++i) {
            if(clients[i] == null){
                clients[i] = c;
            }
        }
    }

    public void supprimerClientById(int id){
        int index = 0;
        boolean found = false;
        for (int i=0; i<100 && !found; ++i) {
            if(clients[i].getId() == id){
                clients[i] = null;
                index = i;
                found = true;
            }
        }

        //delete index i
        boolean end = false;
        for (int i=index; i<99 && !end; ++i) {

            if(clients[i+1] != null){
                clients[i] = clients[i+1];
            }else{
                end = true;
            }
        }
    }
}
