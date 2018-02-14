package individual.v2;

public class Set {
	
	Node head;
	Node end;
	int size;
	
	public Set(){
		head = null;
		end = null;
		size = 0;
	}
	
	//Take input and create a new set
	public Set(String input){
		//Create a array from input with comma as split regex
		String[] inputAsArray = input.split(",");
		//Cretae the head node of the set from the array's first value
		head = new Node (inputAsArray[0], null, null);
		Node current = head;
		Node prev = null;
		size = 0;
		boolean unique = true;
		
		//Go through array and add unique values to the set
		for (int i = 1; i < inputAsArray.length; i++){
			unique = true;
			//For each index of the array check if value already exist in set
			while(current != null){
				if (current.getValue().equals(inputAsArray[i])){
					unique = false;
					break;
				}
				else{
					prev = current;
					current = current.getNext();
				}
			}
			//If value does not already exist in set create a new node and add to set
			if (unique){
				Node newNode = new Node(inputAsArray[i], null, prev);
				prev.setNext(newNode);
				end = newNode;
				size++;
			}
			
			current = head;
		}
	}
	
	//Method to add new value to set
	public void add(String input){
		
		//In the event the set is empty the new value will become the head
		if (size == 0){
			Node newNode = new Node(input, null, null);
			head = newNode;
			end = newNode;
			size++;
		}
		
		//Else add new node to end of current set
		else{
			Node newNode = new Node(input, null, end);
			end.setNext(newNode);
			end = newNode;
			size++;	
		}
	}
	
	//Method to find union of two sets
	public Set union(Set set2){
		Set unionSet = new Set();
		
		Node current = this.head;
		
		//First add all values from this set
		while(current != null){
			unionSet.add(current.getValue());
			current = current.getNext();
		}
		
		current = set2.head;
		Node current2 = unionSet.head;
		boolean unique = true;
		
		//Second add values from second set if value found is unique
		while(current != null){
			unique = true;
			current2 = unionSet.head;
			while(current2 != null){
				if (current.getValue().equals(current2.getValue())){
					unique = false;
					break;
				}
				else
					current2 = current2.getNext();
			}
			if (unique){
				unionSet.add(current.getValue());	
			}
			current = current.getNext();
		}
		
		return unionSet;
	}
	
	//Method to find intersection of two set
	public Set intersection(Set set2){
		Set intersectionSet = new Set();
		
		Node current = this.head;
		Node current2 = set2.head;
		
		//Loop through first set
		while (current != null){
			current2 = set2.head;
			//Loop through second set
			//If value from second set matches value from first set
			//Add value to intersection set
			while(current2 != null){
				if (current.getValue().equals(current2.getValue())){
					intersectionSet.add(current.getValue());
					break;
				}
				else
					current2 = current2.getNext();
			}
			current = current.getNext();
		}
		
		return intersectionSet;
	}
	
	//Method to find difference of two set
	public Set difference(Set set2){
		//First find the union and intersection of two sets
		Set differenceSet = new Set();
		Set unionSet = this.union(set2);
		Set intersectionSet = this.intersection(set2);
		
		Node current = unionSet.head;
		Node current2 = intersectionSet.head;
		boolean unique = true;
		
		//Loop through union set
		while (current != null){
			unique = true;
			current2 = intersectionSet.head;
			//Add value to difference set if value from intersection set
			//Is not found in union set
			while(current2 != null){
				if (current.getValue().equals(current2.getValue())){
					unique = false;
					break;
				}
				else
					current2 = current2.getNext();
			}
			
			if (unique){
				differenceSet.add(current.getValue());
			}
			
			current = current.getNext();
		}
		
		return differenceSet;
	}
	
	//Method to print set
	public void printSet(){
		Node current = head;
		String prefix = "";
		//Loop through set starting from head and print value held in current node
		while (current != null){
			System.out.print(prefix + current.getValue());
			prefix = ",";
			current = current.getNext();
		}
		System.out.println();
	}
}
