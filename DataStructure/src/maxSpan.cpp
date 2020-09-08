#include "../include/maxSpan.h"

maxSpan::maxSpan(int n) :amount(n + 1), length(n) {
	if(length == 0) {
		record = nullptr;	data = nullptr;
		return;
	}
	record = new bucket[amount];	assert(record != nullptr);
	data = new int[length];	assert(data != nullptr);
}

bool maxSpan::create_bucket(int len) {
	if(length != 0 && length < len) {
		//amount = len;
		//cout << "Here?" << endl;
		delete[]record;	delete[]data;
		//return false;
	}
	//cout << "Here?" << endl;
	length = len;	amount = len + 1;
	record = new bucket[amount];	assert(record != nullptr);
	data = new int[length];	assert(data != nullptr);
	return true;
}

int maxSpan::bucket_sort(int a[], int len) {
	//get copy
	create_bucket(len);
	for(int i = 0; i < len; ++i) {
		data[i] = a[i];
	}
	//cout << "Here?" << endl;
	//for(int i = 0; i < len; ++i) {
	//	cout << data[i] << " ";
	//}
	//cout << endl;
	return bucket_sort();
}

int maxSpan::bucket_sort() {
	//get the maximum and the minimum
	int low_bound(MAX_INT), high_bound(MIN_INT);
	for(int i = 0; i < length; ++i) {
		low_bound = ((low_bound < data[i]) ? low_bound : data[i]);
		high_bound = ((high_bound > data[i]) ? high_bound : data[i]);
	}
	//printf("low = %d, high = %d\n", low_bound, high_bound);

	//divide the numbers into "amount" buckets
	int gap = (high_bound - low_bound) / amount;
	int remainder = (high_bound - low_bound) % amount;
	gap += ((remainder >= (amount / 2)) ? 1 : 0);
	//printf("gap = %d\n", gap);

	//establish mapping
	int loc(0);
	int temp_max(0), temp_min(0);
	for(int i = 0; i < length; ++i) {
		loc = (data[i] - low_bound) / gap;
		//printf("loc = %d\n", loc);
		temp_max = record[loc].max_val;	temp_min = record[loc].min_val;
		record[loc].flag = true;
		record[loc].max_val = ((temp_max > data[i]) ? temp_max : data[i]);
		record[loc].min_val = ((temp_min < data[i]) ? temp_min : data[i]);
	}
	//for(int i = 0; i < amount; ++i) {
	//	printf("record[%d].max = %d, record[%d].min = %d\n", i, record[i].max_val, i, record[i].min_val);
	//}

	//get final result
	//the first bucket is supposed to be not empty, because of low bound
	int result_max(record[0].max_val), temp_gap(0);
	int present_loc(0), previ_loc(0);
	for(int i = 2; i < amount; ++i) {
		if(record[i].flag) {
			//printf("i = %d\n", i);
			previ_loc = present_loc;	present_loc = i;
			temp_gap = record[present_loc].min_val - record[previ_loc].max_val;
			result_max = ((temp_gap > result_max) ? temp_gap : result_max);
		}
	}
	return result_max;
}

int maxSpan::maxSpan_process() {
	int len(0);
	scanf("%d", &len);
	create_bucket(len);
	for(int i = 0; i < len; ++i) {
		scanf("%d", &data[i]);
	}
	int max_gap = bucket_sort();
	printf("%d\n", max_gap);
	return 0;
}
