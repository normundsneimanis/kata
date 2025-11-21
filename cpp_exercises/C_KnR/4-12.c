#include <stdio.h>
#include <string.h>
#include <sys/limits.h>

/*
 * 4-12
 * Adapt the ideas of printd to write a recursive version of itoa; that is, convert
 * an integer into a string by calling a recursive routine.
 */

#define STR_MAX 1000

int itoa(int n, char s[]);
void reverse(char s[]);
void printBits(size_t const size, void const * const ptr);


int main() {
	char string[STR_MAX];
	int integer = INT_MIN;
	integer = -12345;
	printf("itoa integer: %i\n", integer);
	itoa(integer, string);

	printf("Strin %s\n", string);
	return 0;
}

/* itoa: convert n to characters in s recursively */
int itoa(int n, char s[])
{
	int sPointer = 0;
	int sign;
	if ((sign = n) < 0) { /* record sign */
		n = -n; /* make n positive */
	}
	
	if (n / 10) {
		sPointer = itoa(n / 10, s);
	}
	
	s[sPointer++] = n % 10 + '0';
	
	s[sPointer] = '\0';

	/* 
	 * Set sign at the beginning of the string,
	 * move all the string forward by one char
	 * then insert '-' in s[0]
	 */
	if (sign < 0) {
		int iter = 0;
		while (s[iter] != '\0')
			iter++;
		iter++;

		while (iter != -1) {
			s[iter+1] = s[iter];
			iter--;
		}
		s[0] = '-';
	}

	return sPointer;
}


/* itoa: convert n to characters in s */
void itoa_orig(int n, char s[])
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


/* printd: print n in decimal */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
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
