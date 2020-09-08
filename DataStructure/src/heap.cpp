#include "../include/heap.h"

heap::heap(int a) :amount(a) {
	//cout << "In averange.cpp: emmm...have come here?" << endl;
	if(a == 0) {
		root = nullptr;	return;
	}
	root = new int[amount];	assert(root != nullptr);
}

heap::heap(int a[], int len) :amount(len) {
	if(len == 0) {
		cerr << "KNOCK: the len is supposed to be a positive number." << endl;
		return;
	}
	root = new int[amount];	assert(root != nullptr);
	for(int i = 0; i < amount; ++i) {
		root[i] = a[i];
	}
	//heap_sort();
    up_shift(amount);
}

bool heap::swap_element(int &x, int &y) {
	//if(&x == nullptr || &y == nullptr) { return false; }
	int temp = x;	x = y;	y = temp;
	return true;
}

bool heap::swap_element(int *x, int *y) {
	if(x == nullptr || y == nullptr) { return false; }
	int temp = (*x);	(*x) = (*y);	(*y) = temp;
	return true;
}

bool heap::compare_to_adjust(int location, int top, child &dir) {
	bool sign(false);
	int left_child = get_left_child(location);
	int right_child = get_right_child(location);
	//the left_child can't be empty pointer
	//2 situations: all are null, the right is null && left is not null, all are not null
	if(is_null(left_child, top) && is_null(right_child, top)) {
		//dir = child::LEFT;
		return sign;
	}
	else if(is_null(right_child, top)) {
		if(root[left_child] >= root[location]) {
			swap_element(root[left_child], root[location]);
			sign = true;	dir = child::LEFT;
		}
	}
	else {
		int *temp = &root[left_child];
		if(root[right_child] > (*temp)) {
			temp = &root[right_child];
			dir = child::RIGHT;
		}
		if((*temp) > root[location]) {
			swap_element(temp, &root[location]);
			sign = true; dir = child::LEFT;
		}
	}
	return sign;
}

//"top" represents the present len of the unsorted heap;
bool heap::up_shift(int top) {
	if(top <= 0) { return false; }
	//begin from the first vertise of 2 degrees or 1 degree
	int location((top - 1) / 2);
	//cout << "In averange.cpp: location = " << location << endl;
	child dir;
	//show_data();
	for(int i = location; i >= 0; --i) {
		compare_to_adjust(location, top, dir);
		//show_data();
		--location;
	}
	return true;
}

bool heap:: down_shift(int top) {
	int location(0);
	bool sign(true);
	child dir;
	for(int i = 1; i < top && sign; ++i) {
		sign = compare_to_adjust(location, top, dir);
		//show_data();
		if(!sign) { break; }
		switch(dir) {
			case child::LEFT: location = get_left_child(location); break;
			case child::RIGHT: location = get_right_child(location); break;
			default: cerr << "KNOCK: it's impossible---dir = " << dir << endl; assert(0); break;
		}
		if(is_null(location, top)) { sign = false; }
	}
	return true;
}

bool heap::heap_sort() {
	int top(amount);
	up_shift(top);
	//swap the first and the last number && update the "top"
	swap(root[0], root[top - 1]);	--top;
	//show_data();
	//loop
	for(int i = 1; i < amount; ++i) {
		down_shift(top);
		swap(root[0], root[top - 1]);	--top;
	}
	return true;
}

void heap::show_heap() {
	for(int i = 0; i < amount; ++i) {
		cout << root[i] << " ";
	}
	cout << endl;	return;
}

bool heap::create_heap(int a[], int len) {
	if(len <= 0) {
		cerr << "KNOCK: the len of the array is supposed to be a positive number." << endl;
	}
	if(root != nullptr) {
		delete[]root; amount = 0;
	}
	amount = len;
	root = new int[amount];	assert(root != nullptr);
	for(int i = 0; i < amount; ++i) {
		root[i] = a[i];
	}
	heap_sort();
	return true;
}

int heap::search(int target, int top) {
	//binary search the lower bound
	int left(0), right(top - 1), mid(0);
	printf("target = %d:\n", target);
	while(left < right) {
		mid = (left + right) / 2;
		printf("left = %d, right = %d, ", left, right);
		printf("root[mid] = %d, mid = %d, the whole list is: ", root[mid], mid);
		show_heap();
		if(root[mid] == target) {	break;	}
		else if(root[mid] > target) {	right = mid - 1;	}
		else if(root[mid] < target) {	left = mid + 1; mid = left;	}
		else { cerr << "KNOCK: it's impossible..for three times...\n"; assert(0); }
	}
	printf("finally, mid = %d\n\n", mid);
	//cout << "root[mid] = " << root[mid] << ", mid = " << mid << endl;
	return mid;
}

int heap::ave_section(int upper, int lower, int top) {
	//long long int sum(0);
	int sum(0);

	//sum the numbers
	//bool get_end(false);
	int loc_lower = search(lower, amount), loc_upper = search(upper, amount);
	int len = loc_upper - loc_lower;
	int ave(0), remainder(0);
	for(int i = loc_lower; i < loc_upper; ++i) {
		//sum += root[i];
		cout << "root[i] = " << root[i] << ", sum = " << sum << endl;

		//the second way
		sum += root[i] / len;
		remainder += root[i] % len;
	}
	cout << "len = " << len << endl;
	//ave = sum / len;
	ave = sum + remainder / len;
	return ave;	
}
