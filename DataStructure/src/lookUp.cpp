#include "../include/lookUp.h"

lookUp::lookUp() :amount(CARDINAL) {
	hashTable = new hashHead[amount];	assert(hashTable != nullptr);
}

int lookUp::get_flag(const string &str) {
	int result(0);
	for(int i = 0; i < (int)str.length(); ++i) {
		result += (int)(str[i]) * WEIGHT;
	}
	return result % FLAG;
}

int lookUp::hash(const string &str) {
	int result(0);
	for(int i = 0; i < (int)str.length(); ++i) {
		result += (int)(str[i]) * WEIGHT;
	}
	return result % CARDINAL;
}

bool lookUp::search(const string &str) {
	int hash_num(0), flag(0);
	return search(str, hash_num, flag);
}

bool lookUp::search(const string &str, int &hash_num, int &flag) {
	hash_num = hash(str);
	flag = get_flag(str);
	hashHead *ptr = hashTable[hash_num].next;
	bool find_it(false);
	while(ptr != nullptr) {
		if(ptr->flag == flag) {
			find_it = true;	break;
		}
		else {
			ptr = ptr->next;
		}
	}
	return find_it;
}

bool lookUp::insert(const string &str) {
	int hash_num(0), flag(0);
	if(search(str, hash_num, flag)) {
		return true;
	}
	//int hash_num = hash(str);
	//int flag = get_flag(str);
	hashHead *ptr = new hashHead(flag, hashTable[hash_num].next);
	hashTable[hash_num].next = ptr;
	return true;
}

int lookUp::lookUp_process() {
	int citizen(0), table_amount(0);
	scanf("%d%d", &citizen, &table_amount);
	string ID;
	for(int i = 0; i < citizen; ++i) {
		cin >> ID;
		insert(ID);
	}
	bool sign(true);
	for(int i = 0; i < table_amount; ++i) {
		cin >> ID;
		sign = search(ID);
		switch(sign) {
			case true: printf("true\n"); break;
			case false: printf("false\n"); break;
			//default: printf("KNOCK\n"); break;
		}
	}
	return 0;
}
