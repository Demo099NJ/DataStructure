#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

static const int MAX_INT = 0X7fffffff;
static const int MIN_INT = 0xffffffff;
//using Bucket sorting

class maxSpan {
private:
	struct bucket {
		bool flag;
		int max_val;
		int min_val;
		bucket(bool f = false, int max = MIN_INT, int min = MAX_INT) :flag(f), max_val(max), min_val(min) { ; }
	};

	bucket *record;
	int amount;
	int *data;
	int length;

	//private function
	int bucket_sort();
public:
	maxSpan(int n = 0);
	~maxSpan() { delete[]record;	delete[]data; }
	bool create_bucket(int len);
	int bucket_sort(int a[], int len);
	int maxSpan_process();
};
