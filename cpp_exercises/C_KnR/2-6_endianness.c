#include <stdio.h>
#include <stdlib.h>

#include <sys/limits.h>
#include <string.h>

void printBits(size_t const size, void const * const ptr);


int main()
{
	int x = 1;
	
	char *y = (char*) &x;

	printf("%c\n",*y+48);
	printf("1 = little endian. 0 = big endian\n");

	{
        int i = 23;
        unsigned int ui = UINT_MAX;
        float f = 1.2f;
		printf("int %d\n", i);
        printBits(sizeof(i), &i);
		printf("unsigned int %u\n", ui);
        printBits(sizeof(ui), &ui);
		// How float is represented in memory
		// http://stackoverflow.com/questions/6910115/how-to-represent-float-number-in-memory-in-c
		printf("float %f\n", f);
        printBits(sizeof(f), &f);
	}

	return 0;
}

//assumes little endian
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


const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}
