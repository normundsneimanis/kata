#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char multi[5][10];

multi[0] = strdup('akaka');
/*multi[1] = {'a','b','c','d','e','f','g','h','i','j'};
multi[2] = {'A','B','C','D','E','F','G','H','I','J'};
multi[3] = {'9','8','7','6','5','4','3','2','1','0'};
multi[4] = {'J','I','H','G','F','E','D','C','B','A'};
*/

void func(char *array);


int main() {
	func(&multi);
	exit(EXIT_SUCCESS);
}

void func(char *array) {
	int i, j;
	for(i=0; i < 5; i++) {
		printf("array[%d] = %s\n", array[i]);
	}
}
