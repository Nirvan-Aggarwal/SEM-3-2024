
class Rectangle {
    int length;
    int width;

    // Constructor with no parameters
    Rectangle() {
        length = 0;
        width = 0;
    }

    // Constructor with two parameters
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    void displayArea() {
        System.out.println("Area: " + (length * width));
    }
}

public class q10 {
    public static void main(String[] args) {
        // Using no-parameter constructor
        Rectangle rect1 = new Rectangle();
        rect1.displayArea();

        // Using two-parameter constructor
        Rectangle rect2 = new Rectangle(5, 10);
        rect2.displayArea();
    }
}
