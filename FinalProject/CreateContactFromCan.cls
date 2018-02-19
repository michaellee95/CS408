public with sharing class CreateContactFromCan{

	//Code for fetching and quering from database
	public void createContact(List<Candidate_c> candsFromTrigger){
		
		//Code for fetching from database
		Account candAcct = [Select a.Id From Account a Where a.Name = 'Recruiting'];
		
		List<Contact> conList = new List<Contact>();
		
		//Code for creating new object and pushing to database
		for (Candidate_c currentCandidate : candsFromTrigger){
			Contact con = new Contact();
			
			con.AccountId = candAcct.Id;
			
			con.firstName = currentCandidate.first_Name_c;
			con.lastName = currentCandidate.last_Name_c;
			con.email = currentCandidate.email_c;
			
			conList.add(con);
		}
		
		Database.insert(conList);
	}
}