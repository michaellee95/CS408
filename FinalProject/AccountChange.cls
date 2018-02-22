public class AccountChange {

    public void names(){
        Insert new Account(Name = 'James');
        Account[] accts = [SELECT Id, Name FROM Account];
        
        for (Account accounts : accts){
            System.debug(accounts.name);
        }
        
        Account acctToAddContact = [SELECT Id, Name FROM Account WHERE Name = 'James' LIMIT 1];
        Contact cont = new Contact();
        cont.AccountId = acctToAddContact.Id;
        cont.firstName = 'Sally';
        cont.LastName = 'Lee';
		insert cont;
    }
}

AccountChange ac = new AccountChange();
ac.names();
