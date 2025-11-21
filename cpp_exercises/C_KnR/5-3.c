/*
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>

#define STR_MAX_SIZE 100

void strcat_old(char s[], char t[]);
void strcat_(char *s, char *t);

int main(void) {
	char str1[STR_MAX_SIZE] = "string1 ";
	char str2[STR_MAX_SIZE] = "Normunds";

	strcat_(str1, str2);

	printf("[%s]\n", str1);

	return 0;
}


void strcat_(char *s, char *t) {
	while (*s != '\0')
		s++;

	while ((*s++ = *t++)) /* make compiler happy */
		;
	
}


/* strcat: concatenate t to end of s; s must be big enough */
void strcat_old(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}
