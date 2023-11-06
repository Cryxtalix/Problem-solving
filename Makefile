CC=gcc

test:
	@$(CC) main.c lib/readwrite.c lib/checker.c -o testing
	@./testing
	@rm -f testing