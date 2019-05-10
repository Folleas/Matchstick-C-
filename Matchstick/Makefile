##
## EPITECH PROJECT, 2018
## My_runner
## File description:
## My_runner's makefile
##

SRCDIR  =       src

INCDIR =	include

SRC     =	$(SRCDIR)/matchstick.c \
		$(SRCDIR)/manage_map.c \
		$(SRCDIR)/simple_functions.c \
		$(SRCDIR)/display_map.c \
		$(SRCDIR)/manage_input.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       matchstick

CFLAGS  =       -W -Wall -Wextra -I include/

all:            $(NAME)

$(NAME):	$(OBJ)
		gcc $(SRC) -g3 -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

