import java.lang.reflect.Array;
import java.util.Scanner;

public class Calculatrice {

    private String[] ope_admissible = {"+", "-", "*", "/"};
    
    public double saisieNombre(){
        System.out.println("Saisir un nombre : ");
        Scanner sc = new Scanner(System.in);
        double in = sc.nextDouble();
        sc.nextLine();
        return in;
    }

    public double lancementCalcul(){
        Boolean good = false;
        double nb_1=0, nb_2=0;

        // GET 1er NOMBRE
        while(!good){
            try{
                nb_1 = saisieNombre();
                good = true;
            }catch(Exception e){
                System.err.println("ERREUR : Le nombre saisie n'est pas un nombre.");
            }
        }


        // GET OPERATION
        good = false;
        String ope = "";
        while(!good){
            try{
                boolean is_ope = false;
                ope = saisieOperation();
                for (String c : ope_admissible) {
                    if (c.equals(ope))
                        is_ope  = true;
                }
                if(!is_ope)
                    throw new OperationException(ope + " n'est pas une opération valide.");
                else
                    good = true;
            }
            catch(Exception e){
                System.err.println(
                    e.getClass().getName() + " : " + e.getMessage()
                );
            }
        }

        // GET 2ème NOMBRE
        good = false;
        while(!good){
            try{
                nb_2 = saisieNombre();
                good = true;
            }catch(Exception e){
                System.err.println("ERREUR : Le nombre saisie n'est pas un nombre.");
            }
        }

        if(ope.equals("/"))
            return nb_1 / nb_2;
        if(ope.equals("*"))
            return nb_1 * nb_2;
        if(ope.equals("+"))
            return nb_1 + nb_2;
        if(ope.equals("-"))
            return nb_1 - nb_2;

        return 0;

    }

    public String saisieOperation(){
        System.out.println("Saisir une operation : ");
        Scanner sc = new Scanner(System.in);
        String in = sc.next();
        sc.nextLine();
        return in;
    }
}
