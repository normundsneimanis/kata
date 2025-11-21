#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(const char *arr[]);

main() {
	char *array[2] = {"ab", "cd"};
	printf("names = %s, %s\n",array[0],array[1]);
	print_array(*array);
	exit(EXIT_SUCCESS);
}

void print_array(const char *arr[]) {
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
}
