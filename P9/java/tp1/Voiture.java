public class Voiture extends Vehicule{


    private boolean autoradio;

    Voiture(String modele, int anneeAchat, float prix, String immatriculation, char permis, boolean autoradio){
        super(modele, anneeAchat, prix, immatriculation, permis);
        this.autoradio = autoradio;
    }

    public void ajouterAutoradio(){
        autoradio=true;
    }


    public void enleverAutoradio(){
        autoradio=false;
    }

    public void afficherVoiture(){
        super.afficherVehicule();
        if(autoradio)
            System.out.println("A un super autoradio !");
        else
            System.out.println("N'a pas d'autoradio !");
    }
}
