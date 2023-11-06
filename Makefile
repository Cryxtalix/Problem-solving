CC=gcc

test:
	@$(CC) main.c lib/readwrite.c -o testing
	@./testing
	@rm -f testing