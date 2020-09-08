#pragma once
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

enum child { RIGHT, LEFT };

class heap {
private:
	int *root;
	int amount;
	//
	bool maintain();
	bool maintain(int loc, int v);
	int get_father(int v) { return (v + 1) / 2; }
	int get_left_child(int v) { return (v * 2) + 1; }
	int get_right_child(int v) { return (v * 2) + 2; }
	bool is_null(int v, int top) { return ((v < 0) || (v >= top)); }
	bool swap_element(int &x, int &y);
	bool swap_element(int *x, int *y);
	//
	bool up_shift(int top);
	bool down_shift(int top);
	bool compare_to_adjust(int location, int top, child &dir);
	int ave_section(int upper, int lower, int top);
public:
	heap(int a = 0);
	heap(int a[], int len);
	~heap() { delete[]root; }
	int length() const { return amount; }
	bool create_heap(int a[], int len);
	void show_heap();
	bool heap_sort();
	int search(int tar, int top);
	int ave_section(int upper, int lower) { return ave_section(upper, lower, amount); }
	//int &operator [] (const int &loc) { return root[i]; }
};
