#include <stdio.h>
#include <stdlib.h>

int main(void) {
	long long int Mb = 0;
	while (malloc(1<<20))
		++Mb;
	printf("Allocated %d Mb total\n", Mb);

	return EXIT_SUCCESS;
}
