#include <stdio.h>

/*
 * Write a function expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
 * and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
 * leading or trailing - is taken literally.
 */

#define MAXLINE 1000

int getline(char line[], int maxline);
void expand(char shortened[], char expanded[]);

int main() {
	
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char expanded[MAXLINE*5]; /* longest line saved here */
    while ((len = getline(line, MAXLINE)) > 0) {
		expand(line, expanded);
        printf("Got [%s] [%s]\n", line, expanded);
    }

	return 0;
}

void expand(char shorthand[], char expanded[]) {
	
	int srcPonter = 0;
	int dstPointer = 0;

	// Take leading '-' literally
	if (shorthand[srcPonter] == '-') {
		expanded[dstPointer++] = '-';
		srcPonter++;
	}

	// Find next '-' and use chars around it to find range.
	while(shorthand[srcPonter] != '\0') {
		if (shorthand[srcPonter] == '-' && (shorthand[srcPonter+1] == '\0' || shorthand[srcPonter+1] == '\n')) {
			expanded[dstPointer++] = '-';
			break;
		}

		if (shorthand[srcPonter] != '-') {
			srcPonter++;
			continue;
		}

		char prevChar, nextChar;
		prevChar = shorthand[srcPonter - 1];
		nextChar = shorthand[srcPonter + 1];

		if ((int) prevChar < (int) nextChar) {
			expanded[dstPointer++] = (char) prevChar++;
			while (prevChar < nextChar) {
				expanded[dstPointer++] = (char) prevChar++;
			}
			expanded[dstPointer++] = (char) nextChar;
		} else if ((int) prevChar > (int) nextChar) {
			expanded[dstPointer++] = (char) prevChar--;
			while (nextChar < prevChar) {
				expanded[dstPointer++] = (char) prevChar--;
			}
			expanded[dstPointer++] = (char) nextChar;
		} else {
			/* prevChar == nextChar */
			expanded[dstPointer++] = nextChar;
		}

		srcPonter++;
	}

	expanded[dstPointer++] = '\0';
	
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

