public class Main {
    public static void main(String[] args) {
        Agence agence = new Agence("Super agence", 0676767676, 21);
        Bureau bureau = new Bureau("Super bureau", 1234, 2, 100);
        Garage garage = new Garage("Super garage", 8418634, 78, 512);
    
        agence.afficherAgence();
        bureau.afficherBureau();
        garage.afficherGarage();

        System.out.println(bureau.nbGarages());
        bureau.ajoutGarage(garage);
        System.out.println(bureau.nbGarages());
        bureau.retraitGarage(garage);
        System.out.println(bureau.nbGarages());

    }
}
