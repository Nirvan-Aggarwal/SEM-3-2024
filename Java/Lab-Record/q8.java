class maths {
    // Method to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Overloaded method to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Overloaded method to add two doubles
    double add(double a, double b) {
        return a + b;
    }
}

public class q8 {
    public static void main(String[] args) {
        maths math = new maths();
        System.out.println("Sum of two integers: " + math.add(5, 3));
        System.out.println("Sum of three integers: " + math.add(5, 3, 2));
        System.out.println("Sum of two doubles: " + math.add(5.5, 3.3));
    }
}
