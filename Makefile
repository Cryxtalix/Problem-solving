CC=gcc

all:
	@$(CC) main.c lib/readwrite.c lib/checker.c -o solver.out
	@./solver.out
	@rm -f solver.out

test:
	@$(CC) test.c lib/checker.c lib/readwrite.c -o test.out
	@./test.out
	@rm -f test.out