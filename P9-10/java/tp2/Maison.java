/**
 * La classe Maison représente un maison (hérite de batiments)
 * @author Xxx_Léandre_xxX
 * @version 1.16.1
 */

public class Maison extends Batiment {
    /**
     * Indique le nombre de pieces dans la maison
     */
    private int nbPieces;
    /**
     * indique la surface du jardin
     */
    private int surfaceJardin;

    /**
     * Seul constructeur
     * @param adresse addresse de la maison
     * @param surfaceHabitable surface habitable
     * @param surfaceJardin surface du jardin
     * @param nbPieces nombre de pièces dans la maison
     */
    Maison(String adresse, int surfaceHabitable, int surfaceJardin, int nbPieces){
        super(adresse, surfaceHabitable);
        this.surfaceJardin=surfaceJardin;
        this.nbPieces=nbPieces;
    }
    
    /**
     * Renvoie une description de la classe sous une String
     */
    public String toString() {
        return super.toString()+"nbPieces : "+nbPieces+"\nsurfaceJardin : "+surfaceJardin+"\n";
    }

    /**
     * Getteur pour surfaceJardin
     * @return la surface du jardin
     */
    public int getSurfaceJardin(){
        return surfaceJardin;
    }

}
