#include <stdio.h>


int main()
{
	int c, newlines, spaces, tabs;
	newlines = 0;
	spaces = 0;
//	tabs = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n') {
			++newlines;
		} else if (c == ' ') {
			spaces++;
		} else if (c == '\t') {
			tabs++;
		}
	printf("Newlines: %d, Spaces: %d, Tabs: %d\n", newlines, spaces, tabs);

	return 0;
}
