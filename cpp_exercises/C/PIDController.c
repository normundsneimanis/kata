#include <stdio.h>
#include <stdlib.h>

// ./a.out 5000 0.5 0.3 0.05

/*
 * PID Controller
 * Arguments:
 * 	Current error (delay from expected)
 *	Error coefficient
 *	Derivative coefficient
 *	Integral coefficient
 *	Initialization flag (1 upon initialization, false on further calls)
 */
float pidController(float currentError, float kP, float kD, float kI, int initFlag) {
	/* PID Controller implementation pseudo code
	 * read currentError
	 * errorNext = currentError - oldError
	 * errors = errors + currentError
	 * adjustment = kP * currentError + kD * errorNext + kI * errors
	 * oldError = currentError
	 */
	static float oldError;
	static float errorNext;
	static float totalErrors;

	if (initFlag) {
		oldError = 0;
		errorNext = 0;
		totalErrors = 0;
	}
	errorNext = currentError - oldError;
	totalErrors = totalErrors + currentError;
	oldError = currentError;
	return (float) (kP * currentError + kD * errorNext + kI * totalErrors);
}

int main(int argc, char ** argv) {
	float expectedSpeed;
	float actualSpeed = 500;
	float kP, kD, kI;
	float adjustment;

	if (argc != 5) {
		fprintf(stderr, "usage: %s <expectedSpeed> <kP> <kD> <kI>\n", argv[0]);
		exit(1);
	}
	expectedSpeed = (float) atoi(argv[1]);
	kP = (float) atof(argv[2]);
	kD = (float) atof(argv[3]);
	kI = (float) atof(argv[4]);

	pidController(0, 0, 0, 0, 1); // Initialize
	int iterations = 40;
	printf("Looping %d iterations with kP %.2f kD %.2f kI %.2f\n", iterations, kP, kD, kI);
	while (iterations > 0) {
		adjustment = pidController(expectedSpeed - actualSpeed, kP, kD, kI, 0);
		printf("Speed: %.2f \tAdjusment %.2f\n", actualSpeed, adjustment);
		actualSpeed += adjustment;
		iterations--;
	}
	return 0;
}
