#include <stdio.h>
#include "4_3_signals.h"
#include "stack.h"

int main(void) {
	if (!swap()) {
		printf("Ok swap fails on empty stack\n");
	} else {
		printf("Fail swap fails on empty stack\n");
	}

	push(1);
	push(2);
	backup();
	swap();
	double a,b;
	a = pop();
	b = pop();
	if ((int) a != 1 || (int) b != 2) {
		printf("Fail after swap: %i %i (1 2)\n", (int) a, (int) b);
	} else {
		printf("Ok swap: %i %i\n", (int) a, (int) b);
	}

	restore();
	a = pop();
	b = pop();
	if ((int) a != 2 || (int) b != 1) {
		printf("Fail after restore: %i %i (1 2)\n", (int) a, (int) b);
	} else {
		printf("Ok restore: %i %i\n", (int) a, (int) b);
	}

	clear();
	a = pop();
	if (!a) {
		 printf("Ok clear succeeded\n");
	} else {
		printf("Fail clear failed %i\n", (int) a);
	}
	return 0;
}


