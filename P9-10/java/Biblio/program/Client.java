package program;

public class Client {

    private static int totalId = 0;
    private String nom;
    private int id;

    Client(String nom){
        this.nom = nom;
        this.id = totalId;
        totalId++;
    }

    public int getId() {
        return id;
    }

    @Override
    public String toString() {
        return "id : "+id+" nom : "+nom;
    }
}
