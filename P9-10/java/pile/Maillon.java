public class Maillon {
	private Object o;
	private Maillon suiv;

	Maillon(Object o, Maillon suiv) {
		this.o = o;
		this.suiv = suiv;
	}

	public void setSuiv(Maillon m) {
		this.suiv = m;
	}

	public void setObject(Object o) {
		this.o = o;
	}

	public Maillon getSuiv() {
		return this.suiv;
	}

	public Object getObject() {
		return this.o;
	}

}