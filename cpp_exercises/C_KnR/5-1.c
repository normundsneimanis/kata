/*
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the input.
 */

#include <stdio.h>
#include <ctype.h>

#define MAX_STR_LEN 100

int getch(void);
void ungetch(int);
int getint(int *);


int main(void) {
	int array[MAX_STR_LEN];
	//int n;
	//for (n = 0; n < MAX_STR_LEN && getint(&array[n]) != EOF; n++)
	//	;

	getint(&array[0]);

	printf("%i\n", array[0]);

	return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign, nextchar;
	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') {
		nextchar = getch();
		if (!isdigit(nextchar)) {
			ungetch(nextchar);
			ungetch(c);
		} else {
			c = nextchar;
		}
	}

	*pn = 0;

	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
	}

	*pn *= sign;

	if (c != EOF && c != '\n')
		ungetch(c);

	return c;
}
