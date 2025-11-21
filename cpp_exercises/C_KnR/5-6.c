/* Rewrite appropriate programs from earlier chapters and exercises with pointers
 * instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
 * and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
 * (Chapter 4).
 */

#include <stdio.h>

#define MAXLINE 100

int getline(char *s, int lim);

int main(void) {
	char line[MAXLINE];
	while (getline(line, MAXLINE) > 0)
		printf("%s", line);
	
	return 0;
}


/* getline: get line into s, return length */
int getline(char *s, int lim)
{
	int initial_len = lim;

	while (--lim > 0 && (*s = getchar()) != EOF && *s != '\n')
		s++;

	if (*s == EOF) {
		return 0;
	}
	s++;
	*s = '\0';

	return initial_len - lim;
}

/* getline: get line into s, return length */
int getline_orig(char s[], int lim)
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
