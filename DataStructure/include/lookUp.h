#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

static const int CARDINAL = 19260817;
static const int FLAG = 1315423911;
static const int WEIGHT = 1116;

class lookUp {
private:
	struct hashHead {
		int flag;
		hashHead *next;
		hashHead(int f = 0, hashHead *n = nullptr) :flag(f), next(n) { ; }
	};

	hashHead *hashTable;
	int amount;

	//private function
	bool search(const string &str, int &heah_num, int &flag);
public:
	lookUp();
	~lookUp() { delete[]hashTable; }
	int hash(const string &str);
	int get_flag(const string &str);
	bool search(const string &str);
	bool insert(const string &str);
	int lookUp_process();
};
