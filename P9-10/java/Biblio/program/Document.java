public class Document{
    private String ref;
    private double prix;

    Document(String ref, double prix){
        this.ref = ref;
        this.prix = prix;
    }

    @Override
    public String toString() {
        return "ref : "+ref + " | prix : "+prix;
    }
}