#include <stdio.h>
#include <ctype.h>
#include "4_3_signals.h"

#define MAXLINE 1000 /* Maximum input line lenght */

int getch(void);
int strindex(char source[], char search[]);
void getline(char string[]);
void ungets(char string[]);

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	int sourcePtr = 0;
	char sourceLine[MAXLINE];

	getline(sourceLine);

	while ((s[0] = c = sourceLine[sourcePtr++]) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (strindex(sourceLine, "sin") == 0) {
		ungets(&sourceLine[3]);
		return SIN;
	}

	if (strindex(sourceLine, "exp") == 0) {
		ungets(&sourceLine[3]);
		return EXP;
	}

	if (strindex(sourceLine, "pow") == 0) {
		ungets(&sourceLine[3]);
		return POW;
	}

	if (c == '_') {
		ungets(&sourceLine[sourcePtr]);
		return LAST;
	}

	if (isalpha(c) && c >= 'a' && c <= 'z') {
		s[0] = c;
		ungets(&sourceLine[sourcePtr]);
		return GET_VAR;
	}

	if (c == '=') {
		if (isalpha(c = sourceLine[sourcePtr++]) && c >= 'a' && c <= 'z' ) {
			s[0] = c;
			ungets(&sourceLine[sourcePtr]);
			return SET_VAR;
		} else {
			ungets(&sourceLine[--sourcePtr]);
			c = '=';
		}
	}

	if (!isdigit(c) && c != '.') {
		ungets(&sourceLine[sourcePtr]);
		return c; /* not a number */
	}
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = sourceLine[sourcePtr++]))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = sourceLine[sourcePtr++]))
			;
	s[i] = '\0';
	if (c != EOF)
		ungets(&sourceLine[sourcePtr]);
	
	return NUMBER;
}


/*
 * Push back line to input buffer starting from startPtr.
 * used by getopt()
 */
void pushBackLine(char line[], int startPtr) {
	char modifiedStr[MAXLINE];
	int i = 0;
	while (line[startPtr] != '\0') {
		modifiedStr[i++] = line[startPtr++];
	}

	ungets(modifiedStr);
}


/* 
 * This version is taken from exercise 4-1, modified to 
 * return first occurrance
 */
int strindex(char source[], char search[]) {
    int srcPointer = 0;
    int searchPointer = 0;
    while (source[srcPointer] != '\0') {
        if (search[searchPointer] == source[srcPointer]) {
            searchPointer++;
            if (search[searchPointer] == '\0') {
                return srcPointer - searchPointer;
            }
        } else {
            searchPointer = 0;
        }
        srcPointer++;
    }

    return -1;
}

