PROGS = bench_cpu bench_mem
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

default: $(PROGS)

clean:
	rm -f $(PROGS)
