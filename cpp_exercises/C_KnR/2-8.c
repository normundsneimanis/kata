#include <stdio.h>
#include <stdlib.h>

/* Write a function rightrot(x,n) that returns the value of the integer x rotated
 * to the right by n positions.
 */

int setbit(unsigned x, int bit, int val);
void printBits(size_t const size, void const * const ptr);
int getbit(unsigned x, int bit);
unsigned rotateRight(unsigned x, int count);

int main() {
	unsigned x = rotateRight(4294902000u, 16);
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

unsigned rotateRight(unsigned x, int count) {
	while(count) {
		if (x & 1) {
			x >>= 1;
			x |= (1 << ((sizeof(x) * 8) - 1));
		} else {
			x >>= 1;
		}
		count--;
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
