/*
 * Write the function strindex(s,t) which returns the position of the rightmost
 * occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
	char line[MAXLINE];
	int found = 0;
	int result = -2;
	while (getline(line, MAXLINE) > 0)
		if ((result = strindex(line, pattern)) >= 0) {
			printf("%i %s", result, line);
			found++;
		}
	return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex_orig(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

int strindex(char source[], char search[]) {
	int result = -1;

	int srcPointer = 0;
	int searchPointer = 0;
	while (source[srcPointer] != '\0') {
		if (search[searchPointer] == source[srcPointer]) {
			searchPointer++;
			if (search[searchPointer] == '\0') {
				result = srcPointer - searchPointer;
			}
		} else {
			searchPointer = 0;
		}
		srcPointer++;
	}

	return result;
}
