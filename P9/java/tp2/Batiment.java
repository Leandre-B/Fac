
public class Batiment {
    private String adresse;
    private int surfaceHabitable;

    Batiment(String adresse, int surfaceHabitable){
        this.adresse=adresse;
        this.surfaceHabitable=surfaceHabitable;
    }

    public String toString(){
        return "Classe : "+getClass().getName()+"\n"+"Adresse : "+adresse+"\nsurfaceHabitable : "+surfaceHabitable+"\n";
    }

    public int getSurfaceHabitable(){
        return surfaceHabitable;
    }

    public int categorie(){
        if(surfaceHabitable<30)
            return 1;
        if(surfaceHabitable<70)
            return 2;
        return 3;
    }

    public Batiment comparer(Batiment b){
        return (b.getSurfaceHabitable() > surfaceHabitable) ?  b : this;
    }
}
