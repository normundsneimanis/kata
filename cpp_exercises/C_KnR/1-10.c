#include <stdio.h>

int main() {
	int gotChar, prevChar;
	prevChar = EOF;

	while ((gotChar = getchar()) != EOF) {
		if (gotChar == '\t') {
			putchar('\\');
			putchar('t');
		} else if (gotChar == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(gotChar);
		}
		
		prevChar = gotChar;
	}

	return 0;
}
