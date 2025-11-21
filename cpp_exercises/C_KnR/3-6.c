#include <stdio.h>
#include <string.h>


void itoa(int n, char s[], int minSpaces);
void testItoa(int n, int minSpaces, char expectedResult[]);
void reverse(char s[]);

/*
 * Write a version of itoa that accepts three arguments instead of two. The third
 * argument is a minimum field width; the converted number must be padded with blanks on the
 * left if necessary to make it wide enough.
 */

int main() {
	
	testItoa(10, 5, "   10");

	return 0;
}

void testItoa(int n, int minSpaces, char expectedResult[]) {
	char s[100];
	itoa(n, s, minSpaces);

	if (strcmp(s, expectedResult) == 0) {
		printf("Ok [%s] %i min: %i\n", s, n, minSpaces);
	} else {
		printf("Fail [%s] %i min: %i expected [%s]\n", s, n, minSpaces, expectedResult);
	}

}


/* itoa: convert n to characters in s */
void itoa(int n, char s[], int minSpaces)
{
	int i, sign;
	if ((sign = n) < 0) /* record sign */
		n = -n; /* make n positive */
	i = 0;

	do { /* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	if (sign < 0)
		s[i++] = '-';

	while (i < minSpaces) {
		s[i++] = ' ';
	}

	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

