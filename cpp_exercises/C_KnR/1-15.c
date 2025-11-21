#include <stdio.h>

/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */

float farenheitToCelsius(float farenheit);

int main()
{
	float fahr, celsius;
	float lower, upper, step;
	int headingPrinted = 0;
	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	fahr = lower;
	while (fahr <= upper) {
		if (!headingPrinted) {
			printf("Farenheit Celsius\n----\n");
			headingPrinted = 1;
		}
		celsius = farenheitToCelsius(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}

float farenheitToCelsius(float farenheit) {
	farenheit -= 32.0;
	return ((5.0/9.0) * (farenheit-32.0));
}
