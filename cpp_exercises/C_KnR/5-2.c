/*
 * 5-2
 * Write getfloat, the floating-point analog of getint. What type does getfloat
 * return as its function value?
 */

#include <stdio.h>
#include <ctype.h>

#define MAX_STR_LEN 100

int getch(void);
void ungetch(int);
int getint(float *);


int main(void) {
	float array[MAX_STR_LEN];
	//int n;
	//for (n = 0; n < MAX_STR_LEN && getint(&array[n]) != EOF; n++)
	//	;

	getint(&array[0]);

	printf("%f\n", array[0]);

	return 0;
}

/* getint: get next integer from input into *pn */
int getint(float *pn)
{
	int c, nextchar;
	float sign;
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

	if (isdigit(c)) /* collect integer part */
		for (;isdigit(c); c = getch())
			*pn = 10 * *pn + (c - '0');

	if (c == '.' || c == ',') { /* collect fraction part */
		c = getch();
		for (;isdigit(c); c = getch()) {
			*pn = 10 * *pn + (c - '0');
			sign /= 10;
		}
	}

	*pn *= sign;

	if (c != EOF && c != '\n')
		ungetch(c);

	return c;
}
