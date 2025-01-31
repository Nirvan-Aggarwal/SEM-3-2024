public class q2 {
    public static void main(String[] args) {
        int day = 2;

        switch (day) {
            case 1 -> System.out.println("Weekday");
            
            case 2 -> System.out.println("Weekend");

            default -> System.out.println("Invalid day");
        }
    }
}
