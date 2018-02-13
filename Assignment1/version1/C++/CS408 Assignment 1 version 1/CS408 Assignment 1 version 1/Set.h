#ifndef SET_H
#define SET_H

#include <string>
#include <vector>

using namespace std;

class Set {
private:
	vector<string> set;
	int size;

public:
	Set(string input);
	Set unionSet(Set set2);
	Set intersectionSet(Set set2);
	Set differenceSet(Set set2);
	string getValue(int index);
	int getSize();
	void printSet();
};

#endif 