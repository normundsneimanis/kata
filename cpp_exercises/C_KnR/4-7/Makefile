all: a.out test_stack test_math test_ungets

clean:
	rm -f a.out test_stack test_math test_ungets

a.out: main.c getop.c inputBuffer.c stack.c
	gcc -Wall -lm -g main.c getop.c inputBuffer.c stack.c

test_stack: test_stack.c
	gcc -Wall -g -o test_stack stack.c test_stack.c

test_math: test_math.c
	gcc -Wall -lm -o test_math test_math.c

test_ungets: test_ungets.c inputBuffer.c
	gcc -Wall -g -o test_ungets test_ungets.c inputBuffer.c
