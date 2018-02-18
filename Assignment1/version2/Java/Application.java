import java.io.*;
import java.util.Scanner;

//Class for applicatoin
public class Application {
	Scanner kb = new Scanner(System.in);
	Set[] neighbors;

	// introduce Bron-Kerbosh algorithm
	// create grpah from user input
	// represent graph as array of sets
	public void intro() {
		System.out.println("Welcome to the Bron-Kerbosh algorithm.\n"
							+ "This algorithm finds the maximal cliques within an undirected graph using sets.\n"
							+ "Enter number of nodes within graph");
		
		int nodes;
		while(true){
			try{
				nodes = kb.nextInt();
				if (nodes < 2){
					System.out.println("There must be a minimum of 2 nodes");
					continue;
				}
				break;
			}catch(Exception e){
				System.out.print("Enter a number");
				kb.nextLine();
			}	
		}

		neighbors = new Set[nodes];

		System.out.print("Graph nodes: ");
		for (int i = 0; i < nodes; i++) {
			neighbors[i] = new Set();
			System.out.print(i + " ");
		}
		System.out.println("\nEnter the edges of the graphs.\n"
						+ "to set an edge, enter the two nodes individually.");
		String cont = "y";
		
		int first = 0;
		int second = 0;
		
		//Get input to create edge
		while (cont.equalsIgnoreCase("y")){
			while(true){
				try{
					System.out.print("first node index: ");
					first = kb.nextInt();
					if (first >= nodes || first < 0){
						System.out.println("Input out of index");
						continue;
					}
					System.out.print("Second node index: ");
					second = kb.nextInt();
					if (second >= nodes || second < 0){
						System.out.println("Input out of index");
						continue;
					}
					break;
				}catch(Exception e){
					System.out.println("Enter a number");
					kb.nextLine();
				}	
			}

			neighbors[first].add(Integer.toString(second));
			neighbors[second].add(Integer.toString(first));

			System.out.println("Edge between node " + first
							+ " and " + second + " has been made");
			kb.nextLine();
			System.out.print("Continue? y/n: ");
			cont = kb.nextLine();
			//Ask user if they wish to continue adding edge
			//Loop question if answer is not y/n
			while(!cont.equalsIgnoreCase("y") && !cont.equalsIgnoreCase("n")){
				System.out.print("Invalid input enter y/n: ");
				cont = kb.nextLine();
			}
		}
	}

	// method that implements the actual Bron-Kerb
	public void bronKerb(Set a, Set b, Set c) {
		//B is maximal clique
		if (b.size == 0 && c.size == 0) {
			System.out.print("Maximal Clique: ");
			a.printSet();
		} 
		//This else if is supposed to be empty
		else if (b.size == 0 && c.size != 0) {
		} 
		
		else {
			Node current = b.head;
			while (current != null) {			
				Set v = new Set();
				v.add(current.getValue());
				
				Set newA = a.union(v);
				Set newB = b.intersection(neighbors[Integer.parseInt(current.getValue())]);
				Set newC = c.intersection(neighbors[Integer.parseInt(current.getValue())]);
				
				bronKerb(newA, newB, newC);
				b = b.difference(v);
				c = c.union(v);
				
				current = current.getNext();
			}
		}
	}
}