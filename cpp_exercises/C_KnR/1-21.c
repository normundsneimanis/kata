#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void aggregate(char line[], int maxlen);
int currentLine = 0;

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
	char modifiedLine[maxlen+1];

	//printf("Aggregating line [%s]\n", line);

	// while char is tab, convert it to TABSTOP spaces. Stop converting as soon
	// as enything other ecounters.
	// if first char is space, don't convert it.

	int i = 0;
	int j = 0; // Destination iterator
	int k = 0; // Internal iterator 
	while (line[i] == ' ') {
		if (k == 3) {
			modifiedLine[j] = '\t';
			j++;
			k = 0;
		} else {
			k++;
		}
		i++;
	}

	// Notify user if there is no 4 spaces
	if (k != 0) {
		fprintf(stderr, "Error, spaces count is not 4 in line %d\n", currentLine);
	} 
	currentLine++;

	for (; i < maxlen - 1; i++) {
		if (line[i] != '\0') {
			modifiedLine[j] = line[i];
		} else {
			modifiedLine[j] = '\0';
			break;
		}
		j++;
	}

	printf("%s", modifiedLine);
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
