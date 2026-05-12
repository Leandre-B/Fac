import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
public class Main {
    public static void main(String[] args) {

        Collection<Forme> formes = new ArrayList<Forme>();
        // formes.add(new Rectangle(10, 5, 20, 20));
        // formes.add(new Rectangle(-1, 2, 10, 4));
        // formes.add(new Cercle(4, -1, -60));
        // formes.add(new Cercle(7, 6, 100));
        // formes.add(new Cercle(9, -10, 1));

        
        // ====  Read and Write in txt format ====
        IOFormeTexte io_f_txt = new IOFormeTexte();
        // try{
        //     io_f_txt.sauver(formes, "formes.txt");
        // }catch(IOException e){
        //     System.out.println("Cannot write to file\"formes.txt\"");
        // }

        try{
             formes = io_f_txt.lire("formes.txt");
        }catch(IOException e){
            System.out.println("Cannot read file\"formes.txt\"");
        }

        System.out.println("Formes lu a partir du fichier txt : ");
        for (Forme f : formes) {
            System.out.println(f.toString());
        }
        System.out.println("\n");

        // ====  Read and Write in binary format ====
        IOFormeBinaire io_f_bin = new IOFormeBinaire();
        try{
            io_f_bin.sauver(formes, "formes_bin");
        }catch(IOException e){
            System.out.println("Cannot write to file\"formes_bin\"");
        }

        Collection<Forme> formes2 = new ArrayList<Forme>();
        try{
             formes2 = io_f_bin.lire("formes_bin");
        }catch(IOException e){
            System.out.println("Cannot read file \"formes_bin\"");
        }


        for (Forme f : formes2) {
            System.out.println(f.toString());
        }

    }
}
