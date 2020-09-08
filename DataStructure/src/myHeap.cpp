#include "../include/myHeap.h"

myHeap::myHeap(int a) :amount(a), top(0) {
	if(a == 0) {
		root = nullptr;	return;
	}
	root = new int[amount];	assert(root != nullptr);
}

myHeap::myHeap(int a[], int len) :amount(len), top(0) {
	if(len <= 0) {
		printf("KNOCK: the len should be greater than 0;");
		amount = 0;	return;
	}
	root = new int[amount];	assert(root != nullptr);
	for(int i = 0; i < len; ++i) {
		root[i] = a[i];
	}
}

myHeap::myHeap(const myHeap &heap) {
	amount = heap.amount;
	top = heap.top;
	root = new int[amount];	assert(root != nullptr);
	for(int i = 0; i < top; ++i) {
		root[i] = heap.root[i];
	}
	return;
}

bool myHeap::maintain() {
	if(top < amount - 1) {
		return false;
	}
	amount *= 2;
	int *temp = new int[amount];	assert(temp != nullptr);
	for(int i = 0; i < top; ++i) {
		temp[i] = root[i];
	}
	delete[]root;
	root = temp;
	return true;
}

bool myHeap::heap_init() {
	if(top <= 0) { return false; }
	int loc((top - 1) / 2), next_loc(loc);
	for(int i = loc; i >= 0; --i) {
		bool sign = compare_adjust(i, next_loc);
		while(sign) {
			loc = next_loc;
			sign = compare_adjust(loc, next_loc);
		}
	}
	return true;
}

bool myHeap::up_shift(int loc) {
	myAlgorithm swap;
	//printf("In function: up_shift()\n");
	if(top <= 0) { return false; }
	int father_loc = get_father(loc);
	//printf("loc = %d, father_loc = %d\n", loc, father_loc);
	while(loc > 0 && root[father_loc] < root[loc]) {
		swap.swap_element(&root[father_loc], &root[loc]);
		loc = father_loc;
		father_loc = get_father(loc);
		//printf("loc = %d, father_loc = %d\n", loc, father_loc);
	}
	return true;
}

bool myHeap::down_shift(int loc) {
	if(top <= 0) { return false; }
	int next_loc(0);
	bool sign = compare_adjust(loc, next_loc);
	while(sign) {
		loc = next_loc;
		sign = compare_adjust(loc, next_loc);
	}
	return true;
}

bool myHeap::compare_adjust(int loc, int &next_loc) {
	next_loc = get_left_child(loc);
	int *temp(nullptr);
	if(is_null(next_loc)) {
		return false;
	}
	temp = &root[next_loc];
	int right_loc = get_right_child(loc);
	if(!is_null(right_loc))  {
		if(root[right_loc] > root[next_loc]) {
			next_loc = right_loc;
			temp = &root[next_loc];
		}
	}
	myAlgorithm swap;
	if((*temp) > root[loc]) {
		swap.swap_element(temp, &root[loc]);
		return true;
	}
	else {
		return false;
	}
}

bool myHeap::insert(int val) {
	maintain();
	//bool sign = maintain();
	//printf("sign = %d\n", sign);
	root[top] = val;	++top;
	up_shift(top - 1);
	return true;
}

bool myHeap::extract(int &val) {
	val = root[0];	--top;
	root[0] = root[top];
	down_shift(0);
	return true;
}

bool myHeap::heap_sort() {
	int len(top);
	heap_init();
	myAlgorithm swap;
	swap.swap_element(&root[0], &root[len - 1]);	--len;
	//printf("emmm...in \"for\" loop?");
	for(int i = 1; i < top; ++i) {
		//printf("In down_shift\n");
		down_shift(0);
		//printf("In swap_element\n");
		//printf("swap_element(root[0] = %d, root[%d] = %d)\n", root[0], len - 1, root[len - 1]);
		swap.swap_element(&root[0], &root[len - 1]);	--len;
	}
	//printf("Not here?\n");
	return true;
}

bool myHeap::heap_sort(int result[], int len) {
	if(len < top) {
		return false;
	}
	//store the sence
	int *temp = new int[len];	assert(temp != nullptr);
	for(int i = 0; i < len; ++i) {
		temp[i] = root[i];
	}
	//code reuse
	heap_sort();
	//restore the sence
	for(int i = 0; i < top; ++i) {
		result[i] = root[i];
		root[i] = temp[i];
	}
	return true;
}

//if exists, return its location
//else, return the next location of this element
int myHeap::search(int tar) {
	myAlgorithm search;
	int loc = search.binary_search(root, top, tar);
	return loc;

	////useless
	//int left(0), right(len - 1), mid(0);
	//bool in_list(false);
	////printf("target = %d\n", tar);
	//while(left < right) {
	//	mid = (left + right) / 2;
	//	//printf("mid = %d\n", mid);
	//	if(root[mid] == tar) {
	//		//printf("root[mid](%d) == tar(%d)\n", root[mid], tar);
	//		in_list = true; break;
	//	}
	//	else if(root[mid] > tar) {
	//		//printf("root[mid](%d) > tar(%d)\n", root[mid], tar);
	//		right = mid;
	//	}
	//	else if(root[mid] < tar) {
	//		//printf("root[mid](%d) < tar(%d)\n", root[mid], tar);
	//		left = mid + 1;
	//	}
	//}
	//if(in_list) { return mid; }
	//else if(!in_list && tar > root[len - 1]) { return len; }
	//else if(!in_list) { return left; }
	//else { return -1; }
}

bool myHeap::create_heap(int val[], int len) {
	if(root != nullptr) {
		delete[]root;
	}
	//printf("emmm...delete?");
	amount = len;	top = len;
	root = new int[amount];	assert(root != nullptr);
	for(int i = 0; i < len; ++i) {
		root[i] = val[i];
	}
	heap_sort();
	return true;
}

void myHeap::show_heap() {
	for(int i = 0; i < top; ++i) {
		printf("%d ", root[i]);
	}
	//printf("but why?\n");
	printf("\n");
}

myHeap& myHeap::operator = (const myHeap &heap) {
	if(this == &heap) { return (*this); }
	amount = heap.amount;
	top = heap.top;
	if(root != nullptr) { delete[]root; }
	root = new int[amount];	assert(root != nullptr);
	for(int i = 0; i < top; ++i) {
		root[i] = heap.root[i];
	}
	return (*this);
}
