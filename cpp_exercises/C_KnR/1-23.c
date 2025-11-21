#include <stdio.h>

// Remove comments from C source file

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void aggregate(char line[], int maxlen);
int currentLine = -1;

int inComment = 0;
int inOneLineComment = 0;

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
	inOneLineComment = 0;

	/* 
	 * Find start of the comment (ignore further starts of the comments)
	 * Ignore the comment part from output.
	 */
	char outline[maxlen];

	int i = 0;
	int j = 0;
	char lastChar;
	lastChar = '\0';

	int wentOutOfComment = 0;

	for (; i <= maxlen; i++) {

		if (wentOutOfComment == 3)
			wentOutOfComment = 0;

		if (line[i] == '\0') {
			if (lastChar != '*') {
				outline[j] = lastChar;
				j++;
			} else {
				outline[j] = '\n';
			}
			outline[j] = '\0';
			break;
		}

		if (!inComment) {
			if (lastChar == '/' && line[i] == '/') {
				inOneLineComment = 1;
			} else if (lastChar == '/' && line[i] == '*') {
				inComment = 1;
			}
		} else {
			if (lastChar == '*' && line[i] == '/') {
				inComment = 0;
				wentOutOfComment = 1;
			}
		}
		
		if (wentOutOfComment != 0 && wentOutOfComment <= 2) {
			wentOutOfComment++;
			continue;
		}

		if (!inComment && !inOneLineComment) {
			if (lastChar != '\0') {
				outline[j] = lastChar;
				j++;
			}
		}

		if (inOneLineComment)
			break;

		lastChar = line[i];
	}

	if (j) {
		printf("%s", outline);
	} else if (!inComment) {
		printf("\n");
	}

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
