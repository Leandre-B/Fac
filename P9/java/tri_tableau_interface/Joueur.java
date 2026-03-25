public class Joueur {

	private String nom;
	private int age;
	private int score;
	private String addresse;

	Joueur(String nom, int age, int score, String addresse){
		this.nom=nom;
		this.age=age;
		this.score=score;
		this.addresse=addresse;
	}

	int getAge(){
		return this.age;
	}


}