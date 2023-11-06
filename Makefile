CC=gcc

test:
	@rm -f testing
	@$(CC) main.c input/input.c -o testing
	@./testing