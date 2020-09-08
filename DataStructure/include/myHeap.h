#pragma once
#include <iostream>
#include <assert.h>
#include "myAlgorithm.h"
using namespace std;

//enum child { LEFT, RIGHT };

class myHeap {
private:
	int *root;
	int amount;
	int top;
	//private function
	int get_father(int tar) { return (tar - 1) / 2; }
	int get_left_child(int tar) { return (tar * 2) + 1; }
	int get_right_child(int tar) { return (tar * 2) + 2; }
	bool is_null(int tar) { return ((tar < 0) || (tar >= top)); }
	//bool swap_element(int *x, int *y);
	bool maintain();

	//for heap
	bool heap_init();
	bool up_shift(int loc);
	bool down_shift(int loc);
	bool compare_adjust(int loc, int &next_loc);
public:
	myHeap(int a = 2);
	myHeap(int a[], int len);
	myHeap(const myHeap &heap);
	~myHeap() { delete[]root; }
	int length() const { return top; }
	bool insert(int val);
	bool extract(int &val);
	bool heap_sort();
	bool heap_sort(int result[], int len);
	int search(int tar);
	bool create_heap(int val[], int len);
	void show_heap();
	int &operator [] (int loc) { return root[loc]; }
	myHeap &operator = (const myHeap &heap);
};

