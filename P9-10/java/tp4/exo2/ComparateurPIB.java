import java.util.Comparator;

public class ComparateurPIB implements Comparator<Region>{
    
    @Override
    public int compare(Region r1, Region r2) {
        if(r1.getPib()<r2.getPib())
            return -1;
        if(r1.getPib() > r2.getPib())
            return 1;
        return 0;
    }
}
