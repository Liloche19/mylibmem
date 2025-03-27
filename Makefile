SRC	=	lib/mem/my_malloc.c\
		lib/mem/my_free.c\
		lib/mem/my_memory.c\

TEST	=	test/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -W -g

NAME	=	libmem.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

dev:	re
	gcc $(TEST) -L. -lmem
