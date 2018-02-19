#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>
#include "Set.h"
#include "Application.h"
#include <iostream>
#include <algorithm>

using namespace std;

//Header file for application class
class Application {
private:
	vector<Set> neighbors;

public:
	Application();
	void intro();
	void bronKerb(Set a, Set b, Set c);
	int getSize();
};
#endif 