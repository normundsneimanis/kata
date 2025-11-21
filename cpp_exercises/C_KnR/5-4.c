/*
 * Write the function strend(s,t), which returns 1 if the string t occurs at the
 * end of the string s, and zero otherwise.
 */

#include <stdio.h>

#define CHAR_MAX_LEN 100

int strend(char *s, char *t);

int main(void) {
	char str1[CHAR_MAX_LEN] = "Normunds";
	char str2[CHAR_MAX_LEN] = "unds";

	printf("%i\n", strend(str1, str2));
	
	return 0;
}


int strend(char *s, char *t) {
	/* go to the end of s */
	while (*s != '\0')
		s++;

	/* go to the end of t, keep count of t length */
	int tLength = 1; /* we're starting with \0, hence 1 */
	while (*t != '\0') {
		tLength++;
		t++;
	}

	/* compare chars while we have some in t */
	while ((tLength) && (*s-- == *t--)) {
		tLength--;
	}

	if (!tLength) {
		return 1;
	} else {
		return 0;
	}
}
