CC=gcc

test:
	@rm -f testing
	@$(CC) main.c readwrite/readwrite.c -o testing
	@./testing