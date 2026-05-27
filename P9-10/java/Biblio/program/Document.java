package program;

public class Document implements Comparable<Document>{
    private String ref;
    private double prix;

    protected Document(String ref, double prix){
        this.ref = ref;
        this.prix = prix;
    }

    @Override
    public String toString() {
        return "ref : "+ref + " | prix : "+prix;
    }

    public double getPrix() {
        return prix;
    }

    public String getRef() {
        return ref;
    }

    @Override
    public int compareTo(Document d) {
        if(d.getPrix() > prix)
            return -1;
        if(d.getPrix() < prix)
            return 1;
        return 0;
    }
}