import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Test {
    public static void main(String[] args) {
        JFrame window = new JFrame();
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setSize(800, 800);

        window.setLayout(new FlowLayout());

        JLabel label = new JLabel("*malicieux* Quel est ton petit nom... ?");
        JButton btn = new JButton("OK");
        JTextField field = new JTextField(10);

        window.add(label);
        window.add(field);
        window.add(btn);

        btn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evenement){
                System.out.println(field.getText());
            }
        });

        
        window.setVisible(true);

    
    }
}