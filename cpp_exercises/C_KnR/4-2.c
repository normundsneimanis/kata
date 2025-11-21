/*
 * Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally 
 * signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

int getline(char s[], int lim);
double atof(char s[]);
double atof_orig(char s[]);

int main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("Argument not given. 123.45e-6\n");
		return 1;
	}

	printf("Result: %f argument: %s\n", atof(argv[1]), argv[1]);

	return 0;
}


/* atof: convert string s to double */
/* handle 123.45e-6 */
double atof(char s[])
{
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (tolower(s[i]) == 'e') {
		int j;
		if (s[++i] == '-') {
			i++;
			for (; isdigit(s[i]); i++) {
				for (j = 0; j < (s[i] - '0'); j++)
					power *= 10;
			}
		} else {
			for (; isdigit(s[i]); i++)
				for (j = 0; j < (s[i] - '0'); j++)
					power /= 10;
		}
	}

	printf("Returning %f (%i * %f / %f)\n", sign * val / power, sign, val, power);
	return sign * val / power;
}


/* atof: convert string s to double */
double atof_orig(char s[])
{
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}


/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

