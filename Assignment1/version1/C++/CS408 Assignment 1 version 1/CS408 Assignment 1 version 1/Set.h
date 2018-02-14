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
	Set operator + (Set &);
	Set operator ^ (Set &);
	Set operator - (Set &);
	string getValue(int index);
	int getSize();
	void printSet();
};

#endif 