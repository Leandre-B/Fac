public class Main {
    public static void main(String[] args) {
        Tonneau t1 = new Tonneau("Tonneau 1", 5, 1, null);
        Tonneau t2 = new Tonneau("Tonneau 2", 12, 4, t1);
        
        t2.setBouchon(false);
        t1.setBouchon(false);

        t2.run();
        t1.run();

        try {
            t1.join();
            t2.join();System . out . println ( " Fin de la partie " ) ;
        } catch ( InterruptedException e ) {
            e.printStackTrace () ;
        }

    }
}
