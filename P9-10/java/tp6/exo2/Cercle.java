public class Cercle extends Forme{
    protected int rayon;


    Cercle(int x, int y, int r){
        super(x, y);
        rayon = r;
    }

    public String toString(){
        return "cercle "+ x + " " + y + " "+ rayon; 
    }
}
