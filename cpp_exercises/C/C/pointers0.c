#include <stdio.h>
#include <stdlib.h>

void sum(const int *ptr);

int main() {
	int array[5] = {1,2,3,4,5};
	int *ptr;
	ptr = array;
	printf("passing address %p\n", ptr);
	sum(ptr);
	exit(EXIT_SUCCESS);
}

void sum(const int *ptr) {
	printf("Got address %p size: %d\n", ptr, (ptr));

}
