package ThreadsAndLocks;
import java.lang.Thread;

public class ThreadExample extends Thread{
    public int count=0;
    public void run(){
        System.out.println("in Thread");
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
        }finally{
            System.out.println("program over.");
        }
    }

    public static void main(String[] args) {
        ThreadExample te = new ThreadExample();
        te.start();
        while(te.count < 5){
            try {
                System.out.println("Count = " + te.count);
                Thread.sleep(250);
            } catch (Exception e) {
                //TODO: handle exception
                System.out.println("In catch");
                System.err.println(e);
            }
        }
    }
}
