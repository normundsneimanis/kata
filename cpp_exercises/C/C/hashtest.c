#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main(void) {
	unsigned short int array[ROWS][COLS] = { 1, 2, 3,
											4, 5, 6,
											7, 8, 9 };
	int i, j;
	for(i = 0; i < ROWS; i++) {
		/* printf("i=%i\n", i); */
		for(j = 0; j < COLS; j++) {
			printf("array[%i][%i] value: %d\n", i, j, array[i][j]);
		}
	}
	exit(EXIT_SUCCESS);
}
