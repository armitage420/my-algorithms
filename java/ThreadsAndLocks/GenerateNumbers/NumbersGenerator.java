package ThreadsAndLocks.GenerateNumbers;

public class NumbersGenerator {
    private int number = 1;
    private int totalNumberInThreads;
    private int totalNumbersInSequence;


    public NumbersGenerator(int totalNumberInThreads, int totalNumbersInSequence) {
        this.totalNumberInThreads = totalNumberInThreads;
        this.totalNumbersInSequence = totalNumbersInSequence;
    }

    public void printNumbers(int result){
        synchronized(this){
            while(number < totalNumbersInSequence-1){
                while(number % totalNumberInThreads != result){
                    try {
                        wait();
                    } catch (InterruptedException exc) {
                        //TODO: handle exception
                        exc.printStackTrace();
                    }
                }

                System.out.println(Thread.currentThread().getName() + " = " + number++);
                notifyAll();
            }
        }
    }
}
