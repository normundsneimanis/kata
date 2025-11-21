#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void reverse(char line[], int maxlen);


/* print the longest input line */
int main()
{
	int len; /* current line length */
	char line[MAXLINE]; /* current input line */
	while ((len = getline(line, MAXLINE)) > 0) {
		reverse(line, len);
	}
	return 0;
}

void reverse(char line[], int maxlen) {
	char modifiedLine[maxlen];

	int i;
	int j = 0;
	for (i = maxlen + 1; i >= 0; i--) {
		if (line[i] != '\0') {
			printf("Handling [%c]\n", line[i]);
			if (line[i] == '\t')
				modifiedLine[j] = ' ';
			else if (line[i] == '\n')
				modifiedLine[j] = ' ';
			else
				modifiedLine[j] = line[i];
			j++;
		}
	}

		j++;
	modifiedLine[j] = '\0';
	printf("[%s]%d %d\n", modifiedLine, i, j);
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
