class MyRunnable implements Runnable {
    public void run() {
        System.out.println("Thread is running");
    }
}

public class q22 {
    public static void main(String[] args) {
        Thread t = new Thread(new MyRunnable());
        t.start();
    }
}
