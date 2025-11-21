#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char string[]) { /* push entire string back on input */
	int i = 0;
	while (string[i] != '\0')
		i++;

	while(i >=0) {
		ungetch((int) string[i--]);
	}
}

void getline(char string[]) {
	int i = 0;

	int gotSome;
	while ((gotSome = getch()) != '\n' && gotSome != EOF) {
		string[i++] = gotSome;
	}
	string[i++] = '\n';
	string[i] = '\0';
}
