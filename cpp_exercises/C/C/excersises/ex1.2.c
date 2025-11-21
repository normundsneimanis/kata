#include <stdio.h>
#include <stdlib.h>

#define INPUTCOUNT 3

int input[INPUTCOUNT], intimes, skaitlis, inputformat; 
intimes = 0;
int three(void);

main() {
	skaitlis = three();
	printf("skaitlis: %d\n", skaitlis);
}

int three(void) {
	while(intimes < 3) {
		input[intimes] = getchar();
		input[intimes] = input[intimes] - 48;
		intimes = intimes + 1;
	}
	intimes = 0;
	printf("input is: [%d] [%d] [%d]\n", input[0], input[1], input[2]);
	inputformat = 0;
	inputformat = (input[0] * 100);
	inputformat = (inputformat + (input[1] * 10));
	inputformat = (inputformat + input[2]);
	printf("inputformat: %d\n", inputformat);
	return inputformat;
}
