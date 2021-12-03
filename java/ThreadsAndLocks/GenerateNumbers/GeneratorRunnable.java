package ThreadsAndLocks.GenerateNumbers;

public class GeneratorRunnable implements Runnable{
    private NumbersGenerator numbersGenerator;
    private int result;


    public GeneratorRunnable(NumbersGenerator numbersGenerator, int result) {
        this.numbersGenerator = numbersGenerator;
        this.result = result;
    }


    public void run(){
        numbersGenerator.printNumbers(result);
    }

}
