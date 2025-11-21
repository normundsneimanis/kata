#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aggregate_array(char *array);
void func(const char *array);

char string[] = "kakas kakas2";

int main() {
	char *str_ptr = string;
	func(str_ptr);
}

void
aggregate_array(char *array) {
	char string[80];
	char *i = string;
	while(*array) {
		*i++ = *array++;
	}
	*i = '\0';
	printf("%s\n", string);
}

void func(const char *array) {
	printf("%s\n", array);
}
