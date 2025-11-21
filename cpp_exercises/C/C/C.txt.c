//preprocessor works:
#include <stdio.h> //replaced by contents of this file
#define IDENTIFIER	replacement


// Function declaration: prototype
void show_message(void);

// Viens un taspats
int main() {}
main() {}

// veseli skaitlji
The integral types are the short, long, signed, unsigned and plain ints.
char arii ir int, bet savaadaak manadzee atminju

// printf lieto:
%c  	char (in character form)
%d 	decimal signed int, short, char
%u 	decimal unsigned int, unsigned short, unsigned char
%x 	hexadecimal int, short, char
%o 	octal int, short, char
%ld 	decimal signed long
%lu %lx %lo 	as above, but for longs


switch (expression){
case const1:    statements
case const2:    statements
default:        statements
}

for(i = 0; i <= 10; i++){ }

goto L1;
/* whatever you like here */
L1: /* anything else */

if (a!=0 && b/a > 5)...
/* alternative */
if (a && b/a > 5)

if (!a)...
/* alternative */
if (a==0)...

if(!(a>b))
/* alternative */
if(a <= b)

if (!(a>b && c<d))...
/* alternative */
if (a<=b || c>=d)...

expression1?expression2:expression3
If expression1 is true, then the result of the whole expression is expression2, otherwise it is expression3

for(i=0; i <= 10; i++){
	printf((i&1) ? "odd\n" : "even\n");
}
