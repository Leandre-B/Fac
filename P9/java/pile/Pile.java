public class Pile {
	private Maillon m;

	Pile() {
		m = null;
	}

	public boolean estVide() {
		return this.m == null;
	}

	public Object sommet() {
		return m.getObject();
	}

	public void empiler(Object o) {
		if (estVide())
			this.m = new Maillon(o, null);
		else {
			Maillon m = new Maillon(o, this.m);
			this.m = m;
		}
	}

	public void depiler() {
		this.m = this.m.getSuiv();
	}

	public int sommeDepileEtSommeEntier() {
		int cpt = 0;
		while (!estVide()) {
			Object sommet = sommet();
			if (sommet instanceof Integer) {
				cpt += (Integer) sommet;
			}
			depiler();
		}
		return cpt;

	}

}