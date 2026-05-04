public class Point implements Translation{
    private double x;
    private double y;

    public Point(double x, double y){
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double distance(Point p){
        return Math.sqrt(Math.pow(x-p.getX(), 2) + Math.pow(y-p.getY(), 2));
    }

    @Override
    public void translation(double vx, double vy) {
        x+=vx;
        y+=vy;
    }
}

