/*
 * 4-4
 * Add the commands to print the top elements of the stack without popping, to
 * duplicate it, and to swap the top two elements. Add a command to clear the 
 * stack.
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
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
