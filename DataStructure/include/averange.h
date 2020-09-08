#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include "myHeap.h"
using namespace std;

class averange {
private:
	myHeap table;
public:
	averange(int amo = 2) :table(amo) { ; };
	averange(int arr[], int len); 
	~averange() { ; }
	int length() const { return table.length(); }
	void show_data() { table.show_heap(); }
	int ave_section(int upper, int lower);
	bool averange_process(istream &in = cin, ostream &out = cout);
};
