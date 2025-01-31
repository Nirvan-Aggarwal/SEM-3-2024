class Student {
    String name;
    int age;

    // Constructor
    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void displayInfo() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

public class q9 {
    public static void main(String[] args) {
        Student student1 = new Student("Alice", 22);
        student1.displayInfo();
    }
}
