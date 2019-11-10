public class ABR<T extends Comparable<T>> {
	private Noeud<T> racine = null;

	public boolean contient(T element) {
		if (racine == null) {
			return false;
		} else {
			return racine.contient(element);
		}
	}

	public void inserer(T element) {
		if (racine == null) {
			racine = new Noeud<>(element);
		} else {
			racine.inserer(element);
		}
	}
}
