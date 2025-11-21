#include <stdio.h>
#include <ctype.h>
#include "4_3_signals.h"

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (isalpha(c) && c == 's')
		return SIN;

	if (isalpha(c) && c == 'e')
		return EXP;

	if (isalpha(c) && c == 'p')
		return POW;

	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
}
