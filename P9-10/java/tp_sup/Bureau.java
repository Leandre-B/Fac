public class Bureau extends Agence{
    private int commerciaux;
    private Garage[] garages;

    Bureau(String nom, int telephone, int administratifs, int commerciaux){
        super(nom, telephone, administratifs);
        this.commerciaux=commerciaux;
        garages = new Garage[4];
        for (int i=0; i<garages.length; ++i) {
            garages[i]=null;            
        }
    }

    public int getCommerciaux() {
        return commerciaux;
    }

    public int taillePersonnel(){
        return super.taillePersonnel()+commerciaux;
    }

    //on suppose que pas plein
    public void ajoutGarage(Garage g){
        for (int i = 0; i < garages.length; i++) {
            if(garages[i]==null){
                garages[i]=new Garage(g.getNom(), g.getTelephone(), g.getAdministratifs(),g.getMechaniciens());
                return;
            }
        }
    }

    //on suppose que pas vide
    public void retraitGarage(Garage g){
        for (int i = 0; i < garages.length; i++) {
            if(garages[i].getNom() == g.getNom()){  
                garages[i]=null;
                return;
            }
        }
    }

    public int nbGarages(){
        int n=0;
        for (Garage garage : garages) {
            if(garage!=null)
                ++n;
        }
        return n;
    }

    public int nbMecaniciens(){
        int mech=0;
        for (Garage garage : garages) {
            if(garage!=null)
                mech+=garage.getMechaniciens();
        }
        return mech;
    }

    public void afficherBureau(){
        System.out.println("Bureau de location - "+super.getNom()+" - "+super.getTelephone()+" - "+super.getAdministratifs()+" adm - "+commerciaux+ "comm");
    }
}
