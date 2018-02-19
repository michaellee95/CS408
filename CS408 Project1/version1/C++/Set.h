#ifndef SET_H
#define SET_H

#include <string>
#include <vector>

using namespace std;

//Header file for set class
class Set {
private:
	vector<string> set;
	int size;

public:
	Set();
	Set(string input);
	Set operator + (Set &);
	Set operator ^ (Set &);
	Set operator - (Set &);
	string getValue(int index);
	void addElement(string input);
	int getSize();
	void printSet();
	vector<string> getSet();
};

#endif 