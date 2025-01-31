class Person {
    String name;
    int age;

    void displayInfo() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

public class q6 {
    public static void main(String[] args) {
        Person person1 = new Person();
        person1.name = "John";
        person1.age = 25;
        person1.displayInfo();
    }
}
