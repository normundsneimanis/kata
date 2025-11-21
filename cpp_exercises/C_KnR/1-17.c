#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */
#define MIN_LINE_TO_SAVE 80

int getline(char line[], int maxline);
void copy(char from[], char to[]);


/* print the longest input line */
int main()
{
	int len; /* current line length */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE][MAXLINE]; /* longest line saved here */
	int currentLongest = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		printf("Length: %d, line: %s\n", len, line);
		if (len > MIN_LINE_TO_SAVE) {
			copy(line, longest[currentLongest]);
			currentLongest++;
		}
		if (currentLongest > MAXLINE) {
			break;
		}
	}
	int i;
	for (i = 0; i <= currentLongest; i++) {
		printf("Longest: %d: %s", strlen(longest[i]), longest[i]);
	}
	return 0;
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


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char from[], char to[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
