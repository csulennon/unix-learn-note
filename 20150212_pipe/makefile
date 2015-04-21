.SUFFIXES:.c .o
CC=gcc
SRCS=test.c
OBJS=$(SRCS:.c=.o)

EXEC=libtest.so

all:$(OBJS)
	$(CC) -shared -o $(EXEC) $(OBJS)
	@echo 编译成功
.c.o:
	$(CC) -Wall -g -fPIC -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f $(EXEC)
	rm -f core*
