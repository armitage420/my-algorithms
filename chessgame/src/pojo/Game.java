package chessgame.src.pojo;

import java.util.ArrayList;

public class Game{ 
    private String name; 
    private Player player1, player2, winner, looser; 

    // leftGame and rightGame represents the left subtree and right subtree repectively from where both the players have won and reached the specific level 
    Game leftGame, rightGame; 

    // round represents the height of binary tree 
    int round; 
    public Game(String name, Player player1, Player player2, int round){ 
        this.name = name; 
        this.player1 = player1; 
        this.player2 = player2; 
        this.round = round; 
    } 

    // getters 
    public int getWinnerId(){ 
        return winner.getId(); 
    } 
    public Player getPlayer1(){ 
        return player1; 
    } 
    public Player getPlayer2(){ 
        return player2; 
    } 
    public int getPlayer1Id(){ 
        return player1.getId(); 
    } 
    public String getName(){ 
        return name; 
    } 

    // check if the player needs to be promoted without playing to next round 
    public boolean isOtherPlayerExists(){ 
        if(player2 != null){ 
            return true; 
        } 
        else{ 
            return false; 
        } 
    } 

    // this method simulates the game scenario between two players 
    public ArrayList<Player> playGame(){ 
        // if right player is not present then player1 is naturally the winner 
        if(player2 == null){ 
            winner = player1; 
            looser = player2; 
        } 
        // randomly select the player as winner 
        else if(Math.random() <= 0.5){ 
            winner = player1; 
            looser = player2; 
        } 
        // if left player is not present then player2 is naturally the winner
        else{ 
            winner = player2; 
            looser = player1; 
        } 
        ArrayList<Player> temp = new ArrayList<>(); 
        temp.add(winner); 
        temp.add(looser); 
        return temp; 
    } 
} 