#include <string>
#include <vector>
#include "Set.h"
#include "Application.h"
#include <iostream>
#include <algorithm>

using namespace std;

//.cpp file for application class
Application::Application() {
}

//Intro method that explain what algorithm will be performed
//Also set up the necessary vector and edges
void Application::intro() {
	cout << "Welcome to the Bron-Kerbosh algorithm.\n"
		"This algorithm finds the maximal cliques within an undirected graph using sets.\n";

	int nodes;

	//Get number of nodes
	while (true) {
		cout << "Enter number of nodes within graph: ";
		cin >> nodes;

		//Catch input mismatch
		if (cin.fail() || nodes < 0 || nodes < 2) {
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << "Invalid input" << endl;
		}
		else {
			break;
		}
	}

	cout << "Graph nodes: ";

	for (int i = 0; i < nodes; i++) {
		neighbors.push_back(Set());
		cout << i;
		cout << " ";
	}

	cout << "\nEnter the edges of the graphs.\n"
		"to set an edge, enter the two nodes individually." << endl;

	string cont = "y";

	int first = 0;
	int second = 0;

	//Get input to create edge
	while (!cont.compare("y")) {
		while (true) {
			cout << "first node index: ";
			cin >> first;
			//Catch input mismatch
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				cout << "Invalid input" << endl;
				continue;
			}
			else if (first >= nodes || first < 0) {
				cout << "Input out of index" << endl;
				continue;
			}

			cout << "Second node index: ";
			cin >> second;
			//Catch input mismatch
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits <streamsize>::max(), '\n');
				cout << "Invalid input" << endl;
				continue;
			}
			else if (second >= nodes || second < 0) {
				cout << "Input out of index" << endl;
				continue;
			}
			break;
		}

		neighbors.at(first).addNode(to_string(second));
		neighbors.at(second).addNode(to_string(first));

		printf("Edge between node %d and %d has been made\n", first, second);

		cout << "Continue? y/n: ";
		cin >> cont;
		transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
		//Ask user if they wish to continue adding edge
		//Loop question if answer is not y/n
		while (cont.compare("y") && cont.compare("n")) {
			cout << "Invalid input enter y/n: ";
			cin >> cont;
			transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
		}
	}
}

//Method that imlements the actual Bron-Kerb
void Application::bronKerb(Set a, Set b, Set c) {
	//B is maximal clique
	if (b.getSize() == 0 && c.getSize() == 0) {
		cout << "Maximal clique: ";
		a.printSet();
	}

	//This else if is supposed to be empty
	else if (b.getSize() == 0 && c.getSize() != 0) {
	}

	else {
		b.current = b.getHead();
		while (b.current != NULL) {
			Set v;
			v.addNode(b.current->value);
			
			Set newA = a + v;
			Set newB = b ^ neighbors.at(stoi(b.getHead()->value));
			Set newC = c ^ neighbors.at(stoi(b.getHead()->value));

			bronKerb(newA, newB, newC);
			b = b - v;
			c = c + v;

			b.current = b.getNext(b.current);

		}
	}
}

int Application::getSize() {
	return neighbors.size();
}