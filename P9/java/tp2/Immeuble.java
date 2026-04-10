public class Immeuble extends Batiment {
    private int nbAppart;

    Immeuble(String adresse, int surfaceHabitable, int nbAppart){
        super(adresse, surfaceHabitable);
        this.nbAppart = nbAppart;
    } 

    public String toString(){
        return super.toString() + "nbAppart : "+nbAppart+"\n";
    }
}
