// CS408 Assignment 1 version 1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Set.h"
#include <string>
#include <limits>
#include <exception>

using namespace std;

int main()
{
	string input1;
	string input2;

	//Get two user input for sets
	cout << "Enter set 1 (Comma seperated, values are space and case sensitive)" << endl;
	cin >> input1;
	cout << "Enter set 2 (Comma seperated, values are space and case sensitive)" << endl;
	cin >> input2;

	Set set1(input1);
	Set set2(input2);

	int option = 0;

	//Loop through options until user decides to quit
	while (option != 5) {
		cout << "Enter action to perform: \n 1. Union \n 2. Intersection \n 3. Difference \n";
		cout << " 4. Application \n 5. Exit \n";

		cin >> option;

		//Catch input mismatch
		if (cin.fail()) {
			cout << "Unknown Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
		}
		//Perform union and print result
		if (option == 1) {
			Set unionSet = set1.unionSet(set2);
			cout << "Union set: ";
			unionSet.printSet();
		}
		//Perform intersection and print result
		else if (option == 2) {
			Set intersectionSet = set1.intersectionSet(set2);
			cout << "Intersection set: ";
			intersectionSet.printSet();
		}
		//Perform difference and print result
		else if (option == 3) {
			//Set differenceSet = set1.difference(set2);
			cout << "Difference set: ";
			//differenceSet.printSet();
		}
		//Perform application and print result
		else if (option == 4) {

		}
		//End program
		else if (option == 5) {
			cout << "Exiting program";
			exit(0);
		}
		else
			cout << "Input is not part of choice";



	}

    return 0;
}

