public class Autocar extends Camion {
    private int nbPassagers;
    
    Autocar(String modele, int anneeAchat, float prix, String immatriculation, char permis, double volume, int nbPassagers){
        super(modele, anneeAchat, prix, immatriculation, permis, volume);
        this.nbPassagers = nbPassagers;
    }

    public boolean peutTransporterPassagers(int nbPassagers, double volumeMoyen){
        if(nbPassagers>this.nbPassagers)
            return false;
        return (peutTransporterVolume(nbPassagers*volumeMoyen));
    }
}
