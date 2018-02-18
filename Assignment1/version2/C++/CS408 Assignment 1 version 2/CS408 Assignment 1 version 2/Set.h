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

public:
	Set(string input);
	Set();
	Set operator + (Set &);
	Set operator ^ (Set &);
	Set operator - (Set &);
	void printSet();
	void addNode(nodePtr newNode);
};

#endif 
