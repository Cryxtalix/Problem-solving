CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -Wmissing-prototypes -Wstrict-prototypes -fanalyzer -O
DEBUG := -g

ll: ll1.c
	@$(CC) ll1.c $(CFLAGS) -o linkedlist.out

debug: ll1.c
	@$(CC) ll1.c $(CFLAGS) $(DEBUG) -o linkedlist_debug.out
