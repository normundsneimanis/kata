#include <stdio.h>
#include <stdlib.h>

/* Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 */

int setbit(unsigned x, int bit, int val);
void printBits(size_t const size, void const * const ptr);
int getbit(unsigned x, int bit);
unsigned invert(unsigned x, int p, int n);

int main() {
	unsigned x = invert(240, 24, 4);
	printBits(sizeof(x), &x);

	x = invert(4279238415u, 28, 4);
	printBits(sizeof(x), &x);

	x = invert(85u, 8, 8);
	printBits(sizeof(x), &x);

	return 0;
}

unsigned invert(unsigned x, int p, int n) {
	int stop = p - n;
	if (stop < 0) {
		stop = 0;
	}

	while(p > stop) {
		x = setbit(x, p, !getbit(x, p));
		p--;
	}

	return x;
}

unsigned setbits(unsigned x, int p, int n, int y) {

	int stop = p - n;
	while(p > stop) {
		if (getbit(x, p) != getbit(x, y)) {
			x = setbit(x, p, getbit(x, y));
		}
		p--;
		y--;
	}

	return x;
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

// Returns bit value from right side.
int getbit(unsigned x, int bit) {
	bit -= 1;
	unsigned mask = (1 << bit);
	return x & mask;
}

// Sets bit value to given one. Couting starts from right side. Little-endian :)
int setbit(unsigned x, int bit, int val) {
	bit -= 1;
	unsigned mask = (1 << bit);
	if (val)
		return x | mask;
	else
		return x ^ mask;
}
