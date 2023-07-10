all: test1

test1: a3_birthdayLookupSystem.c a3_birthdaylib.c
	gcc -Wall -std=c99 -fsanitize=leak -o test1 a3_birthdayLookupSystem.c a3_birthdaylib.c

clean:
	rm -f test1
