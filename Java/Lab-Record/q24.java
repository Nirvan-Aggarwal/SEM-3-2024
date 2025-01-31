import java.awt.*;

public class q24 {
    public static void main(String[] args) {
        Frame frame = new Frame("Layout Demo");
        frame.setLayout(new FlowLayout());
        frame.add(new Button("Button 1"));
        frame.add(new Button("Button 2"));
        frame.setSize(200, 200);
        frame.setVisible(true);
    }
}
