## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile compiles your programs
##

SRC =		src/main.c			\
		src/error.c			\
		src/check_way.c			\
		src/generator.c			\
		src/create_maze.c		\
		src/check_direction.c		\
		src/move.c			\
		ressources/malloc_array.c	\
		ressources/print_array.c	\

CFLAGS += -I include

OBJ = $(SRC:.c=.o)

NAME = generator

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

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