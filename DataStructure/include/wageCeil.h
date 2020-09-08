#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include "myHeap.h"
using namespace std;

class wageCeil {
private:
	myHeap heap;
public:
	wageCeil() { ; };
	~wageCeil() { ; };
	int turn_int(const string &str);
	bool add_data(int val) { return heap.insert(val); }
	bool inquiry(int k);
	void show_data() { heap.show_heap(); }
	int wageCeil_process();
};
