#ifndef SET_H
#define SET_H

#include <string>

using namespace std;

//Header file for set class
class Set {
private:
	typedef struct node {
		string value;
		node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr end;
	int size;

public:
	nodePtr current;
	Set(string input);
	Set();
	Set operator + (Set &);
	Set operator ^ (Set &);
	Set operator - (Set &);
	void printSet();
	void addNode(nodePtr);
	void addNode(string);
	nodePtr getNext(nodePtr);
	nodePtr getHead();
	int getSize();
};

#endif 
