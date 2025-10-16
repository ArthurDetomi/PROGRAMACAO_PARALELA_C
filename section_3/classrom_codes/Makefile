CC = gcc
CFLAGS = -Wall -Wextra -pthread -g

%: %.c
	$(CC) $(CFLAGS) -o $@.out $<

clean:
	@echo 'Cleaning...'
	rm *.out
