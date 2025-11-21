#include <stdio.h>
#include <string.h>
#include <sys/limits.h>

/*
 * In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not.
 * Modify it to print that value correctly, regardless of the machine on which it runs
 */

#define STR_MAX 1000

void itoa(int n, char s[]);
void reverse(char s[]);
void printBits(size_t const size, void const * const ptr);


int main() {
	char string[STR_MAX];
	int integer = INT_MIN;
	printf("itoa integer: %i\n", integer);
	itoa(integer, string);

	printf("Strin %s\n", string);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0) /* record sign */
		n = -n; /* make n positive */
	i = 0;
	
	// Handle INT_MIN case
	if (n == INT_MIN) {
		s[i++] = '8';
		(n /= 10);
		n = -n;
	}

	do { /* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
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
