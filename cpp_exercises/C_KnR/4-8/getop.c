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

	if (isalpha(c) && c == 's') {
		if (isalpha(c = getch()) && c == 'i') {
			if (isalpha(c = getch()) && c == 'n') {
				return SIN;
			} else {
				ungetch(c);
				ungetch('i');
				c = 's';
			}
		} else {
			ungetch(c);
			c = 's';
		}
	}

	if (isalpha(c) && c == 'e') {
		if (isalpha(c = getch()) && c == 'x') {
			if (isalpha(c = getch()) && c == 'p') {
				return EXP;
			} else {
				ungetch(c);
				ungetch('x');
				c = 'e';
			}
		} else {
			ungetch(c);
			c = 'e';
		}
	}

	if (isalpha(c) && c == 'p') {
		if (isalpha(c = getch()) && c == 'o') {
			if (isalpha(c = getch()) && c == 'w') {
				return POW;
			} else {
				ungetch(c);
				ungetch('o');
				c = 'p';
			}
		} else {
			ungetch(c);
			c = 'p';
		}
	}

	if (c == '_') {
		return LAST;
	}

	if (isalpha(c) && c >= 'a' && c <= 'z') {
		s[0] = c;
		return GET_VAR;
	}

	if (c == '=') {
		if (isalpha(c = getch()) && c >= 'a' && c <= 'z' ) {
			s[0] = c;
			return SET_VAR;
		} else {
			ungetch(c);
			c = '=';
		}
	}

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
