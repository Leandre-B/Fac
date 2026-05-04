import java.lang.String;

public class Vehicule {
    private String modele;
    private int anneeAchat;
    private float prix;
    private String immatriculation;
    private char permis;

    Vehicule(String modele, int anneeAchat, float prix, String immatriculation, char permis){
        this.modele=modele;
        this.anneeAchat=anneeAchat;
        this.prix=prix;
        this.immatriculation=immatriculation;
        this.permis=permis;

    }

    public int age(){
        return 2026-anneeAchat;
    }
    
    public void afficherVehicule(){
        System.out.println(modele + " acheté(e) en "+anneeAchat+" a "+prix+ " euros, immat \""+immatriculation+ "\" nécéssite permis "+permis+".");
    }

    public float coutLocation(){
        if(this.age()<1)
            return prix/200;
        else
            return prix/250;
    }


}
