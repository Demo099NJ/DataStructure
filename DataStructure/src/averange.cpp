#include "../include/averange.h"

averange::averange(int a[], int len) :table(a, len) {
	if(len == 0) {
		cerr << "KNOCK: the len is supposed to be a positive number." << endl;
		return;
	}
}

int averange::ave_section(int upper, int lower) {
	long long int sum(0);
	int count(0);
	for(int i = table.search(lower); i < table.length(); ++i) {
		sum += table[i];
		if(table[i] == upper) { break; }
		else { ++count; }
	}
	return (int)(sum / count);
}

bool averange::averange_process(istream &in, ostream &out) {
	int amount(0), group_num(0);
	in >> amount >> group_num;
	int *list = new int[amount];	assert(list != nullptr);
	for(int i = 0; i < amount; ++i) {
		in >> list[i];
	}
	//get section
	//cout << "note: come here?" << endl;
	table.create_heap(list, amount);
	int upper_bound(amount - 1), lower_bound(0);
	for(int i = 0; i < group_num; ++i) {
		in >> lower_bound >> upper_bound;
		int ave = ave_section(upper_bound, lower_bound);
		out << "the averange is: " << ave << " " << endl;
	}

	delete[]list;
	return true;
}
