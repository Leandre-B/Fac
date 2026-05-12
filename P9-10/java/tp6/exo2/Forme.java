import java.io.Serializable;

public abstract class Forme implements Serializable {
    private static final long serialVersionUID = 4L ;
    protected int x;
    protected int y;

    Forme(int x, int y){
        this.x = x;
        this.y = y;
    }
}
