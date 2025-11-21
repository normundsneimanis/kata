#include <stdio.h>
#include <sys/limits.h>
#include <float.h>

/*
 * Print minimum and maximum number of types
 */

int main() {
	printf("char size: %d, min %d, max %d, max unsigned %d\n", sizeof(char), SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
	printf("short size: %d, min %d, max %d, max unsigned %d\n", sizeof(short), SHRT_MIN, SHRT_MAX, USHRT_MAX);
	printf("int size: %d, min %d, max %d, max unsigned %u\n", sizeof(int), INT_MIN, INT_MAX, UINT_MAX);
	printf("long size: %d, min %ld, max %ld, max unsigned %lu\n", sizeof(long), LONG_MIN, LONG_MAX, ULONG_MAX);
	printf("long long size: %d, min %lld, max %lld, max unsigned %llu\n", sizeof(long long), LLONG_MIN, LLONG_MAX, ULLONG_MAX );
	printf("float size: %d, min %f, max %f\n", sizeof(float), FLT_MIN, FLT_MAX);
	printf("double size: %d, min %f, max %f\n", sizeof(double), DBL_MIN, DBL_MAX);
	printf("long double size %d, min: %Lf, max %Lf\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

	return 0;

}

