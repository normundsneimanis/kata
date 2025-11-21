#include <stdio.h>

void ungets(char string[]);
int getch(void);
void ungetch(int c);

int main(void) {
	char string[] = "sin";

	ungetch(EOF);
	ungets(string);
	
	char gotChar;
	while((gotChar = getch()) != EOF) {
		printf("%c", gotChar);
	}

	printf("\n");
	
	return 0;
}
