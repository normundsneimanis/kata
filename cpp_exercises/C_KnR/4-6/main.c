/*
 * 4-6
 * Add commands for handling variables. (It's easy to provide twenty-six variables
 * with single-letter names.) Add a variable for the most recently printed value.
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include "4_3_signals.h"
#include "stack.h"

#define MAXOP 100 /* max size of operand or operator */
#define MAXVARS 26
#define LETTER_A_CHAR_IDX 97

double vars[MAXVARS];

/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	double lastPrinted = -1.0f;
	char var;
	
	printf("_ - most recently used result variable\n");
	printf("=a - save value in variable a. [a-z]\n");

	/* Clean up saved vars database */
	int i;
	for (i = 0; i < 26; i++)
		vars[i] = -1.0f;

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
		case LAST:
			if ((int) lastPrinted == -1) {
				printf("main: no last printed value\n");
			} else {
				push(lastPrinted);
			}
			break;
		case SET_VAR:
			var = s[0];
			op2 = pop();
			vars[(int) var - LETTER_A_CHAR_IDX] = op2;
			printf("Saving %f in %c\n", op2, var);
			break;
		case GET_VAR:
			var = s[0];
			if ((int) vars[(int) var - LETTER_A_CHAR_IDX] != -1) {
				push(vars[(int) var - LETTER_A_CHAR_IDX]);
			} else {
				printf("Error: variable %c not defined! Using 0\n", var);
				push(0);
			}
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
			op2 = pop();
			printf("\t%.8g\n", op2);
			lastPrinted = op2;
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}

	return 0;
}
