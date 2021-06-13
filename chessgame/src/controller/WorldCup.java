package chessgame.src.controller;
import chessgame.src.pojo.*;

import java.util.ArrayList; 
import java.util.Scanner; 
public class WorldCup{ 
    private Player[] players; 
    private int playerCount; 

    // takes number of players as input along with their names 
    public WorldCup(int playerCount){ 
        this.playerCount = playerCount; 
        players = new Player[playerCount]; 
         
        for(int i=0; i<playerCount; i++){ 
            Scanner sc = new Scanner(System.in); 
            String playerName = sc.nextLine(); 
            players[i] = new Player(playerName, i); 
            sc.close();
        } 
    } 

    // get the list of players 
    public Player[] getPlayers(){ 
        return players; 
    } 

    // this method simulates the game in a binary tree type system 
    public void play(){ 
        if(playerCount <= 1){ 
            System.out.println("Please add atleast 2 players"); 
            return; 
        } 
        ArrayList<Integer> remainingPlayers = new ArrayList<>(); 
        ArrayList<Integer> semifinalists = new ArrayList<>(); 


        for(int i=0; i<playerCount; i++){ 
            remainingPlayers.add(i); 
        } 
        int round = 1; 
        while(remainingPlayers.size()!=1){ 
            int gamesCount = (int)Math.ceil(((double)remainingPlayers.size())/2); 
            String gameName; 
            switch(gamesCount){ 
                case 1: 
                gameName = "Finale"; 
                break; 
                case 2: 
                gameName = "Semi Final"; 
                semifinalists = remainingPlayers; 
                break; 
                default: 
                gameName = "Round " + Integer.toString(round); 
                break; 
            } 
            String gameRes = "Game : " + gameName + "\n"; 
            ArrayList<Player> loosers = new ArrayList<>(); 

            // simulating breadth first search here 
            for(int i=0; i<gamesCount; i++){ 
                Player player1 = players[remainingPlayers.get(i*2)]; 
                Player player2 = null; 
                if(i*2 + 1 != remainingPlayers.size()){ 
                    player2 = players[remainingPlayers.get(i*2 + 1)]; 
                } 
                Game game = new Game(gameName, player1, player2, round); 
                //game game to player records 
                players[remainingPlayers.get(i*2)].addGame(game); 
                if(player2!=null){ 
                    players[remainingPlayers.get(i*2 + 1)].addGame(game); 
                } 
                ArrayList<Player> res = game.playGame(); 
                if(res.get(1)!=null){ 
                    loosers.add(res.get(1)); 
                } 

                // add the players details result in each level of tree 
                gameRes += player1.getName() + (player2!=null ? " vs " + player2.getName() : "") + " :: winner -> " + res.get(0).getName() + (i!=gamesCount-1 ? " || " : ""); 
            } 
            for(int i=0; i<loosers.size(); i++){ 
                remainingPlayers.remove(new Integer((loosers.get(i)).getId())); 
            } 
            System.out.println(gameRes+"\n"); round++; 
        } 

        // this will finally print the root/final winner of the chess world cup 
        Player champion = players[remainingPlayers.get(0)]; 
        System.out.println("\n\nChampion (" + champion.getName() + ") game data:\n"); 
        champion.displayGamesData(); 
        if(semifinalists.size()>1){ 
            Player smflst = players[semifinalists.get(1)]; 
            System.out.println("\n\nOne of the semifinalist (" + smflst.getName() + ") game data:\n"); 
            smflst.displayGamesData(); 
        } 
        Scanner sc = new Scanner(System.in); 
        System.out.println("\n\nEnter a player id to get games data:"); 
        int playerId = 0; 
        playerId = sc.nextInt(); 
        while(playerId <= 0 || playerId > playerCount){ 
            System.out.println("Enter a valid player id:"); 
            playerId = sc.nextInt(); 
        } 
        sc.close();
        Player rPlayer = players[playerId-1]; 
        System.out.println("\n\nRandom player (" + rPlayer.getName() + ") game data:\n"); 
        rPlayer.displayGamesData(); 
    } 
} 
