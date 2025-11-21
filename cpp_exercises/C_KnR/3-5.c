#include <stdio.h>
#include <string.h>

/* 
 * Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16) formats s as a
 * hexadecimal integer in s.
 */

void itob(int n, char s[] , int b);
void reverse(char s[]);
void testItob(int n, int b, char result[]);

char chars[] = "0123456789abcdefghijklmnoprstuvxyz";

int main() {
	testItob(80, 16, "50");
	testItob(15, 16, "f");
	testItob(15, 8, "17");
	testItob(0, 16, "0");

	return 0;
}

void testItob(int n, int b, char result[]) {
	char s[100];
	itob(n, s, b);
	if (strcmp(s, result) == 0) {
		printf("Ok decimal %i in base %i = %s\n", n, b, s);
	} else {
		printf("Fail decimal %i in base %i = %s (!= %s)\n", n, b, s, result);
	}

}

void itob(int n, char s[] , int b) {
	int dstPointer = 0;
	do {
		s[dstPointer++] = (char) chars[n % b];
	} while ((n /= b) > 0);

	s[dstPointer] = '\0';

	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
