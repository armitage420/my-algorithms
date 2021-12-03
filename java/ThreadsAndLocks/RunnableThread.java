package ThreadsAndLocks;
import java.lang.Runnable;

// public interface Runnable{
//     void run();
// }

public class RunnableThread implements Runnable{
    public int count=0;
    public void run(){
        System.out.println("in Runnable");
        try {
            while(count < 5){
                Thread.sleep(500);
                count++;
            }
        } catch (InterruptedException exc){
            System.err.println(exc);
        }catch (Exception e) {
            //TODO: handle exception
            System.err.println(e);
        }
    }

    public static void main(String[] args) {
        RunnableThread rt = new RunnableThread();
        Thread thread = new Thread(rt);
        thread.start();

        while(rt.count < 5){
            try {
                System.out.println("Count = " + rt.count);
                Thread.sleep(250);
            } catch (Exception e) {
                //TODO: handle exception
                System.out.println("In catch");
                System.err.println(e);
            }
        }
    }
}
