import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class CaseMorpion {
    Game game;
    JButton button;
    int x;
    int y;

    CaseMorpion(Game game, int x, int y){
        this.game = game;
        this.x = x;
        this.y = y;
        button = new JButton("");
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evenement){
                int player = game.getCurr_player();
                if(game.jouer(x, y)){
                    button.setText(player == 1 ? "X" : "0");
                }
            }
        });
    }

    public JButton getButton() {
        return button;
    }
}
