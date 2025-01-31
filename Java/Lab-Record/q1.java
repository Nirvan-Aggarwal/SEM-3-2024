public class q1 {
    public static void main(String[] args) {
        int age = 17;
        
        if (age < 0) {
            System.out.print("Age cannot be less than 0");
        } 
        else if (age < 18) {
            System.out.print("You cannot vote as age is: " + age);
        } 
        else {
            System.out.print("You can now vote");
        }
    }
}
