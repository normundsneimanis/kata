all: a.out test_stack test_math

clean: a.out test_stack test_math
	rm a.out test_stack test_math

a.out: main.c getop.c inputBuffer.c stack.c
	gcc -Wall -lm -g main.c getop.c inputBuffer.c stack.c

test_stack: test_stack.c
	gcc -Wall -g -o test_stack stack.c test_stack.c

test_math: test_math.c
	gcc -Wall -lm -o test_math test_math.c
