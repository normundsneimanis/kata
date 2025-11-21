#include <stdio.h>
#include <ctype.h>
#include "4_3_signals.h"

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;

	static int ungetchBuffer[3];
	static int ungetchBufferPtr = 0;

	// Flag to know if ungetchBuffer was used
	int ungetchBufferUsed = 0;
	
	while(ungetchBufferPtr > 0) {
		ungetchBufferUsed = 1;
		if ((s[0] = c = ungetchBuffer[--ungetchBufferPtr]) == ' ' || c == '\t')
			;
	}

	if (s[0] == ' ' || (!ungetchBufferUsed))
		while ((s[0] = c = getch()) == ' ' || c == '\t')
			;

	s[1] = '\0';

	if (isalpha(c) && c == 's') {
		if (isalpha(c = getch()) && c == 'i') {
			if (isalpha(c = getch()) && c == 'n') {
				return SIN;
			} else {
				ungetchBuffer[ungetchBufferPtr++] = c;
				ungetchBuffer[ungetchBufferPtr++] = 'i';
				c = 's';
			}
		} else {
			ungetchBuffer[ungetchBufferPtr++] = c;
			c = 's';
		}
	}

	if (isalpha(c) && c == 'e') {
		if (isalpha(c = getch()) && c == 'x') {
			if (isalpha(c = getch()) && c == 'p') {
				return EXP;
			} else {
				ungetchBuffer[ungetchBufferPtr++] = c;
				ungetchBuffer[ungetchBufferPtr++] = 'x';
				c = 'e';
			}
		} else {
			ungetchBuffer[ungetchBufferPtr++] = c;
			c = 'e';
		}
	}

	if (isalpha(c) && c == 'p') {
		if (isalpha(c = getch()) && c == 'o') {
			if (isalpha(c = getch()) && c == 'w') {
				return POW;
			} else {
				ungetchBuffer[ungetchBufferPtr++] = c;
				ungetchBuffer[ungetchBufferPtr++] = 'o';
				c = 'p';
			}
		} else {
			ungetchBuffer[ungetchBufferPtr++] = c;
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
			ungetchBuffer[ungetchBufferPtr++] = c;
			c = '=';
		}
	}

	if (!isdigit(c) && c != '.') {
		printf("returning %c\n", c);
		return c; /* not a number */
	}
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetchBuffer[ungetchBufferPtr++] = c;
	
	return NUMBER;
}
