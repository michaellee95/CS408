//Code for trigger
trigger CreateContact on Candidate_c (after insert){

	CreateContactFromCan cc = new CreateContactFromCan();
	
	cc.createContact(Trigger.new);
}