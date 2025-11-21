#include <stdio.h>
#include <string.h>

// http://users.powernet.co.uk/eton/kandr2/krx2.html

int atoi(char string[]);

int main() {
	printf("%d", atoi("0xF"));

	return 0;
}

int atoi(char string[]) {

	int total = 1;

	if (string[0] == '0' && (string[1] == 'X' || string[1] == 'x')) {
		int i = 2;
		for (; i < strlen(string); i++)
			total *= (unsigned int) (string[i]);

	} else if (string[0] == 0) {
		int i = 1;
		for (; i < strlen(string); i++)
			total *= (int) string[i];
	}

	return total;
}
