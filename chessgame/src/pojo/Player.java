package chessgame.src.pojo;

import java.util.ArrayList; 

public class Player{ 
    private String name; 
    private int id; 
    private ArrayList<Game> gamesPlayed = new ArrayList<>(); 
    public Player(String name, int id){
        this.name = name; 
        this.id = id; 
    } 
    public String getName(){ 
        return name; 
    } 
    public int getId(){ 
        return id; 
    } 
    public void addGame(Game game){ 
        gamesPlayed.add(game); 
    } 
    public void displayGamesData(){ 
        for(int i=0; i<gamesPlayed.size(); i++){ 
            Game game = gamesPlayed.get(i); 
            boolean win = game.getWinnerId() == id ? true : false; 
            String s = ""; 
            System.out.println("Round: " + game.getName()); 
            if(game.isOtherPlayerExists()){ 
                s = (win ? "Won " : " Lost ") + "on " + (game.getPlayer1Id()==id ? game.getPlayer2().getName() : game.getPlayer1().getName()); 
            } else{ 
                s = "Promoted to next round due to absence of opponent"; 
            } 
            System.out.println(s); 
        } 
    } 
} 
