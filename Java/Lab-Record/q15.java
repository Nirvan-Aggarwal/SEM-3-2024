class Parent {
    void show() {
        System.out.println("Parent show method");
    }
}

class Child extends Parent {
    @Override
    void show() {
        System.out.println("Child show method");
    }
}

public class q15 {
    public static void main(String[] args) {
        Child child = new Child();
        child.show();
    }
}
