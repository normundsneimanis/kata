#include <stdio.h>
#include <stdlib.h>

int lower(int c);
int lower_old(int c);

int main() {
	printf("%c %c\n", lower('A'), lower_old('A'));

	return 0;
}


/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	return (c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c);
}


/* lower: convert c to lower case; ASCII only */
int lower_old(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
