public class Rectangle extends Polygone implements Translation{
    /*
     * A-----B
     * |     |
     * C-----D
     */
    private Point a, b, c, d;

    public Rectangle(Point p, double longueur, double largeur){
        //p  = A
        a = new Point(p.getX(), p.getY());
        b = new Point(p.getX() + longueur, p.getX());
        c = new Point(p.getX(), p.getY()+largeur);
        d = new Point(p.getX() + longueur, p.getY() + largeur);
    }

    @Override
    public double perimetre() {
        return a.distance(b) + b.distance(d);
    }

    @Override
    public String toString() {
        return "Je suis un rectangle";
    }

    @Override
    public void translation(double vx, double vy) {
        a.translation(vx, vy);
        b.translation(vx, vy);
        c.translation(vx, vy);
        d.translation(vx, vy);
    }


}
