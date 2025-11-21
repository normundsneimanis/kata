#include <stdlib.h>
#include <stdio.h>

/* Write the function any(s1,s2), which returns the first location in a string s1
 * where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
 * (The standard library function strpbrk does the same job but returns a pointer to the
 * location.)
 */

int any(char s1[], char s2[]);

int main() {
	char s1[] = "String1";
	char s2[] = "String2";
	int result = -1;

	if ((result = any(s1, s2)) == 0) {
		printf("pass\n");
	} else {
		printf("fail\n");
	}

	char s3[] = "asdasddsf 3e3sda21e";
	char s4[] = "z";
	if ((result = any(s3, s4)) == -1) {
		printf("pass\n");
	} else {
		printf("fail %d\n", result);
	}

	return 0;
}

/* Find any char of s2 in s1 */
int any(char s1[], char s2[]) {
	int j, i;
	j = -1;
	i = -1;

	while (s1[++i] != '\0') {
		while (s2[++j] != '\0') {
			if (s1[i] == s2[j]) {
				//printf("num %d eq %d char %c == %c. s2: %s\n", i,j, s1[i], s2[j], s2);
				return i;
			}
		}
		j=0;
	}

	return -1;
}
