public class Garage extends Agence{
    private int mechaniciens;

    Garage(String nom, int telephone, int administratifs, int mechaniciens){
        super(nom, telephone, administratifs);
        this.mechaniciens=mechaniciens;
    }


    public int taillePersonnel(){
        return super.taillePersonnel()+mechaniciens;
    }

    //on suposse que pas plein
    public void ajoutBureau(Bureau b){
        b.ajoutGarage(this);
    }

    public void retraitBureau(Bureau b){
        b.retraitGarage(this);
    }

    public int getMechaniciens() {
        return mechaniciens;
    }

    public void afficherGarage(){
        System.out.println("Bureau de location - "+super.getNom()+" - "+super.getTelephone()+" - "+super.getAdministratifs()+" adm - "+mechaniciens+ "mech");
    }
}
