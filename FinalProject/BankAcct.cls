public class BankAcct{
	private Integer balance = 0;
	public string acctName;
	public string accttype;
	//public Id userId;
	
	public void makeDeposit(Integer deposit){
		balance = balance + deposit;
	}
	
	public Integer getBalance(){
		return balance;
	}
	
}