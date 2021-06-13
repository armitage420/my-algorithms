package chessgame.src.driver;
import chessgame.src.controller.*;
import java.util.Scanner;

// this is the final driver class that will run the code and take the number of players and names of the players 
public class ChessWorldCup { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of players:"); 
        int num = sc.nextInt();
        sc.close();
        
        WorldCup mWorldCup = new WorldCup(num); 
        System.out.println("Enter player names one after one:"); 
        mWorldCup.play(); 
    } 
} 