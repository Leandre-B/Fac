public class CompareAge implements Compare{

	public boolean inf (Object x, Object y){
		Joueur j1=(Joueur)x;
		Joueur j2=(Joueur)y;
		return j1.getAge() < j2.getAge();
	}


}