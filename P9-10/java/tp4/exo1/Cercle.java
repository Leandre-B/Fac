public class Cercle extends FormeGeometrique{
    private Point centre;
    private int rayon;

    public Cercle(Point centre, int rayon){

    }

    @Override
    public String toString() {
        return nom+", centre : ("+centre.getX()+", "+centre.getY()+"), rayon : "+rayon;
    }

    public double perimetre(){
        return (3.14 * rayon * 2);
    }

    public void translation(double vx, double vy) {
        centre.translation(vx, vy);
    }

}
