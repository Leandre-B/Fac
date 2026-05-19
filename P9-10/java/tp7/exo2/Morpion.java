import java.awt.GridLayout;
import javax.swing.JFrame;

public class Morpion {
    public static void main(String[] args) {
        Game game = new Game(1);
        JFrame window = new JFrame();

        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setSize(800, 800);

        window.setLayout(new GridLayout(3, 3));
        CaseMorpion caseMorpion00 = new CaseMorpion(game, 0, 0);
        CaseMorpion caseMorpion01 = new CaseMorpion(game, 0, 1);
        CaseMorpion caseMorpion02 = new CaseMorpion(game, 0, 2);
        CaseMorpion caseMorpion10 = new CaseMorpion(game, 1, 0);
        CaseMorpion caseMorpion11 = new CaseMorpion(game, 1, 1);
        CaseMorpion caseMorpion12 = new CaseMorpion(game, 1, 2);
        CaseMorpion caseMorpion20 = new CaseMorpion(game, 2, 0);
        CaseMorpion caseMorpion21 = new CaseMorpion(game, 2, 1);
        CaseMorpion caseMorpion22 = new CaseMorpion(game, 2, 2);

        window.add(caseMorpion00.getButton());
        window.add(caseMorpion01.getButton());
        window.add(caseMorpion02.getButton());
        window.add(caseMorpion10.getButton());
        window.add(caseMorpion11.getButton());
        window.add(caseMorpion12.getButton());
        window.add(caseMorpion20.getButton());
        window.add(caseMorpion21.getButton());
        window.add(caseMorpion22.getButton());

        window.setVisible(true);

    }
}
