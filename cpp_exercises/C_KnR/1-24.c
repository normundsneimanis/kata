#include <stdio.h>

// Remove comments from C source file

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void aggregate(char line[], int maxlen);
int currentLine = -1;

char commentCharsToFind[2][2] = {{'/', '*'}, {'*', '/'}};
int inComment = 0;
char oneLineComment[2] = {'/', '/'};
char startChars[3] = {'{', '(', '['};
char endChars[3] = {'}', ')', ']'};
int entered[3] = {0, 0, 0};
int exited[3] = {0, 0, 0};


/* print the longest input line */
int main()
{
	int len; /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = getline(line, MAXLINE)) > 0) {
		aggregate(line, MAXLINE);
	}

	int j;
	for (j = 0; j <= 2; j++) {
		if (entered[j] - exited[j] != 0)
			printf("Parentheses %c %c\n", startChars[j], endChars[j]);
	}

	if (inComment)
		printf("Comment not ended\n");

	return 0;
}

void aggregate(char line[], int maxlen) {
	currentLine++;

	int i = 0;
	int j;


	for (; i <= maxlen; i++) {
		if (line[i] == '\0' || 
			(line[i] == oneLineComment[0] && line[i+1] == oneLineComment[1])) {
			break;
		}

        if (!inComment) {
            if (line[i] == commentCharsToFind[0][0] && line[i+1] == commentCharsToFind[0][1]) {
                inComment = 1;
				continue;
			}

			for (j = 0; j <= 2; j++) {
				if (line[i] == startChars[j])
					entered[j]++;

				if (line[i] == endChars[j])
					exited[j]++;
			}
        } else {
            if (line[i-2] == commentCharsToFind[1][0] && line[i-1] == commentCharsToFind[1][1]) {
                inComment = 0;
            }
        }

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
