public class Rectangle extends Forme{
    protected int longueur;
    protected int largeur;


    Rectangle(int x, int y, int lon, int lar){
        super(x, y);
        longueur = lon;
        largeur = lar;
    }

    public String toString(){
        return "rectangle " + x + " " + y + " "+ longueur + " " +largeur; 
    }
}
