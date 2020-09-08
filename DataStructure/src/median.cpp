#include "../include/median.h"

median::median(int len) :amount(len), top(0) {
	list = new int[amount];	assert(list != nullptr);
}

bool median::maintain() {
	if(list == nullptr) { return false; }
	if(top == 0) { return false; }
	if(top < amount - 1) { return false; }
	amount *= 2;
	int *temp = new int[amount];	assert(temp != nullptr);
	for(int i = 0; i < top; ++i) {
		temp[i] = list[i];
	}
	delete[]list;
	list = temp;
	return true;
}

//using bisection insertion sorting
bool median::insert(int tar) {
	//assert(tar != 2);
	myAlgorithm search;
	int loc = search.binary_search(list, top, tar);
	//printf("tar = %d\n", tar);
	//assert(0);
	//assert(tar != 2);
	if(loc == -1) {
		return false;
	}
	for(int i = top; i > loc; --i) {
		list[i] = list[i - 1];
	}
	//assert(tar != 2);
	//assert(0);
	//printf("loc = %d\n", loc);
	list[loc] = tar;	++top;
	//assert(tar != 1);
	//assert(0);
	return true;
}

int median::get_median() {
	//printf("top = %d, top / 2 = %d, mid is ", top, top / 2);
	switch(top % 2) {
		case 0: printf("%d %d\n", list[(top / 2) - 1], list[(top / 2)]); break;
		case 1: printf("%d\n", list[top / 2]); break;
		default: printf("KNOCK!\n"); assert(0);
	}
	return 0;
}

void median::show_list() {
	for(int i = 0; i < top; ++i) {
		printf("%d ", list[i]);
	}
	printf("\n");
	return;
}

int median::median_process() {
	int citizen(0);
	scanf("%d", &citizen);
	int income(0), middle(0);
	for(int i = 0; i < citizen; ++i) {
		scanf("%d", &income);
		insert(income);
		middle = get_median();
		printf("%d ", middle);
	}
	printf("\n");
	return 0;
}
