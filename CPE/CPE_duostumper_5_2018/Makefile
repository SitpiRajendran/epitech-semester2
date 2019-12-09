## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	src/main.c	\
	src/error.c	\
	src/get_args.c	\
	src/get_pos.c	\
	src/game.c	\
	src/init_tab.c	\
	src/print_tab.c	\
	src/win.c	\
	src/launch.c

CFLAGS += -I include

OBJ = $(SRC:.c=.o)

NAME = tictactoe

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: CFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@gcc -o $(NAME) $(OBJ)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

.PHONY: all clean fclean re test

.SILENT: $(OBJ)
