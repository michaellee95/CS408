#include <iostream>
#include "Set.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//.cpp file for Set class
//Get user input

Set::Set() {
	size = 0;
}

Set::Set(string input) {
	stringstream ss(input);
	string value;

	//Create a vector object using user input seperated by comma
	while (getline(ss, value, ',')) {
		set.push_back(value);
	}

	//Sort vector and delete repeated elements
	sort(set.begin(), set.end());
	set.erase(unique(set.begin(), set.end()), set.end());

	size = set.size();
}

//Method for union
Set Set::operator + (Set &set2) {
	vector<string> uniqueSet;

	//Add all values from set 1 and set 2 into new set
	for (int i = 0; i < set.size(); i++) {
		uniqueSet.push_back(set.at(i));
	}

	for (int i = 0; i < set2.getSize(); i++) {
		uniqueSet.push_back(set2.getValue(i));
	}

	//Sort and delete repeated elements
	sort(uniqueSet.begin(), uniqueSet.end());
	uniqueSet.erase(unique(uniqueSet.begin(), uniqueSet.end()), uniqueSet.end());

	string uniqueSetAsString;

	//Turn elements of vector into string and create new set using string
	for (int i = 0; i < uniqueSet.size(); i++) {
		uniqueSetAsString += uniqueSet.at(i) + ",";
	}

	return Set(uniqueSetAsString);
}

//Method for intersection
Set Set::operator ^ (Set &set2) {
	vector<string> intersectionSet;

	//Add elements to vector if elements found in set 1 is found in set2
	for (int i = 0; i < set.size(); i++) {
		for (int j = 0; j < set2.getSize(); j++) {
			if (!set.at(i).compare(set2.getValue(j))) {
				intersectionSet.push_back(set.at(i));
			}
		}
	}

	//Sort vector
	sort(intersectionSet.begin(), intersectionSet.end());

	string intersectionSetAsString;

	//Turn elements of vector into string and create new set using string
	for (int i = 0; i < intersectionSet.size(); i++) {
		intersectionSetAsString += intersectionSet.at(i) + ",";
	}

	return Set(intersectionSetAsString);
}

//Method for difference
Set Set::operator - (Set &set2) {
	//Get the union and intersection set
	Set unionSet = (*this)+(set2);
	Set intersectionSet = (*this)^(set2);
	vector<string> differenceSet;

	bool unique = true;

	//If value is found in union set but not in intersection set than add element to new set
	for (int i = 0; i < unionSet.getSize(); i++) {
		unique = true;
		for (int j = 0; j < intersectionSet.getSize(); j++) {
			if (!unionSet.getValue(i).compare(intersectionSet.getValue(j))) {
				unique = false;
				break;
			}
		}
		if (unique)
			differenceSet.push_back(unionSet.getValue(i));
	}

	string differenceSetAsString;

	//Turn elements of vector into string and create new set using string
	for (int i = 0; i < differenceSet.size(); i++) {
		differenceSetAsString += differenceSet.at(i) + ",";
	}

	return Set(differenceSetAsString);
}

string Set::getValue(int index) {
	return set.at(index);
}

int Set::getSize() {
	return size;
}

vector<string> Set::getSet() {
	return set;
}

void Set::addElement(string input) {
	set.push_back(input);
	size = set.size();
}

//Method for printing values of set
void Set::printSet() {
	for (int i = 0; i < set.size(); i++) {
		cout << set.at(i) + " ";
	}

	cout << endl;
}