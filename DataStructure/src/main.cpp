#include "../include/myHeap.h"
#include "../include/averange.h"
#include "../include/median.h"
#include "../include/wageCeil.h"
#include "../include/maxSpan.h"
//#include "../include/heap.h"
#include <fstream>

int main4() {
	int a[10] = { 0, 9, 5, 1, 4, 3, 7, 6, 8, 2 };
	myHeap temp_heap;
	temp_heap.create_heap(a, 10);
	temp_heap.show_heap();
	temp_heap.heap_sort(a, 10);
	for(int i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

int main3() {
	maxSpan temp;
	int a[5] = { 10000, 40000, 8000, 60000, 28000 };
	cout << temp.bucket_sort(a, 5) << endl;
	return 0;
}

int main2() {
	string str("123456789");
	wageCeil temp;
	cout << temp.turn_int(str) << endl;
	return 0;
	int b[10] = { 0, 9, 5, 1, 4, 3, 7, 6, 8, 2 };
	wageCeil wage;
	for(int i = 0; i < 10; ++i) {
		wage.add_data(b[i]);
		//wage.show_data();
	}
	wage.show_data();
	wage.inquiry(5);
	printf("\n");
	return 0;
}

int main1() {
	int b[10] = { 0, 9, 5, 1, 4, 3, 7, 6, 8, 2 };
	//int a[10];	for(int i = 0; i < 10; ++i) { a[i] = i; }
	median temp(10);
	//assert(0);
	for(int i = 0; i < 10; ++i) {
		//cout << "inserting..." << endl;
		//assert(i < 1);
		//temp.insert(a[i]);
		temp.insert(b[i]);
		//assert(i < 1);
		//temp.show_list();
		//printf("mid is ");
		temp.get_median();
		printf("\n");
	}
	temp.show_list();
	return 0;
}

int main0(int argc, char *argv[]) {
	/*int a[10] = { 0 };
	for (int i = 0; i < 10; ++i) {
		a[i] = i + i;
	}
	
	int b[10] = { 0, 9, 5, 1, 4, 3, 7, 6, 8, 2 };
	myHeap list(b, 10);	list.create_heap(a, 10);
	list.heap_sort();
	list.show_heap();
	return 0;

	printf("list.search(%d) = %d\n\n", -1, list.search(-1, 10));
	for(int i = 0; i < 10; ++i) {
		list.show_heap();
		printf("list.search(%d) = %d\n\n", i, list.search(i, 10));
	}
	printf("list.search(%d) = %d\n\n", 20, list.search(20, 10));
	return 0;*/
	//averange revenue(a, 10);
	//averange revenue(b, 10);
	averange revenue;
	if(argc <= 1) {
		revenue.averange_process();
		cout << "the whole data: ";
		revenue.show_data();
		cout << "the length: " << revenue.length() << endl << endl;
		return 0;
	}
	ifstream fin;
	for(int i = 1; i < argc; ++i) {
		cout << "the name of the file is " << argv[i] << endl;
		fin.open(argv[i]);	assert(fin.is_open());
		revenue.averange_process(fin, cout);
		cout << "the whole data: ";
		revenue.show_data();
		cout << "the length: " << revenue.length() << endl << endl;
		fin.close();
	}
	return 0;
}
