class Main {
	public static void main(String[] args) {

		Pile pile = new Pile();
		pile.empiler(4);
		pile.empiler(10);
		pile.empiler('r');
		pile.empiler("coucou");
		pile.empiler(false);

		// System.out.println(pile.sommet());
		// pile.depiler();
		// System.out.println(pile.sommet());

		System.out.println(pile.sommeDepileEtSommeEntier());
	}
}