#include <stdio.h>

/* Write a function escape(s,t) that converts characters like newline and tab into
 * visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
 * function for the other direction as well, converting escape sequences
 */

#define MAXLINE 1000

int getline(char s[],int lim);
void escape(char s[], char t[]);
void reverseEscape(char s[], char t[]);

int main() {

    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getline(line, MAXLINE)) > 0) {
		char converted[MAXLINE];
		reverseEscape(line, converted);
        printf("Got [%s]. Converted [%s]\n", line, converted);
    }

	return 0;
}

void reverseEscape(char s[], char t[]) {
	int srcIterator = 0;
	int dstIterator = 0;
	int sawBackslash = 0;
	while (s[srcIterator] != '\0') {
		switch(s[srcIterator]) {
			case '\\':
				sawBackslash = 1;
				break;
			case 'n':
				if (sawBackslash) {
					t[dstIterator++] = '\n';
					sawBackslash = 0;
				}
				break;
			case 't':
				if (sawBackslash) {
					t[dstIterator++] = '\t';
					sawBackslash = 0;
				}
				break;
			default:
				if (sawBackslash) {
					t[dstIterator++] = '\\';
				}
				t[dstIterator++] = s[srcIterator];
				sawBackslash = 0;
		}
		srcIterator++;
	}
	
	t[dstIterator++] = '\0';
}

void escape(char s[], char t[]) {
	
	int srcIterator = 0;
	int dstIterator = 0;
	while (s[srcIterator] != '\0') {
		switch(s[srcIterator]) {
			case '\t':
				t[dstIterator++] = '\\';
				t[dstIterator++] = 't';
			case '\n':
				t[dstIterator++] = '\\';
				t[dstIterator++] = 'n';
			default:
				t[dstIterator++] = s[srcIterator];
		}
		srcIterator++;
	}

	t[dstIterator++] = '\0';
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

