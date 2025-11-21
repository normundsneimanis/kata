#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

#define MAX_WORD_LEN 15


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
				//printf("Incrementing array %d\n", thisWordLength);
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

	/*
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
	*/

	// Vertical histogram
	// First, understand height of our histogram
	int histogramHeight = 0;
	for (i = MAX_WORD_LEN -1; i > 0; i--) {
		//printf("Current lengths[%d]: %d\n", i, lengths[i]);
		if (histogramHeight < lengths[i]) {
			histogramHeight = lengths[i];
			//printf("Setting height to %d\n", lengths[i]);
		}
	}

	printf("Histogram Height will be %d\n", histogramHeight);

	// Get histogram boundaries (start and end length)
	int histogramStart= MAX_WORD_LEN;
	int histogramEnd = 0;

	for (i = 0; i < MAX_WORD_LEN; i++) {
		if (lengths[i]) {
			if (histogramStart < i)
				histogramStart = i;
			if (histogramEnd < i)
				histogramEnd = i;
		}
	}

	// Start drawing from shortest word.
	int j = MAX_WORD_LEN;
	for (i = histogramHeight; i > 0; i--) {
		for (j = 1; j < MAX_WORD_LEN; j++) {
			if (lengths[j] >= i) {
				printf("|  ");
			} else {
				printf("   ");
			}
		}
		putchar('\n');
	}

	for (i = 1; i < MAX_WORD_LEN; i++) {
		if (i < 10)
			printf("%d  ", i);
		else
			printf("%d ", i);
	}
	printf("\n");

	return 0;
}
