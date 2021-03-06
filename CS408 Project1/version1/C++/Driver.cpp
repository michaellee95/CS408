// CS408 Assignment 1 version 1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Set.h"
#include "Application.h"
#include <string>
#include <limits>
#include <exception>
#include <chrono>

using namespace std;

int main()
{
	string input1;
	string input2;

	//Get two user input for sets
	cout << "Enter set 1 (Comma seperated, values are space and case sensitive)" << endl;
	getline(cin, input1);
	cout << "Enter set 2 (Comma seperated, values are space and case sensitive)" << endl;
	getline(cin, input2);

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
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
		}
		//Perform union and print result
		if (option == 1) {
			Set unionSet = set1 + set2;
			cout << "Union set: ";
			unionSet.printSet();
		}
		//Perform intersection and print result
		else if (option == 2) {
			Set intersectionSet = set1 ^ set2;
			cout << "Intersection set: ";
			intersectionSet.printSet();
		}
		//Perform difference and print result
		else if (option == 3) {
			Set differenceSet = set1 - set2;
			cout << "Difference set: ";
			differenceSet.printSet();
		}
		//Perform application and print result
		else if (option == 4) {
			Application app;
			app.intro();
			Set a;
			Set b;
			Set c;

			for (int i = 0; i < app.getSize(); i++) {
				b.addElement(to_string(i));
			}
			
			//auto start = std::chrono::high_resolution_clock::now();

			//for (int i = 0; i < 100; i++)
				app.bronKerb(a, b, c);

			//auto finish = std::chrono::high_resolution_clock::now();

			//std::chrono::duration<double> elapsedTime = finish - start;

			//cout << "elapsed time: " << elapsedTime.count();
			//cout << "average time" << elapsedTime.count() / 100;
		}
		//End program
		else if (option == 5) {
			cout << "Exiting program";
			return 0;
		}
		else
			cout << "Input is not part of choice" << endl;
	}

    return 0;
}

