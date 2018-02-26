//Demo class
public class GameDriver {

    public List<Account> listOfPlayers = new List<Account>();
    public Long startTime;
    public Long endTime;
    public Long runTime;
    public List<String> message = new List<String>();
    
    //Default game starts with 4 players without input
    public void gameDriver(){
    	DateTime now = System.now();
    	startTime = now.getTime();        
        gameSetup(4);
        start();
    }
    
    public void gameDriver(integer playerCount){
    	DateTime now = System.now();
    	startTime = now.getTime();           
        gameSetup(playerCount);
        start();
    }    
    
    //Create players(accounts) based on input/default
    public void gameSetup(integer playerCount){
        for (integer i = 1; i <= playerCount; i++){
            Account newPlayer = new Account();
            String name = 'Player' + i;
            newPlayer.Name = name;
            newPlayer.Money__c = 1000.00;
            newPlayer.Rank__c = 1;
            listOfPlayers.add(newPlayer);
        }
        
        //Try to insert to database
        try{
            insert listOfPlayers;
        }catch(Exception e){
            System.debug('Error when inserting players');
        }        
    }
    
    //Run game for twenty turns
    public void start(){
        integer turnCount = 0;
        while(turnCount < 20){
        	turn();
            resolveRank();
            
            //update players
            try{
                update listOfPlayers;
            }catch(Exception e){
                System.debug('Error when updating players');
            }
            listOfPlayers = [SELECT Id, Name, Money__c, Rank__c FROM Account WHERE Name LIKE 'Player%'];
            turnCount++;
        }
        endGame();
    }
    
    //Each player will see if they win or lose some money depending on random number
    public void turn(){
        Decimal random1 = 0.0;
        Decimal random2 = 0.0;
        Decimal amount = 0.0;
        for (Account currentPlayer : listOfPlayers){
            for (Account otherPlayer : listOfPlayers){
                if (currentPlayer == otherPlayer)
                    continue;
                else if (currentPlayer.Money__c == 0 || otherPlayer.Money__c == 0)
                    continue;
                else{
                    random1 = Math.random();
                    random2 = Math.random();
                    
                    amount = 100 * Math.random();
                    amount = amount.setScale(2);
                    
                    if (random1 > random2){
                        if (otherPlayer.Money__c < amount){
                            currentPlayer.Money__c += otherPlayer.Money__c;
                            otherPlayer.Money__c = 0.0;
                        }
                        else{
                        	currentPlayer.Money__c += amount;
                        	otherPlayer.Money__c -= amount;                            
                        }
                    }
                    else{
                        if (currentPlayer.Money__c < amount){
                            otherPlayer.Money__c += otherPlayer.Money__c;
                            currentPlayer.Money__c = 0.0;                            
                        }
                        else{
                        	otherPlayer.Money__c += amount;
                        	currentPlayer.Money__c -= amount;                               
                        }                     
                    }
                }
            }
        }
    }
    
    //Determine rank based on who has more money
    public void resolveRank(){
        integer rank = 1;
        for (Account currentPlayer : listOfPlayers){
            rank = 1;
            for (Account otherPlayer : listOfPlayers){
                if (currentPlayer == otherPlayer)
                    continue;
                if (currentPlayer.Money__c < otherPlayer.Money__c){
					rank++;                     
                }
                currentPlayer.Rank__c = rank;
            }
        }    
    } 
    
    //End game by printing out/storing results and deleting the created accounts
    public List<String> endGame(){
        for (Account currentPlayer : listOfPlayers){
            System.debug(currentPlayer.Name + ' ended with: $' + currentPlayer.Money__c + ' and ranked ' + currentPlayer.Rank__c);
            message.add(currentPlayer.Name + ' ended with: $' + currentPlayer.Money__c + ' and ranked ' + currentPlayer.Rank__c);
        }

        try{
            delete listOfPlayers;
        }catch(Exception e){
            System.debug('Error when deleting players');
        }  
        
        //Get runtime
        DateTime now = System.now();
    	endTime = now.getTime();
        runTime = endTime - startTime;
        System.debug('Runtime: ' + runTime);
        message.add('Runtime: ' + runTime);
        return message;
    }
}