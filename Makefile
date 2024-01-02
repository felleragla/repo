##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## our Makefile
##

NAME = radar

SRC = window.c	\
	event.c 	\
	circle.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	gcc -o $(NAME) $(OBJS) -lm -lcsfml-graphics -lcsfml-window -lcsfml-system
$(OBJS):
	gcc -c $(SRC)
clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re : fclean all
