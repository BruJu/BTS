public class Noeud<T extends Comparable<T>> {
	private T element;
	private Noeud<T> filsGauche = null;
	private Noeud<T> filsDroit = null;

	public Noeud(T element) {
		this.element = element;
	}

	public void inserer(T element) {
		if (this.element.equals(element)) {
			return;
		} else if (this.element.compareTo(element) < 0) {
			if (filsGauche == null) {
				filsGauche = new Noeud<>(element);
			} else {
				filsGauche.inserer(element);
			}
		} else {
			if (filsDroit == null) {
				filsDroit = new Noeud<>(element);
			} else {
				filsDroit.inserer(element);
			}
		}

	}

	public boolean contient(T element) {
		if (this.element.equals(element)) {
			return true;
		} else {
			if (this.element.compareTo(element) < 0) {
				return filsGauche == null ? false : filsGauche.contient(element);
			} else {
				return filsDroit == null ? false : filsDroit.contient(element);
			}
		}
	}
}
