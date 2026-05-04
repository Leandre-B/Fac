public class Agence {
    private String nom;
    private int telephone;
    private int administratifs;
    public String commentaires; //"que n importe qui peut utiliser comme bon lui semble" -> public

    Agence(String nom, int telephone, int administratifs){
        this.nom=nom;
        this.telephone=telephone;
        this.administratifs=administratifs;
    }

    public int taillePersonnel(){
        return administratifs;
    }

    public void afficherAgence(){
        System.out.println("Agence - "+nom+" - "+telephone+" - "+administratifs+" adm");
    }
    public int getTelephone() {
        return telephone;
    }
    public String getNom() {
        return nom;
    }
    public int getAdministratifs() {
        return administratifs;
    }

}
