//Execute code for bank account
BankAcct chkAcct = new BankAcct();
chkAcct.accttype = 'Checking';
chkAcct.acctName = 'B.Lee-Chk';
chkAcct.makeDeposit(150);
//chkAcct.userId = '00001243';

BankAcct savAcct = new BankAcct();
savAcct.accttype = 'Savings';
savAcct.acctName = 'B.Lee-Sav';
savAcct.makeDeposit(220);

List<BankAcct> bankAccts = new List<BankAcct>();
bankAccts.add(chkAcct);
bankAccts.add(savAcct);
system.debug('There are: ' + bankAccts.size() + 'bank accounts.');
system.debug('Here is the list: ' + bankAccts);

for (BankAcct tempAcct : bankAccts){
	system.debug(tempAcct.acctName + ' is a ' + tempAcct.accttype + ' account with a balance of $' + tempAcct.getBalance());
}



//Execute code for contact
Account acct = new Account();
acct.Name = 'Recruiting';
Database.insert(acct);