public class ExampleClass {

    public void aMethod(){
        //Type code here
    }
    
    public void showTest(){
        System.debug('Hello from the otter side!');
    }
    
    public void loops(){
        for (integer i = 0; i < 5; i++)
            System.debug(i);
        
        integer[] aArray = new integer[]{1,2,3,4,5};
        for (integer num: aArray)
            System.debug(num);
        
        integer counter = 0;
        while (counter < 10){
            System.debug(counter);
            counter++;
        }
    }
    
    public integer returnMethod(){
        integer num = 5;
        return num;
    }
    
    public void tryCatch(){
        try{
            System.debug('It works!');
        }catch(Exception e){
            System.debug('There was a error');
        }
    }
    
    public void sObjectShowCase(){
        //Some sObject includes
        Account aAccount = new Account();
        Contact aContact = new Contact();
        //The generic form is
        sObject aSObject = new Account();
        sObject aSObject2 = new Contact();
    }
    
    public void DML(){
        Account aAccount = new Account(Name = 'Michael');
        insert aAccount;
        
        Account delAccount = [SELECT Id, Name FROM Account WHERE Name = 'Michael'];
        delete delAccount;
        
        Account updateAccount = [SELECT Id, Name FROM Account WHERE Name = 'Michael'];
        updateAccount.Name = 'NotMichael';
        update updateAccount;
    }
    
    public void createObject(){
        ExampleClass ec = new ExampleClass();
        //Do something with ec
    }
}