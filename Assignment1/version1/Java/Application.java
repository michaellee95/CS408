package individual.v1;

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
				break;
			}catch(Exception e){
				System.out.println("Enter a number");
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
		
		//Get input to create edge
		while (cont.equalsIgnoreCase("y")){
			System.out.println("first node index: ");
			int first = kb.nextInt();
			System.out.println("Second node index: ");
			int second = kb.nextInt();

			neighbors[first].addElement(Integer.toString(second));
			neighbors[second].addElement(Integer.toString(first));

			System.out.println("Edge between node " + first
					+ " and " + second + " has been made");
			kb.nextLine();
			System.out.println("Continue? y/n");
			cont = kb.nextLine();
			//Ask user if they wish to continue adding edge
			//Loop question if answer is not y/n
			while(!cont.equalsIgnoreCase("y") && !cont.equalsIgnoreCase("n")){
				System.out.println("Invalid input enter y/n");
				cont = kb.nextLine();
			}
		}
	}

	// method that implements the actual Bron-Kerb
	public void bronKerb(Set a, Set b, Set c) {
		if (b.size == 0 && c.size == 0) {
			System.out.print("Maximal Clique: ");
			a.printSet();
		} 
		//This else if is supposed to be empty
		else if (b.size == 0 && c.size != 0) {
		} 
		
		else {
			int count = b.set.length;
			while (b.size != 0) {
				Set v = new Set(b.set[0]);

				Set newR = a.union(v);
				Set newP = b.intersection(neighbors[Integer.parseInt(b.set[0])]);
				Set newX = c.intersection(neighbors[Integer.parseInt(b.set[0])]);

				bronKerb(newR, newP, newX);
				b = b.difference(v);
				c = c.union(v);
			}
		}

	}

}