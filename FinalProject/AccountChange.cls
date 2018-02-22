public class AccountChange {

    public void names(){
        Insert new Account(Name = 'Bob');
        Account[] accts = [SELECT Id, Name FROM Account];
        
        for (Account accounts : accts){
            System.debug(accounts.name);
        }
    }
}


AccountChange ac = new AccountChange();
ac.names();