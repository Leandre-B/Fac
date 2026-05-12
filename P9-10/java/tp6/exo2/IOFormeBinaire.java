import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collection;

public class IOFormeBinaire implements IOForme {
    public Collection <Forme> lire (String filename) throws IOException{

        Collection <Forme> formes = new ArrayList<Forme>();
        ObjectInputStream ois = new ObjectInputStream (
            new FileInputStream (filename)
        );
        try{
            while (true){

                // Simple
                formes.add((Forme)ois.readObject());

                // Horrible
                // String ligne = ois.readObject().toString();
                // String[] infos = ligne.split(" ");

                // if(infos[0].equals("rectangle")){
                //     formes.add(new Rectangle(
                //         Integer.parseInt(infos[1]), 
                //         Integer.parseInt(infos[2]), 
                //         Integer.parseInt(infos[3]), 
                //         Integer.parseInt(infos[4]))
                //     );
                // }
                // else if(infos[0].equals("cercle")){
                //     formes.add(new Cercle(
                //         Integer.parseInt(infos[1]), 
                //         Integer.parseInt(infos[2]), 
                //         Integer.parseInt(infos[3]))
                //     );
                // }
                // else{
                //     System.out.println("Unknowed forme \""+infos[0]+"\"");
                // }
            }
        } catch ( ClassNotFoundException cnf ){
            // erreur de lecture
        } catch (EOFException eof) {
            // fin de fichier
        }
        ois.close();
        return formes;
    }
    public void sauver (Collection <Forme> formes , String filename ) throws IOException{
        try {
            
            ObjectOutputStream oos = new ObjectOutputStream (
                new FileOutputStream (filename)
            );
            for (Forme f : formes) {
                oos.writeObject(f);
            }
            oos.close () ;
        } catch ( Exception e ) {
            e.getStackTrace();
        }

    }
}
