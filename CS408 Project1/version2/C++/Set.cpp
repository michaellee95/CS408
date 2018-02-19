#include <iostream>
#include "Set.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//Constructor to create empty set
Set::Set() {
	head = NULL;
	end = NULL;
	size = 0;
}

//Constructor for set when input is given
Set::Set(string input) {
	vector<string> inputAsVector;
	head = NULL;
	end = NULL;

	stringstream ss(input);
	string value;

	//Create a vector object using user input seperated by comma
	while (getline(ss, value, ',')) {
		inputAsVector.push_back(value);
	}

	//sort and remove duplicate elements
	sort(inputAsVector.begin(), inputAsVector.end());
	inputAsVector.erase(unique(inputAsVector.begin(), inputAsVector.end()), inputAsVector.end());

	//Create new node and add them to set
	for (int i = 0; i < inputAsVector.size(); i++) {
		nodePtr newNode = new node;
		newNode->next = NULL;
		newNode->value = inputAsVector.at(i);
		
		//if head is not null just add to end of set
		//else new node becomes head
		if (head != NULL) {
			end->next = newNode;
			end = newNode;
		}
		else {
			head = newNode;
			end = newNode;
		}
		size++;
	}
}

//Method to add new node to set
void Set::addNode(nodePtr passedNode) {

	//Create a new node and pass the value from passed node
	nodePtr newNode = new node;
	newNode->value = passedNode->value;
	newNode->next = NULL;

	//if head is not null just add to end of set
	//else new node becomes head
	if (head != NULL) {
		end->next = newNode;
		end = newNode;
	}
	else {
		head = newNode;
		end = newNode;
	}
	size++;
}

//Method to add new node to set
void Set::addNode(string input) {

	//Create a new node and pass the value from passed node
	nodePtr newNode = new node;
	newNode->value = input;
	newNode->next = NULL;

	//if head is not null just add to end of set
	//else new node becomes head
	if (head != NULL) {
		end->next = newNode;
		end = newNode;
	}
	else {
		head = newNode;
		end = newNode;
	}
	size++;
}

//Method to find union of two sets
Set Set::operator + (Set &set2) {

	Set unionSet;
	nodePtr current = head;


	//Add nodes in set 1 to unionSet
	while (current != NULL) {
		unionSet.addNode(current);
		current = current->next;
	}

	nodePtr currentUnionSet = unionSet.head;
	nodePtr set2Current = set2.head;
	bool unique = true;


	//Add nodes in set 2 to unionSet if it does not exist already
	while (set2Current != NULL) {
		unique = true;
		currentUnionSet = unionSet.head;
		while (currentUnionSet != NULL) {
			if (currentUnionSet->value == set2Current->value) {
				unique = false;
				break;
			}
			else
				currentUnionSet = currentUnionSet->next;
		}
		if (unique) {
			unionSet.addNode(set2Current);
		}
		set2Current = set2Current->next;
	}

	return unionSet;
}

//Method to find intersection of two sets
Set Set::operator ^ (Set &set2) {
	Set intersectionSet;
	nodePtr set1Current = head;
	nodePtr set2Current = set2.head;

	//Loop through first and second set
	//If a element is found in both set add to intersectionSet
	while (set1Current != NULL) {
		set2Current = set2.head;
		while (set2Current != NULL) {
			if (set1Current->value == set2Current->value) {
				intersectionSet.addNode(set1Current);
				break;
			}
			else
				set2Current = set2Current->next;
		}
		set1Current = set1Current->next;
	}

	return intersectionSet;
}

//Method for difference
Set Set::operator - (Set &set2) {
	//Get the union and intersection set
	Set unionSet = (*this) + (set2);
	Set intersectionSet = (*this) ^ (set2);
	Set differenceSet;

	nodePtr unionSetCurrent = unionSet.head;
	nodePtr intersectionSetCurrent = intersectionSet.head;
	bool unique = true;

	//Loop through first and second set
	//If a element is not found in intersection set but found in union set
	//Add to difference set
	while (unionSetCurrent != NULL) {
		unique = true;
		intersectionSetCurrent = intersectionSet.head;
		while (intersectionSetCurrent != NULL) {
			if (!unionSetCurrent->value.compare(intersectionSetCurrent->value)) {
				unique = false;
				break;
			}
			else
				intersectionSetCurrent = intersectionSetCurrent->next;
		}

		if (unique) {
			differenceSet.addNode(unionSetCurrent);
		}

		unionSetCurrent = unionSetCurrent->next;
	}

	return differenceSet;
}

//Method to get the head of the set
Set::nodePtr Set::getHead() {
	return head;
}

//Method to get size of set
int Set::getSize() {
	return size;
}

//Method to print values in set
void Set::printSet() {
	nodePtr current = head;

	//Loop from head and print value held in each node
	while (current != NULL) {
		cout << current->value + " ";
		current = current->next;
	}
	cout << endl;
}