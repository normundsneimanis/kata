#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void putvalues(char *array);
void printvalues(const char *array);

int main() {
	char array[5][5];
	int *array_ptr = array;
	putvalues(array_ptr);
	printvalues(array_ptr);
}

void
putvalues(char *array) {
	strcpy(array, "0123");
}

void
printvalues(const char *array) {
	printf("%s\n",array);
}
