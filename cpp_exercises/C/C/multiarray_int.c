#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_array(const int *array[][3]);

int array[2][3] = {1,2,3,4,5,6};

main () {
	int *array_p = array[0];
	print_array(array_p);
	exit(EXIT_SUCCESS);
}

void
print_array(const int *array[][3]) {
	int i,j;
	for(i=0;i<2;i++) {
		for(j=0;j<3;j++) {
			printf("array[%d][%d] = %d\n", i, j, array[i][j]);
		}
	}
}
