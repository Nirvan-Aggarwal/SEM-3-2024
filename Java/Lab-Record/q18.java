interface Animal {
    void sound();
}

class Cat implements Animal {
    public void sound() {
        System.out.println("Cat meows");
    }
}

public class q18 {
    public static void main(String[] args) {
        Animal cat = new Cat();
        cat.sound();
    }
}
