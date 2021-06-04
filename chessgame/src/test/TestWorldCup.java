package chessgame.src.test;

import chessgame.src.controller.*;
public class TestWorldCup {
    public static void main(String[] args) {
        WorldCup mWorldCup = new WorldCup(20); 
        System.out.println("Enter player names one after one:"); 
        mWorldCup.play(); 
    }
}
