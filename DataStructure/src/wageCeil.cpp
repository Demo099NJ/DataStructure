#include "../include/wageCeil.h"

bool wageCeil::inquiry(int len) {
	myHeap temp(heap);
	int element(0);
	for(int i = 0; i < len; ++i) {
		heap.extract(element);
		printf("%d ", element);
	}
	return true;
}

int wageCeil::turn_int(const string &str) {
	int result(0);
	for(int i = 0; i < (int)str.length(); ++i) {
		result = result * 10 + (str[i] - '0');
	}
	return result;
}

int wageCeil::wageCeil_process() {
	int citizen(0), top_num(0);
	scanf("%d%d", &citizen, &top_num);
	string input;
	for(int i = 0; i < citizen; ++i) {
		cin >> input;
		if(input == "Check") {
			inquiry(top_num);
		}
		else {
			add_data(turn_int(input));
		}
	}
	//inquiry(top_num);
	return 0;
}
