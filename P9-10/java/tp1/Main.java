public class Main{
    public static void main(String[] args){

        Voiture v1 = new Voiture("Twingo", 2026, 10000, "AB-123-CD,", 'B', true);
        v1.afficherVoiture();

        Camion c1 = new Camion("J9", 2008, 20000, "1234-AB-56", 'B', 25);
        c1.afficherCamion();
        System.out.println(c1.peutTransporterVolume(7));

        System.out.println(v1.coutLocation());
        System.out.println(c1.coutLocation());


        Autocar autocar = new Autocar("FRI", 2005, 90000, "123-AB-45", 'D', 5, 53);
        System.out.println(autocar.peutTransporterPassagers(40, 0.1));
    }   

}
