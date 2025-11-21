#include <stdio.h>
#include <stdlib.h>

/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
 * position p set to the rightmost n bits of y, leaving the other bits unchanged.
 */

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);
unsigned properGetbits(unsigned x, int p, int n);
int setbit(unsigned x, int bit, int val);
void printBits(size_t const size, void const * const ptr);
int getbit(unsigned x, int bit);

int main() {
	printf("%i\n", getbits(125, 4, 3));
	printf("%i (84)\n", properGetbits((unsigned) 4294967124u, 7, 5));

	printf("bit is %i\n", getbit(3, 1));

	unsigned x = setbits(240, 24, 4, 8);
	printBits(sizeof(x), &x);

	x = setbits(4279238415u, 28, 4, 8);
	printBits(sizeof(x), &x);


	return 0;
}


unsigned setbits(unsigned x, int p, int n, int y) {

	int stop = p - n;
	if (stop < 0) {
		stop = 0;
	}

	while(p > stop) {
		if (getbit(x, p) != getbit(x, y)) {
			x = setbit(x, p, getbit(x, y));
		}
		p--;
		y--;
	}

	return x;
}

/* getbits: get n bits from position p */
/* Example getbits(125,4,3)
 *  will return 11111111
 *  from & to |: |  ^  
 *  11111111 >> 2
 *  00111111 & ~(11111111 << 3)
 *  00111111 & ~(11111000)
 *  00111111 & 00000111
 *  00000111
 *
 * getbits(10,4,3)
 *  0000 1010 >> 2
 *  0000 0010 & 00000111
 *  0000 0010
 *
 * getbits(84, 4, 5));
 *  0101 0100 >> 0
 *  0101 0100 & 1110 0000
 *  0001 0100
 *
 * getbits(84, 7, 5))
 * 0101 0100 >> 3
 * 0000 1010 & 0001 1111
 * 0000 1010
 */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

// 1 - input integer
// 2 - start byte from beginning.
// 3 - byte count from start byte.
// (1111 1111 1111 1111, 12, 5) will return
//  0000 1111 1000 0000
// int is
// 0000 0000 0000 0000 0000 0000 0000 0000
//   byte1     byte2     byte3     byte4
unsigned properGetbits(unsigned x, int p, int n) {
	unsigned tmp = x;
	printf("Received: \n");
	printBits(sizeof(tmp), &tmp);
	int maxBit = sizeof(x) * 8;
	tmp <<= (maxBit - p); // remove heading bits
	printf("shifted to left: \n");
	printBits(sizeof(tmp), &tmp);
	tmp >>= (maxBit - n); // remove trailing bits
	printf("shifted to right: \n");
	printBits(sizeof(tmp), &tmp);
	tmp <<= p - n;
	printf("reverted back: \n");
	printBits(sizeof(tmp), &tmp);
	return tmp;
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
