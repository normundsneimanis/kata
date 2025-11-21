#include <stdio.h>

int main() {
	int gotChar, prevChar;
	prevChar = EOF;

	while ((gotChar = getchar()) != EOF) {
		if (gotChar == ' ') {
			if (prevChar != ' ') {
				putchar(gotChar);
			}
		} else {
			putchar(gotChar);
		}
		
		prevChar = gotChar;
	}

	return 0;
}
