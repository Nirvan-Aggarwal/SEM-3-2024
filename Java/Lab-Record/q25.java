import java.awt.*;
import java.awt.event.*;

public class q25 {
    public static void main(String[] args) {
        Frame frame = new Frame("Event Demo");
        Button button = new Button("Click Me");

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.out.println("Button Clicked");
            }
        });

        frame.add(button);
        frame.setSize(200, 200);
        frame.setVisible(true);
    }
}
