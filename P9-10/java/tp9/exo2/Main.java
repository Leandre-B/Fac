public class Main {
    public static void main(String[] args) {
        int NMAX = 100000000;
        int[] values = new int[NMAX];
        for (int i = 0; i < NMAX; i++) {
            values[i] = (int)Math.floor(Math.random()*1000);
            //System.out.print(values[i]+" ");
        }
        //System.out.println();

        System.out.println("En train de trier...");
        QuickSort quickSort = new QuickSort(values, 0, NMAX-1);
        quickSort.run();
        try {
            quickSort.join();
        } catch ( InterruptedException e ) {
            e.printStackTrace () ;
        }

        for (int i = 0; i < NMAX; i++) {
            //System.out.print(values[i]+" ");
        }
        System.out.println("Trié !");
    }
}
