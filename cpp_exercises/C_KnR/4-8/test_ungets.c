#include <stdio.h>

void ungets(char string[]);
int getch(void);

int main(void) {
	char string[] = "sin";

	ungets(string);
	
	char gotChar;
	while((gotChar = getch()) != EOF) {
		printf("%c", gotChar);
	}

	printf("\n");
	
	return 0;
}
