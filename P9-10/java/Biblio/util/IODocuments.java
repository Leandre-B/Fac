package util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.concurrent.ExecutionException;

import program.*;

public class IODocuments {
    
    static public ArrayList<Document> lire(String filename) throws IOException{
        BufferedReader in = null ;
        ArrayList<Document> documents = new ArrayList<Document>();
        try {
            in = new BufferedReader (new FileReader(filename));
            String ligne = null ;
            ligne = in.readLine();
            while ((ligne = in.readLine())!= null ) {
                String[] tokens = ligne.split(",");

                if(tokens[0].equals("Livre")){


                    documents.add(new Livre(tokens[1], Double.parseDouble(tokens[2]), Integer.parseInt(tokens[3])));
                }
                else if(tokens[0].equals("Video")){
                    documents.add(new Video(tokens[1], Double.parseDouble(tokens[2]), (tokens[4])));
                }
            }
        }
        catch(Exception e){
            System.err.println(e.getMessage());
        }
        finally {
            if (in != null) {
                in.close();
            }
        }

        return documents;
    }

    static public void sauver(ArrayList<Consultable> cons, String fileName){
        PrintWriter out = null ;
        try {
            out = new PrintWriter(new FileWriter(fileName+".csv"));
            for (Consultable c : cons) {
                out.println(c.toString());
            }
        } catch(Exception e){
            System.err.println(e.getMessage());
        }finally {
            if ( out != null ) {
                out.close();
            }
        }
    }
}
