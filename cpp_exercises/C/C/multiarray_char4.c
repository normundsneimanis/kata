
#include <stdio.h>
#include <string.h>

void stuff(char (*some_bunch_of_strings)[10], int j)
{
strcpy((some_bunch_of_strings)[j], "oh I see");
}

int main(void) {
	char a_string[10][10]; /* = {0}; */
	int i = 0;
	int j = 0;
	stuff(a_string, 1);
	
	printf("i=%i, j=%i, a_string=%s\n", i, j, a_string[1]);
	stuff(a_string, 2);
	printf("i=%i, j=%i, a_string=%s\n", i, j, a_string[2]);

	return 0;
}
