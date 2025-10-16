CC = gcc
CFLAGS = -Wall -Wextra -pthread

%: %.c
	$(CC) $(CFLAGS) -o $@.out $<

clean:
	@echo 'Cleaning...'
	rm *.out
