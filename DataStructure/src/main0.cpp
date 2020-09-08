#include "../include/averange.h"
#include "../include/median.h"
#include "../include/wageCeil.h"
#include "../include/lookUp.h"
#include "../include/maxSpan.h"

int main() {
	//test-1
	averange test1;
	test1.averange_process();

	//test-2
	median test2;
	test2.median_process();

	//test-3
	wageCeil test3;
	test3.wageCeil_process();

	//test-4
	lookUp test4;
	test4.lookUp_process();

	//test-5
	maxSpan test5;
	test5.maxSpan_process();

	return 0;
}
