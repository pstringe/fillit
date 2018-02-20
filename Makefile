CC = gcc
SRD = srcs/
INC = ./libft
NAME = fillit
SRCS = $(SRD)fillit.c\
	   $(SRD)read.c\
	   $(SRD)board.c\
	   $(SRD)output.c\
	   $(SRD)error.c\
	   $(SRD)normalize.c\
	   $(SRD)solve.c
OBJS = fillit.o\
	   read.o\
	   board.o\
	   output.o\
	   error.o\
	   normalize.o\
	   solve.o
LIBD = -L$(INC) -lft
CFLAGS = -Wall -Werror -Wextra -I$(INC) 
OFLAGS = -o $(NAME) $(OBJS) $(LIBD)

all: $(NAME)

libft.a :
	make -C ./libft
$(NAME): libft.a $(OBJS)
	$(CC) $(OFLAGS)

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)
	rm -f libft/*.o
	rm -f libft/libft.a

fclean: clean
	rm -f $(NAME)
	rm -f $(DNAME)
	rm -rf $(DNAME).dSYM

re: fclean
	make
