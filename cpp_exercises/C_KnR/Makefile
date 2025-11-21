sources = $(shell find ./ -name "*.c" -maxdepth 1 -type f)
sources = $(wildcard *c)
directories = $(shell find . -maxdepth 1 -type d)
directories = $(wildcard */)

results = $(subst .c,,$$sources)

all: files directories

clean: cleanfiles cleandirectories

files: 5-1 5-2
	echo $(patsubst %.c,%.o,1-1.c)
	echo $(subst .c,.o,1-1.c)
	echo $(subst .c,,1-1.c)
	@- $(foreach f,$(sources), \
		$(eval X = $(subst .c, ,$(f))) \
		echo gcc -Wall -g -o $X $(f); \
		gcc -Wall -g -o $X $(f); \
	)

cleanfiles:
	@- $(foreach f,$(sources), \
		$(eval X = $(subst .c, ,$(f))) \
		echo removing $X; \
		rm -f $X; \
	)


directories:
	@- $(foreach f,$(directories), \
		echo === Building $(f); \
		cd $(f); gmake; cd ..; \
	)

cleandirectories:
	@- $(foreach f,$(directories), \
		echo === Cleaning $(f); \
		cd $(f); gmake clean; cd ..; \
	)

5-1: 5-1.c 4-11/inputBuffer.c
	gcc -Wall -g -o 5-1 5-1.c 4-11/inputBuffer.c

5-2: 5-2.c 4-11/inputBuffer.c
	gcc -Wall -g -o 5-2 5-2.c 4-11/inputBuffer.c

5-3: 5-3.c
	gcc -Wall -g -o 5-3 5-3.c

5-4: 5-4.c
	gcc -Wall -g -o 5-4 5-4.c

5-5: 5-5.c
	gcc -Wall -g -lc -o 5-5 5-5.c

5-6: 5-6.c
	gcc -Wall -g -lc -o 5-6 5-6.c
