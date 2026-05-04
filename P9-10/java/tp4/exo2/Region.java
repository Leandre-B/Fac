public class Region implements Comparable<Region>{
    private String nom;
    private int nb_hab;
    private int pib;
    private int superficie;
    
    Region(String nom, int nb_hab, int pib, int superficie){
        this.nom = nom;
        this.nb_hab = nb_hab;
        this.pib = pib;
        this.superficie = superficie;
    }

    public int getNb_hab() {
        return nb_hab;
    }
    public String getNom() {
        return nom;
    }
    public int getPib() {
        return pib;
    }
    public int getSuperficie() {
        return superficie;
    }
    
    @Override
    public String toString() {
        return "Je suis "+nom;
    }

    @Override
    public int compareTo(Region r) {
        return (nom.compareTo(r.getNom()));
    }
}
