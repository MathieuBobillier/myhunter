##
## EPITECH PROJECT, 2020
## B-MUL-100-LYN-1-1-myhunter-mathieu.bobillier
## File description:
## Makefile
##

SRC		=		my_hunter.c		\
				avance.c		\
				my_putstr.c		\
				my_putchar.c	\
				my_put_nbr.c	\
				description.c	\

OBJ		=		$(SRC:.c=.o)

NAME 	=		my_hunter

$(NAME):		$(OBJ)
		gcc -o $(NAME) $(OBJ) -g3 -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

clean:
		rm -f $(OBJ)
		rm -f *~

fclean: clean
		rm -f $(NAME)

re:		fclean all
