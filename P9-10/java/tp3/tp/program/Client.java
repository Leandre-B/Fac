package program;

public class Client {
    private int numeroClient;
    private int solde;
    private String nom;

    static int cptClient = 0;

    public Client(String nom){
        this.numeroClient = cptClient;
        cptClient++;
        this.solde = 0;
        this.nom = nom;
    }

    public String getNom() {
        return nom;
    }
    public int getNumeroClient() {
        return numeroClient;
    }
    public int getSolde() {
        return solde;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }
    public void setNumeroClient(int numeroClient) {
        this.numeroClient = numeroClient;
    }
    public void setSolde(int solde) {
        this.solde = solde;
    }

    public String toString() {
        return "Client :\nNumero : "+numeroClient+"\nNom : "+nom+"\nSolde : "+solde;
    }

    @Override
    public boolean equals(Object obj) {
        return nom == Client.class.cast(obj).getNom();
    }
}
    