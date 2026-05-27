import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Calculatrice extends JFrame implements ActionListener{
    
    private JLabel formule;

    private JButton operateurs[];
	private JButton chiffres[];
	private JButton c;
	private JButton egal;

    Calculatrice(){
        setSize(new Dimension(500, 500));
        setLayout(new BorderLayout());
        formule = new JLabel("azljjfnbdazkjbnkza");
        formule.setSize(new Dimension(500, 100));
        
        JPanel op = new JPanel(new GridLayout(3, 2));
        operateurs = new JButton[6];
        operateurs[0] = (new JButton ("+"));
        operateurs[1] = (new JButton ("-"));
        operateurs[2] = (new JButton ("*"));
        operateurs[3] = (new JButton ("/"));
        operateurs[4] = (new JButton ("inv"));
        operateurs[5] = (new JButton ("rac"));
        for(int i=0; i<6; ++i){
            operateurs[i].addActionListener(this);
            op.add(operateurs[i]);
        }

        JPanel ch = new JPanel(new GridLayout(4, 3));
        chiffres = new JButton[12];
        for(int i=0; i<9; ++i){
            chiffres[i] = new JButton(String.valueOf(i+1));
        }
        chiffres[9] = new JButton(" ");
        chiffres[10] = new JButton("9");
        chiffres[11] = new JButton(".");

        for(int i=0; i<12; ++i){
            chiffres[i].addActionListener(this);
            ch.add(chiffres[i]);
        }

        JPanel execution = new JPanel(new FlowLayout());
        c = new JButton("c");       c.addActionListener(this);      execution.add(c);
        egal = new JButton("=");    egal.addActionListener(this);   execution.add(egal);


        

        
        add(formule, BorderLayout.NORTH);
        add(op, BorderLayout.EAST);
        add(ch, BorderLayout.CENTER);
        add(execution, BorderLayout.SOUTH);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        Object src = e.getSource();
        String expr = formule.getText();

        if(src == c){
            formule.setText("");
        }else if(src == egal){
            System.out.println(formule.getText());
        }else{
            for(int i=0; i<12; ++i){
                if(chiffres[i] == src){
                    formule.setText(expr + chiffres[i].getText());
                    return;
                }
            }
            for(int i=0; i<6; ++i){
                formule.setText(expr + operateurs[i].getText());
                    return;
            }
        }
    }


}