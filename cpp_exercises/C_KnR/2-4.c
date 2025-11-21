
#include <stdio.h>

#include <stdlib.h>

void squeeze(char s[], int c);

int main() {
	char s[] = "abc5defg";
	char c = 'b';
	squeeze(s, (int) c);

	printf("%s\n", s);
	return 0;
}


/* squeeze: delete all c from s */
/*void squeeze(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}
*/

void squeeze(char s[], int c)
{
	int i = -1; // Src array element
	int j = 0; // Dst array element
	while (s[++i] != 0) {
		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}
