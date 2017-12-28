CC = gcc
NAME = fillit
SRCS = fillit.c\
	   error.c\
	   read_tetromino_set.c\
	   file_validation.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
LIBD = -L./libft -lft
CFLAGS = -Wall -Werror -Wextra
OFLAGS = $(CFLAGS) $(LIBD) -o
DSRCS = $(SRCS)
DFLAGS = $(CFLAGS) -g $(LIBD) $(DSRCS) -o
DNAME = $(NAME)_debug
DOBJS = $(patsubst %.c, %.o, $(DSRCS))

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(OFLAGS) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(DNAME)
	rm -rf $(DNAME).dSYM
re: fclean
	make

debug: $(DNAME)

$(DNAME):
	$(CC) $(DFLAGS) $(DNAME)
	export DARGS=test
	lldb $(DNAME) $(DARGS)
