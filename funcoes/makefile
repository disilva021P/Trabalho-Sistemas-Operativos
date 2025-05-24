SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
PROGS := $(SRCS:.c=)

CC := gcc
CFLAGS := -Wall -Wextra -g

.PHONY: all clean

all: $(PROGS)

# Linka só o .o para gerar executável
%: %.o
	$(CC) $(CFLAGS) -o $@ $^

# Compila .c para .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROGS)
