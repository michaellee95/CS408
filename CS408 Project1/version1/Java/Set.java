//Set class using arrays
public class Set {

	String[] set;
	int size;
	
	public Set(){
		set = new String[1];
		set[0] = "";
		size = 0;
	}
	
	//Create a new set array that is split based on comma and only contain unique values
	public Set (String input) {
		//First create a temporary array that will hold the values of input split by comma
		//Second create a stringbuffer that will only hold the unique values
		String[] temp = input.split(",");
		String[] inputWithoutRepeat = new String[temp.length];
		int index = 0;
		boolean unique = true;
		StringBuilder uniqueString = new StringBuilder(temp.length);
		//Loop through temporary array
		//If the value in temp array index is not found in string buffer the value is unique
		//Add value to string buffer
		for (int i = 0; i < temp.length; i++){
			unique = true;
			for (int j = 0; j < index; j++){
				if (inputWithoutRepeat[j].equals(temp[i]))
					unique = false;
			}
			if (unique){
				uniqueString.append(temp[i] + ",");
				inputWithoutRepeat[index] = temp[i];
				index++;
			}
		}
		
		
		//Create new set based on string buffer that should only contain the same value once
		//Is space and case sensitive
		set = uniqueString.toString().split(",");
		size = set.length;
	}
	
	public int getSize() {
		return size;
	}
	
	public String getValue(int index) {
		return set[index];
	}
	
	//Method to add new element to set. Used for application
	public void addElement(String input){
		if (size == 0){
			set[0] = input;
			size++;
		}
		else{
			String[] newSet = (String[])set.clone();
			set = new String[set.length + 1];
			for (int i = 0; i < newSet.length; i++) {
				set[i] = newSet[i];
			}
			set[newSet.length] = input;
			size = newSet.length+1;
		}
	}
	
	//Create a new set based on two set's union
	public Set union(Set set2) {
		String[] combinedSet = new String[set.length + set2.getSize()];
		StringBuilder unionSet = new StringBuilder();
		int index = 0;
		
		//First copy all values from set 1 to combined set
		for (int i = 0; i < set.length; i++) {
			combinedSet[index] = set[i];
			unionSet.append(set[i] + ",");
			index++;
		}
		
		boolean repeat;
		
		//For the second set, only add values after checking with values from combined set
		//To ensure duplicates do not exist
		for (int i = 0; i < set2.getSize(); i++) {
			repeat = false;
			for (int j = 0; j < index; j++) {
				if (set2.getValue(i).equals(combinedSet[j])){
					repeat = true;
					break;
				}
			}
			//If value from set 2 is not a repeat add to the union set string
			if (repeat == false) {
				combinedSet[index] = set2.getValue(i);
				unionSet.append(set2.getValue(i) + ",");
				index++;
			}
		}
		
		//Return a new set made from union set string
		return new Set(unionSet.toString());
	}
	
	//Create a new set based on two set's intersection
	public Set intersection(Set set2) {
		StringBuilder intersectionSet = new StringBuilder(set.length);
		// Go through set 1 and set 2. If both set contain the same value add that to intersection set
		for (int i = 0; i < set.length; i++) {
			for (int j = 0; j < set2.getSize(); j++) {
				if (set[i].equals(set2.getValue(j))) {
						intersectionSet.append(set[i] + ",");
						break;	
				}
			}
		}
		
		//Return a new set made from the intersection set string 
		return new Set(intersectionSet.toString());
	}
	
	//Create a new set based on two set's difference
	public Set difference(Set set2) {
		//Get the union and intersection of two sets
		Set unionSet = this.union(set2);
		Set intersectionSet = this.intersection(set2);
		StringBuilder differenceSet = new StringBuilder(unionSet.getSize());
		boolean unique;
		
		//If a value from the union set is not in the intersection set, the value is unique to one of two sets
		for (int i = 0; i < unionSet.getSize(); i++){
			unique = true;
			for (int j = 0; j < intersectionSet.getSize(); j++){
				if (unionSet.getValue(i).equals(intersectionSet.getValue(j))){
					unique = false;
					break;
				}
			}
			if (unique)
				differenceSet.append(unionSet.getValue(i) + ",");
		}
		
		//Return a new set made from the difference set string
		return new Set(differenceSet.toString());
	}
	
	//Print all values stored in this set
	public void printSet() {
		for (int i = 0; i < set.length; i++) {
			System.out.print(set[i] + " ");
		}
		System.out.println();
	}
}
