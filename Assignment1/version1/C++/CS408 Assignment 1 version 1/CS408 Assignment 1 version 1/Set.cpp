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

Set Set::unionSet(Set set2) {
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

Set Set::intersectionSet(Set set2) {
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

Set Set::differenceSet(Set set2) {
	vector<string> differenceSet;


	string differenceSetAsString;

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