public class Triangle extends Polygone{
    private Point a, b, c;

    public Triangle(Point a, Point b, Point c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public double perimetre() {
        return a.distance(b) + b.distance(c) + c.distance(a);
    }

    @Override
    public String toString() {
        return "Je suis un triangle";
    }

    public void translation(double vx, double vy) {
        a.translation(vx, vy);
        b.translation(vx, vy);
    }

}
