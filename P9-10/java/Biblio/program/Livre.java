package program;

public class Livre extends Document{
    int nbPages;

    public Livre(String ref, double prix, int nbPages){
        super(ref, prix);
        this.nbPages = nbPages;
    }

    @Override
    public String toString() {
        return super.toString() + " nbPages : " + nbPages;
    }
}
