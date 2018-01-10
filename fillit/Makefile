CC = gcc
INC = ../libft
NAME = fillit
SRCS = fillit.c\
	   error.c\
	   read_tetromino_set.c\
	   file_validation.c\
	   label_tetrominos.c\
	   dimensional_access.c\
	   validate_tetrominos.c\
	   bitwise_encoder.c\
	   spatial_manipulation.c\
	   normalize_tetromino.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
LIBD = -L$(INC) -lft
CFLAGS = -Wall -Werror -Wextra -I$(INC) 
OFLAGS =  -o $(NAME) $(OBJS) $(LIBD)
DSRCS = $(SRCS)
DFLAGS = $(CFLAGS) -g $(LIBD) $(DSRCS) -o
DNAME = $(NAME)_debug
DOBJS = $(patsubst %.c, %.o, $(DSRCS))

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(OFLAGS)
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
	lldb $(DNAME) $(DARGS)
