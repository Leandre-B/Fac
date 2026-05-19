public class Tonneau extends Thread{

    public static int VMAX = 12;

    private String nom;
    private int volume;
    private int debit;
    private Tonneau target;
    private boolean bouchon = true;

    Tonneau(String nom, int volume, int debit, Tonneau target){
        this.nom=nom;
        this.volume=volume;
        this.debit=debit;
        this.target=target;
    }

    public void ajouterVolume(int vol){
        System.out.println(nom + " : ajout");
        if(volume + vol >= VMAX){
            System.out.println("      Débordement !");
            volume = VMAX;
        }
        else
            volume+=vol;
        System.out.println("      curr volume : "+volume+"\n");
    }

    public void retirerVolume(int vol){
        System.out.println(nom + " : fuite");
        if(volume - vol <= 0) {
            System.out.println("      Fuite !");
            volume = 0;
        }else
            volume-=vol;
        System.out.println("      curr volume : "+volume+"\n");
    }

    private synchronized void deverser(){
        int vol_before = volume;
        retirerVolume(debit);
        if(target != null)
            target.ajouterVolume(vol_before - volume);
    }

    public void run(){ 
        while(volume!=0){
            if(bouchon == false)
                deverser();

            try {
                sleep(1000);
            } catch ( InterruptedException e ) {
                e.printStackTrace () ;
            }
        }
    }
    public void setBouchon(boolean bouchon) {
        this.bouchon = bouchon;
    }
}