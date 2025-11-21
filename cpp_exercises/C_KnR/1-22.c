#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define MAX_LINE_LEN 80 /* Maximum output line length */

int getline(char line[], int maxline);
void aggregate(char line[], int maxlen);
int lastSpaceBeforeMax(char line[], int startPointer, int maxLine, int *endReached);
void printLine(char line[], int startPointer, int endPointer);
int currentLine = -1;

/* print the longest input line */
int main()
{
	int len; /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = getline(line, MAXLINE)) > 0) {
		aggregate(line, MAXLINE);
	}
	return 0;
}

void aggregate(char line[], int maxlen) {
	currentLine++;

	/*
	 * Iterate source line and copy words who end with space that is before 
	 * MAX_LINE_LEN
	*/

	int i = 0; // Source array iterator
	int endReached = 0;
	int lastSpace = 0;

	// Find if there is space before MAX_LINE_LEN
	for (;;) {
		lastSpace = lastSpaceBeforeMax(line, i, lastSpace + MAX_LINE_LEN, &endReached);
		fprintf(stderr, "Line %d. Found lastSpace %d. EndReched %d i:%d\n", currentLine, lastSpace, endReached, i);
		if (lastSpace) {
			printLine(line, i, lastSpace);
			lastSpace++;
			i = lastSpace;
		} else {
			printLine(line, i, i + MAX_LINE_LEN);
			lastSpace = i;
			i += MAX_LINE_LEN;
		}

		if (endReached) {
			break;
		}
	}
}

int lastSpaceBeforeMax(char line[], int startPointer, int maxLine, int *endReached) {
	// check for spaces ONLY before \0, find \0 location
	int zLocation = -1;
	int z = startPointer;
	
	for (; z <= maxLine; z++) {
	 	if (line[z] == '\0') {
			zLocation = z;
			*endReached = 1;
		}
	}

	if (zLocation > 0) {
		maxLine = zLocation;
	}
	
	// Find space before max location
	while (maxLine >= startPointer) {
		if (line[maxLine] == ' ' || line[maxLine] == '\t') {
			return maxLine;
		}
		maxLine--;
	}

	return 0;
}

void printLine(char line[], int startPointer, int endPointer) {
	char newLine[endPointer - startPointer + 1];

	int i = 0;
	for (;startPointer <= endPointer; startPointer++) {
		newLine[i] = line[startPointer];
		i++;
	}
	newLine[i] = '\0';

	printf("%s\n", newLine);
}

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
