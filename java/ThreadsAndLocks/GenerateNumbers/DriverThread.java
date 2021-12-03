package ThreadsAndLocks.GenerateNumbers;

public class DriverThread {
    private static final int TOTAL_NUMBERS_IN_SEQUENCE = 10;
    private static final int TOTAL_THREADS = 3;

    public static void main(String[] args) {
        NumbersGenerator numbersGenerator = new NumbersGenerator(TOTAL_THREADS, TOTAL_NUMBERS_IN_SEQUENCE);
        Thread t1 = new Thread(new GeneratorRunnable(numbersGenerator, 1), "THREAD-1");
        Thread t2 = new Thread(new GeneratorRunnable(numbersGenerator, 2), "THREAD-2");
        Thread t3 = new Thread(new GeneratorRunnable(numbersGenerator, 0), "THREAD-3");

        t1.start();
        t2.start();
        t3.start();
    }
}
