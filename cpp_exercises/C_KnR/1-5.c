#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
	float fahr, celsius;
	float lower, upper, step;
	int headingPrinted = 0;
	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 5; /* step size */
	fahr = upper;
	while (fahr >= lower) {
		if (!headingPrinted) {
			printf("Farenheit Celsius\n----\n");
			headingPrinted = 1;
		}
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr - step;
	}

	return 0;
}
