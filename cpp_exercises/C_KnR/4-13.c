#include <stdio.h>
#include <string.h>
#include <sys/limits.h>

/*
 * 4-13
 * Write a recursive version of the function reverse(s), which reverses the
 * string s in place.
 */

#define STR_MAX 1000

int itoa(int n, char s[]);
void printBits(size_t const size, void const * const ptr);
void reverse(char s[]);
void reverseRec(char s[], int ch, int rep);


int main() {
	char string[STR_MAX] = "abcd";
	reverse(string);
	printf("reversed string: %s\n", string);

	char string2[STR_MAX] = "abcde";
	reverse(string2);
	printf("reversed string: %s\n", string2);

	return 0;
}


/* reverse: reverse string s in place */
void reverse(char s[])
{
	int len = strlen(s) - 1;

	reverseRec(s, 0, len);
}

void reverseRec(char s[], int ch, int rep) {

	int replaceChar = s[rep];
	s[rep] = s[ch];
	s[ch] = replaceChar;

	if (++ch < --rep)
		reverseRec(s, ch, rep);
}


/* reverse: reverse string s in place */
void reverse_orig(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
        printf(" ");
    }
    puts("");
}
