 /**
 * La classe Quartier regroupe des batiments dans un tableau.
 * @author Xxx_Léandre_xxX
 * @version 1.16.1
 */
public class Quartier {
    /**
     * batiments est un tableau contenant les batiments
     */
    private Batiment[] batiments;

    /**
     * nbBatiment contient le nombre de batiments dans le quartier
     */
    private int nbBatiment;

    /**
     * Unique constructeur
     * @param n pour la taille du tableau à initialiser
     */
    Quartier(int n){
        nbBatiment = 0;
        batiments = new Batiment[n];
    }

    /**
     * Ajoute un batiment au quatier
     * Renvoie vrai si le quartier n'est pas plein
     * Faux sinon
     * @param batiment le batiment à ajouter
     */
    public boolean ajoutBatiment(Batiment batiment){
        if(nbBatiment==this.batiments.length)
            return false;

        this.batiments[nbBatiment]=batiment;
        ++nbBatiment;
        return true;
    }

    public void afficherBatiments(int cat){
        for (int i = 0; i < nbBatiment; i++) {
            if(batiments[i].categorie()>=cat)
                System.out.println(batiments[i].toString());
        }
    }
    

    public Batiment[] getBatiments(){
        return batiments;
    }

    public int getNombreBat(){
        return nbBatiment;
    }

    /**
     * La methode plusGrandBatiments() retourne le plus grand batiment en fonction de sa surface habitable.
     * On suppose qu'il existe au moins un batiment.
     * @author Xxx_Léandre_xxX
     * @version 1.16.1
     */
    public Batiment plusGrandBatiments(){
        Batiment max = batiments[0];
        for (int i = 1; i < nbBatiment; i++) {
            if(batiments[i].getSurfaceHabitable()>max.getSurfaceHabitable())
                max=batiments[i];
        }
        return max;
    }
}
