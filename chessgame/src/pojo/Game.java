package chessgame.src.pojo;

import java.util.ArrayList;

public class Game{ 
    private String name; 
    private Player player1, player2, winner, looser; 
    Game leftGame, rightGame; 
    int round; 
    public Game(String name, Player player1, Player player2, int round){ 
        this.name = name; 
        this.player1 = player1; 
        this.player2 = player2; 
        this.round = round; 
    } 
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
    public boolean isOtherPlayerExists(){ 
        if(player2 != null){ 
            return true; 
        } 
        else{ 
            return false; 
        } 
    } 
    public ArrayList<Player> playGame(){ 
        if(player2 == null){ 
            winner = player1; 
            looser = player2; 
        } 
        else if(Math.random() <= 0.5){ 
            winner = player1; 
            looser = player2; 
        } 
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