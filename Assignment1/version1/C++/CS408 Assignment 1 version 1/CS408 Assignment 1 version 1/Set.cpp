#include <iostream>
#include "Set.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

Set::Set(string input) {

	int i;
	stringstream ss(input);
	string value;

	while (getline(ss, value, ',')) {
		set.push_back(value);
	}

	sort(set.begin(), set.end());
	set.erase(unique(set.begin(), set.end()), set.end());

	size = set.size();
}

Set Set::operator + (Set &set2) {
	vector<string> uniqueSet;

	for (int i = 0; i < set.size(); i++) {
		uniqueSet.push_back(set.at(i));
	}

	for (int i = 0; i < set2.getSize(); i++) {
		uniqueSet.push_back(set2.getValue(i));
	}

	sort(uniqueSet.begin(), uniqueSet.end());
	uniqueSet.erase(unique(uniqueSet.begin(), uniqueSet.end()), uniqueSet.end());

	string uniqueSetAsString;

	for (int i = 0; i < uniqueSet.size(); i++) {
		uniqueSetAsString += uniqueSet.at(i) + ",";
	}

	return Set(uniqueSetAsString);
}

Set Set::operator ^ (Set &set2) {
	vector<string> intersectionSet;

	for (int i = 0; i < set.size(); i++) {
		for (int j = 0; j < set2.getSize(); j++) {
			if (!set.at(i).compare(set2.getValue(j))) {
				intersectionSet.push_back(set.at(i));
			}
		}
	}

	sort(intersectionSet.begin(), intersectionSet.end());

	string intersectionSetAsString;

	for (int i = 0; i < intersectionSet.size(); i++) {
		intersectionSetAsString += intersectionSet.at(i) + ",";
	}

	return Set(intersectionSetAsString);
}

Set Set::operator - (Set &set2) {
	Set unionSet = (*this)+(set2);
	Set intersectionSet = (*this)^(set2);
	vector<string> differenceSet;

	bool unique = true;

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

void Set::printSet() {
	string prefix = "";
	for (int i = 0; i < set.size(); i++) {
		cout << prefix + set.at(i);
		prefix = ",";
	}

	cout << endl;
}