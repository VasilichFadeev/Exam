CC = gcc
CFLAGS = -Wall -Wextra -Werror

%: %.c
	$(CC) $(CFLAGS) $< -o $@

compile:
	$(CC) $(CFLAGS) $(FILE) -o $(basename $(FILE))

clean:
	rm -f $(wildcard *.o) 2>/dev/null || true

.PHONY: clean compile