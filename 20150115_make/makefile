 #.c 和.o 简历联系
.SUFFIXES:.c .o 
CC=gcc
SRCS	=	hello.c \
		add.c   	#同时编译两个文件

OBJS=$(SRCS:.c=.o)
EXEC=hello
start:$(OBJS)
	$(CC) -o$(EXEC) $(OBJS)
	@rm -f $(OBJS)
	@echo '---------ok------------'
	@ls -l --color=auto
.c.o:
	$(CC) -Wall -g  -c $< -o$@

clean:
	@rm -f $(OBJS) $(EXEC)
	@echo '---------clean---------'
	@ls -l --color=auto
