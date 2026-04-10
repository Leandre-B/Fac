public class TestBatiment {
    public static void main(String[] args) {

        Batiment batiment = new Batiment("3 rue", 120);
        Maison maison = new Maison("8 place", 50, 20, 5);
        Immeuble immeuble = new Immeuble("5 sentier", 10, 0);

        // Batiment[] tabBatiment = new Batiment[3];
        // tabBatiment[0] = batiment;
        // tabBatiment[1] = maison;
        // tabBatiment[2] = immeuble;

        // for (Batiment b : tabBatiment) {
        //     System.out.println(b.toString());
        // }

        // Maison[] tabMaison = new Maison[1];
        // tabMaison[0] = maison;

        // System.out.println(surfaceHabitableTotale(tabBatiment));
        // System.out.println(surfaceJardinTotale(tabMaison));

        Quartier quartier = new Quartier(10);
        quartier.ajoutBatiment(batiment);

        // for (int i = 0; i < quartier.getNombreBat(); i++) {
        //     System.out.println(quartier.getBatiments()[i].toString());
        // }

        quartier.ajoutBatiment(maison);
        quartier.ajoutBatiment(immeuble);

        // for (int i = 0; i < quartier.getNombreBat(); i++) {
        //     System.out.println(quartier.getBatiments()[i].toString());
        // }

        // System.out.println(maison.categorie());
        // System.out.println(batiment.categorie());

        //quartier.afficherBatiments(1);

        System.out.println(maison.comparer(batiment).toString());


        System.out.println(quartier.plusGrandBatiments());



        
    }

    public static int surfaceHabitableTotale(Batiment[] tabBatiment){
        int tot = 0;
        for (Batiment b : tabBatiment) {
            tot+=b.getSurfaceHabitable();
        }
        return tot;
    } 

    public static int surfaceJardinTotale(Maison[] tabMaison){
        int tot = 0;
        for (Maison m : tabMaison) {
            tot+=m.getSurfaceJardin();
        }
        return tot;
    } 
}
