#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

#define MAX_WORD_LEN 256


int main() {
	char lengths[MAX_WORD_LEN];

	// Fill lengths array with zeros
	int i;
	for (i = 0; i < MAX_WORD_LEN; i++) {
		lengths[i] = 0;
	}

	int state = OUT;
	int prevState = OUT;

	int inputChar;

	int thisWordLength = 0;

	while ((inputChar = getchar()) != EOF) {

        if (inputChar == ' ' || inputChar == '\n' || inputChar == '\t') {
            state = OUT;
			if (prevState == IN && thisWordLength < MAX_WORD_LEN && thisWordLength > 0) {
				printf("Incrementing array %d\n", thisWordLength);
				lengths[thisWordLength]++;
			}
			thisWordLength = 0;
        } else if (state == OUT) {
			if (prevState == OUT)
				prevState = IN;
			thisWordLength++;
            state = IN;
        } else {
			thisWordLength++;
		}
	}

	for (i = MAX_WORD_LEN; i > 0; i--) {
		if (lengths[i]) {
			printf("%d: ", i);
			int j;
			for (j = 0; j < lengths[i]; j++) {
				putchar('-');
			}
			putchar('\n');
		}
	}

	return 0;
}
