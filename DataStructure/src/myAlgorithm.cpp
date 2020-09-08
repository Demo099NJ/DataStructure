#include "../include/myAlgorithm.h"

int myAlgorithm::binary_search(int model[], int len, int tar) {
	int left(0), right(len - 1), mid(0);
	bool in_list(false);
	//printf("target = %d\n", tar);
	while(left < right) {
		mid = (left + right) / 2;
		//printf("mid = %d\n", mid);
		if(model[mid] == tar) {
			//printf("root[mid](%d) == tar(%d)\n", root[mid], tar);
			in_list = true; break;
		}
		else if(model[mid] > tar) {
			//printf("root[mid](%d) > tar(%d)\n", root[mid], tar);
			right = mid;
		}
		else if(model[mid] < tar) {
			//printf("root[mid](%d) < tar(%d)\n", root[mid], tar);
			left = mid + 1;
		}
	}
	if(in_list) { return mid; }
	else if(!in_list && tar > model[len - 1]) { return len; }
	else if(!in_list) { return left; }
	else { return -1; }
}

bool myAlgorithm::swap_element(int *x, int *y) {
	int temp = (*x);
	(*x) = (*y);
	(*y) = temp;
	return true;
}
