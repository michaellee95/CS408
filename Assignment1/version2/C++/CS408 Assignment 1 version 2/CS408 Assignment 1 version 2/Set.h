#ifndef SET_H
#define SET_H

#include <string>

using namespace std;

//Header file for set class
class Set {

public:
	typedef struct node {
		string value;
		node* next;
	}*nodePtr;

	Set(string input);
	Set();
	Set operator + (Set &);
	Set operator ^ (Set &);
	Set operator - (Set &);
	void printSet();
	void addNode(nodePtr);
	void addNode(string);
	nodePtr getHead();
	int getSize();

private:
	nodePtr head;
	nodePtr end;
	int size;
};

#endif 
