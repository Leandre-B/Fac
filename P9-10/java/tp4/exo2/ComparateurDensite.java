import java.util.Comparator;

public class ComparateurDensite implements Comparator<Region>{
    
    @Override
    public int compare(Region r1, Region r2) {
        double d1 = r1.getNb_hab() / r1.getSuperficie();
        double d2 = r2.getNb_hab() / r2.getSuperficie();
        if(d1 < d2)
            return -1;
        if(d1 > d2)
            return 1;
        return 0;
    }
}
