import java.io.File;

public class Main {
    public static void main(String[] args) {
        
        program(args[0]);

    }

    public static void program(String file_name){
        File f = new File(file_name);
        if(f.exists()){
            if(f.isDirectory()){
                System.out.println("Le fichier est un repertoire.");
                for (File file : f.listFiles()) {
                    System.out.println(file.getName());
                }
            }
            else if (f.isFile()){
                System.out.println("Le fichier est un repertoire.");
                System.out.println("Chemin : " + f.getAbsolutePath());
                System.out.println("Taille : " + f.length() + " octects");
            }
        }else{
            System.out.println("Le fichier \""+file_name+"\" n'existe pas.");
        }
    }
}
