#include <stdio.h>
#include <stdlib.h>

int binsearchOrig(int x, int v[], int n);
int binsearch(int x, int v[], int n);

#define ARRAY_MAX 100

int main() {
	int array[ARRAY_MAX];

	int i;
	for (i = 0; i < ARRAY_MAX; i++) {
		array[i] = i;
		printf("%i ", i);
	}
	printf("\n");


	int result = -2;
	int ok, nok;
	ok = nok = 0;
	for (i = 0; i < ARRAY_MAX; i++) {
		if ((result = binsearch(i, array, ARRAY_MAX)) == i) {
			printf("%i Ok\n", i);
			ok++;
		} else {
			printf("%i NOK. Got %i\n", i, result);
			nok++;
		}
	}

	printf("Ok %i nok %i\n", ok, nok);

	return 0;
}


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low+high)/2;

	while (low <= high && x != v[mid]) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	if (x == v[mid]) {
		return mid;
	} else {
		return -1;
	}
}


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearchOrig(int x, int v[], int n)
{
	int low, high, mid;
	/* int low_prev, high_prev, mid_prev;
	low_prev = high_prev = mid_prev = -2; */
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		/* printf("Low: %i High %i mid %i x: %i v[mid]: %i\n", low, high, mid, x, v[mid]);
		if (low == low_prev && high == high_prev && mid == mid_prev) {
			printf("Binary search failed\n");
			return -1;
		} */
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;

		/* mid_prev = mid;
		high_prev = high;
		low_prev = low; */
	}

	return -1; /* no match */
}
