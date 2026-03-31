public class Camion extends Vehicule{
    private double volume;

    Camion(String modele, int anneeAchat, float prix, String immatriculation, char permis, double volume){
        super(modele, anneeAchat, prix, immatriculation, permis);
        this.volume = volume;
    }

    public boolean peutTransporterVolume(double volume){
        return volume<=this.volume;
    }

    public void afficherCamion(){
        super.afficherVehicule();
        System.out.println("VOLUME DE "+volume+"!!!");
    }
}
