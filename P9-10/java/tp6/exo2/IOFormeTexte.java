import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;

public class IOFormeTexte implements IOForme{
    public Collection <Forme> lire (String filename) throws IOException{
        Collection <Forme> formes = new ArrayList<Forme>();
        BufferedReader in = null ;
        try {
            in = new BufferedReader (new FileReader(filename)) ;
            String ligne = null ;
            while (( ligne = in.readLine()) != null) {
                String[] infos = ligne.split(" ");
                if(infos[0].equals("rectangle")){
                    formes.add(new Rectangle(Integer.parseInt(infos[1]), Integer.parseInt(infos[2]), Integer.parseInt(infos[3]), Integer.parseInt(infos[4])));
                }else if(infos[0].equals("cercle")){
                    formes.add(new Cercle(Integer.parseInt(infos[1]), Integer.parseInt(infos[2]), Integer.parseInt(infos[3])));
                }else{
                    System.out.println("Unknowed forme \""+infos[0]+"\"");
                }
            }
        }finally{
            if(in != null){
                in.close();
            }
        }
        //formes.add(new Rectangle(0, 0, 0, 0));
        return formes;   
    }

    public void sauver (Collection <Forme> formes , String filename ) throws IOException{
        PrintWriter out = null;
        try {
            out = new PrintWriter(new FileWriter(filename)) ;
            for (Forme f : formes) {
                out.println(f.toString());
            }    
        }finally{
            if (out != null) {
                out.close() ;
            }
        }
    }
}
