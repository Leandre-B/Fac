package program;

import java.util.ArrayList;
import java.util.Collections;

import javax.print.Doc;

import exeptions.*;
import util.IODocuments;

public class Mediatheque {
    private Client[] clients;
    private ArrayList<Document> documents;
    private String nom;

    public Mediatheque(String nom){
        this.nom = nom;

        clients = new Client[100];
        for (int i = 0; i < 100; i++) {
            clients[i] = null;
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

        // info+="Documents : ";
        // for (Document d : documents) {
        //     info+=d.toString() + "\n";
        // }

        return info;
    }

    public void ajouterClient(Client c) throws MediathequeException{
        for (int i=0; i<100; ++i) {
            if(clients[i] != null){
                if(clients[i].getId() == c.getId()){
                    throw new MediathequeException();
                }
            }else{
                clients[i] = c;
                return;
            }
        }
        throw new MediathequeException();
    }

    public void supprimerClientById(int id) throws MediathequeException{
        int index = 0;
        boolean found = false;
        for (int i=0; i<100 && !found; ++i) {
            if(clients[i] != null){
                if(clients[i].getId() == id) {
                    clients[i] = null;
                    index = i;
                    found = true;
                }
            }
        }
        if(!found)
            throw new MediathequeException();
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


    public void afficherDocumentSorted(){

        for (Document d : documents) {
            System.out.println(d.toString());
        }

        ArrayList<Document> doc_aux = documents;
        Collections.sort(doc_aux);
        for (Document d : doc_aux) {
            System.out.println(d.toString());
        }
    }

    public void ajouterDocumentsFromFile(String fileName){
        ArrayList<Document> doc = new ArrayList<Document>();
        try {
            doc = IODocuments.lire(fileName);
            for (Document d : doc) {
                documents.add(d);
            }
        } catch (Exception e) {
            System.err.println("Probleme");
        }

    }

    public void saveConsultable(){
        ArrayList<Consultable> cons = new ArrayList<Consultable>();
        for (Document d : documents) {
            if(d instanceof Consultable)
                if(((Consultable)d).estConsultable())
                    cons.add((Consultable)d);
        }
        IODocuments.sauver(cons, nom);
    }

    public void supprimerDocument(String ref ) throws MediathequeException{
        for (int i=0; i<documents.size(); ++i) {
            if(documents.get(i).getRef().equals(ref)){
                documents.remove(i);
                return;
            }
        }
        throw new MediathequeException();
    }
}
