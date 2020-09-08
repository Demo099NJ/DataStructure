#pragma once
#include <iostream>
#include <assert.h>
#include "myAlgorithm.h"
using namespace std;

class median {
private:
	int *list;
	int amount;
	int top;
	//private function
	bool maintain();
public:
	median(int len = 2);
	~median() { delete[]list; }
	bool insert(int tar);
	int get_median();
	void show_list();
	int median_process();
};
