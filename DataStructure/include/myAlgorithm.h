#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myAlgorithm {
//private:
//	string name;
public:
	myAlgorithm() { ; }
	~myAlgorithm() { ; }
	int binary_search(int model[], int len, int tar);
	bool swap_element(int *x, int *y);
};
