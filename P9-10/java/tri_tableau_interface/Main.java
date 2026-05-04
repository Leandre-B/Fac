import java.util.Random;

public class Main {
	public static void main(String[] args) {
		Random rdm = new Random();
		Joueur[] t = new Joueur[20];
		for(int i=0; i<20; ++i){
			t[i] = new Joueur("Polo", rdm.nextInt(1000), 0, "partout");
		}

		TriGenerique.tri(t, new CompareAge());

		for(int i=0; i<20; ++i){
			System.out.println(t[i].getAge());
		}


	}
}