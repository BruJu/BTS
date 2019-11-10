public class Main {

    public static void main(String[] args) {
    	ABR<Integer> abr = new ABR<>();

    	System.out.println(abr.contient(7));

    	abr.inserer(7);
		abr.inserer(33);
		abr.inserer(12);
		abr.inserer(6);

		System.out.println(abr.contient(7));
		System.out.println(abr.contient(5));
		System.out.println(abr.contient(33));
		System.out.println(abr.contient(11));
    }
}
