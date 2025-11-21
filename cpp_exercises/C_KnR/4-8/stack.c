#include <stdio.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
int backup_sp = 0;
double backup_val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL) {
		printf("stack: inserting %f\n", f);
		val[sp++] = f;
	} else
		printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0) {
		printf("stack: returning %f\n", val[sp - 1]);
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* print elem top elements without popping them */
void peek(int elem) {
	int internal_sp = sp;

	if (sp == 0) {
		printf("error: stack empty\n");
	}

	while (elem > 0 && internal_sp > 0) {
		printf("%i: %f\n", internal_sp, val[internal_sp]);
		internal_sp--;
		elem--;
	}
}

void backup(void) {
	int i;
	for (i = 0; i <= sp; i++) {
		backup_val[i] = val[i]; 
	}
	backup_sp = sp;
}

void restore(void) {
	int i;

	for (i = 0; i <= backup_sp; i++) {
		val[i] = backup_val[i];
	}
	sp = backup_sp;
}

/* Swap top two elements */
int swap(void) {
	if (sp > 1) {
		double backup;
		backup = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = backup;
		return 1;
	} else {
		printf("Error: not enaugh elements in stack to do swap\n");
		return 0;
	}
}

/* Empty stack */
void clear(void) {
	sp = 0;
}

