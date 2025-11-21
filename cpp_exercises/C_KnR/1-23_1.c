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

	char charsToFind[2][2] = {{'/', '*'}, {'*', '/'}};
	char oneLineComment[2] = {'/', '/'};

	for (; i <= maxlen; i++) {
		if (line[i] == '\0') {
			outline[j++] = line[i];
			break;
		}

		if (!inComment) {
			if (line[i] == charsToFind[0][0] && line[i+1] == charsToFind[0][1])
				inComment = 1;
			else if (line[i] == oneLineComment[0] && line[i+1] == oneLineComment[1])
				inOneLineComment = 1;

			if (!inComment && !inOneLineComment) {
				outline[j++] = line[i];
			}

		} else {
			if (line[i-2] == charsToFind[1][0] && line[i-1] == charsToFind[1][1]) {
				inComment = 0;
				outline[j++] = line[i];
			}
		}
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
