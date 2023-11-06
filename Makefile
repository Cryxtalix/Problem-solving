CC=gcc

test:
	@$(CC) main.c readwrite/readwrite.c -o testing
	@./testing
	@rm -f testing