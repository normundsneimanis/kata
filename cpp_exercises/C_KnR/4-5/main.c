/*
 * 4-5
 * Add access to library functions like sin, exp, and pow. See <math.h> in
 * Appendix B, Section 4.
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include "4_3_signals.h"
#include "stack.h"

#define MAXOP 100 /* max size of operand or operator */

/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case SIN:
			push(sin(pop()));
			break;
		case EXP:
			push(exp(pop()));
			break;
		case POW:
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '%':
			op2 = pop();
			push((int) pop() % (int) op2);
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}

	return 0;
}
