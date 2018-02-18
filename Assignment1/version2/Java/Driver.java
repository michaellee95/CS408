
import java.util.Scanner;

/*Driver class. Takes user input for two sets
 * Afterwards asks user if they wish to perform union/intersection/difference
 * Along with the option to use the set appliction (using list)
 */
public class Driver {
	
	public static void main (String[] args){
		
		Scanner kb = new Scanner(System.in);
		
		//Get two user input and change them to sets
		System.out.println("Enter set 1 (Comma seperated, values are space and case sensitive)");
		String input1 = kb.nextLine();
		Set set1 = new Set(input1);
		
		System.out.println("Enter set 2 (Comma seperated, values are space and case sensitive)");
		String input2 = kb.nextLine();
		Set set2 = new Set(input2);
		
		int option = 0;
		
		//Loop through options until user decides to quit
		while(option != 5) {
			System.out.println("Enter action to perform: \n 1. Union \n 2. Intersection \n 3. Difference \n "
					+ "4. Application \n 5. Exit");
			try {
				option = kb.nextInt();
			}catch (Exception e) {
				System.out.println("Unknown Input");
				kb.nextLine();
				continue;
			}
			//Perform union and print result
			if (option == 1) {
				Set unionSet = set1.union(set2);
				System.out.print ("Union set: ");
				unionSet.printSet();
			}
			//Perform intersection and print result
			else if (option == 2) {
				Set intersectionSet = set1.intersection(set2);
				System.out.print ("Intersection set: ");
				intersectionSet.printSet();
			}
			//Perform difference and print result
			else if (option == 3) {
				Set differenceSet = set1.difference(set2);
				System.out.print ("Difference set: ");
				differenceSet.printSet();
			}
			//Perform application and print result
			else if (option == 4) {
				Application app = new Application();
				app.intro();
				Set a = new Set();
				Set b = new Set();
				Set c = new Set();
				
				for (int i = 0; i < app.neighbors.length; i++){
					b.add(Integer.toString(i));
				}
				app.bronKerb(a, b, c);
			}
			//End program
			else if (option == 5) {
				System.out.println("Exiting program");
				System.exit(0);
			}
			else
				System.out.println("Input is not part of choice");
		}
		
		
		kb.close();
	}

}
