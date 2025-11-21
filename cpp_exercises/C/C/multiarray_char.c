#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_array(char array[][3]);

int main () {
	char array[3][3];
	strcpy((array)[0], "ab");
	strcpy((array)[1], "cd");
	print_array(array);
	printf("after print_array: array[0] = %s\n", array[0]);
	exit(EXIT_SUCCESS);
}

void
print_array(char array[][3]) {
	int i;
	printf("%p\n", array[0]);
	for(i=0; i<2; i++) {
		/*printf("array[%d][] = '%s'\n", i, (char *)array[i][j]);*/
		printf("array[%d] = %s\n", i, array[i]);
	}
	strcpy((array)[0], "ef");
}
