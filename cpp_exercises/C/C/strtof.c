#include <stdlib.h>
#include <stdio.h>

int main(void) {
	float result = 0;
	char first[] = "1.25";
	result = atof(first);
	printf("%f\n", result);
	return 0;
}
