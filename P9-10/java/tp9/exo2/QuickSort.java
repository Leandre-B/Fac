public class QuickSort extends Thread{
    private int[] values;
    private int d;
    private int f;

    QuickSort(int[] values, int d, int f){
        this.values=values;
        this.d=d;
        this.f=f;
    }

    public int partitionner(){
        int j = d;
        for (int i = d; i < f; i++) {
            if(values[i]<values[f]){
                int aux = values[i];
                values[i] = values[j];
                values[j] = aux;
                ++j;
            }
        }
        int aux = values[j];
        values[j] = values[f];
        values[f] = aux;
        return j;
    }

    public void run(int[] values, int d, int f){
        if(d<f){
            int p = this.partitionner();
            QuickSort s1 = new QuickSort(values, d, p-1);
            QuickSort s2 = new QuickSort(values, p+1, f);

            s1.run();
            s2.run();

            try {
                s1.join();
                s2.join();
            } catch ( InterruptedException e ) {
                e.printStackTrace () ;
            }
        }
    }
}   