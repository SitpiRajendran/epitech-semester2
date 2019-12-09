## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	src/main.c	\
	src/args.c	\
	src/error.c	\
	src/debug.c	\
	src/fonctions.c	\
	src/get_tetriminos.c	\
	src/help.c	\
	src/init.c	\
	src/lists.c	\
	src/launch.c	\
	src/game.c	\
	src/map.c	\
	src/read_now.c	\

CFLAGS += -I include

OBJ = $(SRC:.c=.o)

NAME = tetris

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) -lncurses
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: CFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@gcc -o $(NAME) $(OBJ) -lncurses
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

.PHONY: all clean fclean re test

.SILENT: $(OBJ)