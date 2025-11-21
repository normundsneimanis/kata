/*
 * Write versions of the library functions strncpy, strncat, and strncmp, which
 * operate on at most the first n characters of their argument strings. For 
 * example, strncpy(s,t,n) copies at most n characters of t to s. Full 
 * descriptions are in Appendix B.
 */

#include <stdio.h>
#include <string.h>

#define STR_MAX_LEN 100

void strncpy_(char *source, char *dest, int len);
void strncat_(char *s, char *t, int len);
int strncmp_(char *str1, char *str2, int len);
void test_strncpy(char *input, char *expected, int len); 

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Insufficient amount of arguments\n");
		return 0;
	}

	char str1[STR_MAX_LEN], str2[STR_MAX_LEN], str3[STR_MAX_LEN];
	str3[0] = 0;

	strncpy_(str1, argv[1], sizeof(str1));
	strncpy_(str2, argv[2], sizeof(str2));

	strncat_(str3, str2, 5);

	printf("%i\n", strncmp_("asd", "asdfg", 3));
	printf("%i\n", strncmp_("asd", "asafg", 3));
	printf("%i\n", strncmp_("asd", "asffg", 3));

	printf("Arguments: [%s], [%s]\n", str1, str2);
	
	test_strncpy("abcdef", "abc", 3);
	test_strncpy("ab", "ab", 3);
	test_strncpy("abc", "abc", 3);

	return 0;
}

void test_strncpy(char *input, char *expected, int len) {
	char testString[STR_MAX_LEN];
	strncpy_(testString, input, len);
	if (!strncmp(testString, expected, len)) {
		printf("ok [%s] %i\n", expected, len);
	} else {
		char correct[STR_MAX_LEN];
		strncpy(correct, expected, len);
		printf("nok [%s] [%s] correct: [%s]\n", testString, expected, correct);
	}
}


/* Copy source in dest, maximum len chars
 * If \0 is reached before len, \0 is copied
 * otherwise string gets truncated and \0 added to last char */
void strncpy_(char *dest, char *source, int len) {
	while ((len-- > 0) && (*dest++ = *source++))
		;

	while (len-- > 0) {
		*dest++ = '\0';
	}
}

/* The strncat() function appends not more than count characters from
 * append, and then adds a terminating \0 */
void strncat_(char *s, char *t, int len) {
    while (*s != '\0')
        s++;

    while ((len > 0) && (*s++ = *t++)) /* make compiler happy */
		len--;

	if (!len) {
		*s = '\0';
	}
}


int strncmp_(char *str1, char *str2, int len) {
	while ((len > 0) && (*str1++ == *str2++))
		len--;

	if (!len) {
		return 0;
	} else {
		str1--;
		str2--;
		if (*str1 > *str2) {
			return 1;
		} else if (*str1 < *str2) {
			return -1;
		}
	}
}
