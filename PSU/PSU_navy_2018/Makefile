## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	src/connection.c	\
	src/errorhelp.c	\
	src/fonction.c	\
	src/fonction_next.c	\
	src/get_pos.c	\
	src/get_next_line.c	\
	src/init_map.c	\
	src/main.c	\
	src/openread.c	\
	src/verif_map.c	\
	src/game.c	\
	src/get_pos_game.c	\
	src/win_verif.c

@OBJ =	$(SRC:.c=.o)

NAME = navy

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(SRC) -g3 -Wall -Wextra -I include
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@$(clean)


fclean: clean
	@rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean
