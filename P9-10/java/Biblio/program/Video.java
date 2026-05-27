package program;

public class Video extends Document implements Consultable{
    String url;
    
    public Video(String ref, double prix, String url){
        super(ref, prix);
        this.url = url;
    }

    @Override
    public boolean estConsultable() {
        return url!="";
    }

    @Override
    public String toString() {
        return super.toString() + " url : " + url;
    }
}
