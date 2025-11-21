#include <stdio.h>
#include <stdlib.h>

/* Write a function rightrot(x,n) that returns the value of the integer x rotated
 * to the right by n positions.
 */

void printBits(size_t const size, void const * const ptr);
int bitcount(unsigned x);
int bitcount_old(unsigned x);

int main() {
	unsigned x = 255;
	printf("bc: %i bc_old: %i\n", bitcount(x), bitcount_old(x));
	printBits(sizeof(x), &x);
	while (x) {
		x &= (x-1);
		printBits(sizeof(x), &x);
		printf("x: %i\n", x);
	}

	return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int bitCount = 0;
	while (x) {
		x &= (x-1);
		bitCount++;
	}

	return bitCount;
}


/* bitcount: count 1 bits in x */
int bitcount_old(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
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
