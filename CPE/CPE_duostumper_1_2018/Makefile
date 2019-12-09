## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	main.c	\
	option.c	\
	function.c	\
	tree_a.c	\
	tree_d.c	\
	tree_f.c	\
	test.c

@OBJ = $(SRC:.c=.o)

NAME = tree

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

re: fclean all

.PHONY: all clean fclean
