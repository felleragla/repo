##
## EPITECH PROJECT, 2023
## makefile
## File description:
## make
##

NAME    =       my_hunter

SRC     =      	my_hunter.c\
				my_cond.c\
				mini_printf.c\
				my_restart.c

OBJ     =       $(SRC:.c=.o)

all     :       $(NAME)
$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean   :
		rm -f $(OBJ)

fclean  :       clean
	rm -rf $(NAME)

re      :	fclean all
