#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int array[] = {10,11,12,13,14};
	int *ptr;
	ptr = &array[0];
	int i;
	for(i=0; i <= 4; i++) {
		printf("Array elemnt %d is %d\n", i, *(ptr + i));
	}
	return(EXIT_SUCCESS);
}
