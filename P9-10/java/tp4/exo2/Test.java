import java.util.ArrayList;

public class Test {
    public static void main(String[] args) {
        ArrayList<Region> regions = new ArrayList<Region>();
        regions.add(new Region("Centre-Val de Loire",2566759 ,70 ,39151));
        regions.add(new Region("Bretagne",3329395 ,92 ,27208));
        regions.add(new Region("Ile-de-France",12213364 ,669 ,12011));
        regions.add(new Region("Auvergne-Rhône-Alpes",8026685 ,250 ,69711));

        for (Region region : regions) {
            System.out.println(region.toString());
        }

        System.out.println(regions.get(0).compareTo(regions.get(1)));

        ComparateurDensite cpDens = new ComparateurDensite();
        ComparateurPIB cpPib = new ComparateurPIB(); 

        System.out.println(cpPib.compare(regions.get(0), regions.get(1)));
        System.out.println(cpDens.compare(regions.get(0), regions.get(1)));
    }
}
