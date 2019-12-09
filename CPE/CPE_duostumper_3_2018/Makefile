## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	src/main.c	\
	src/dispatch.c	\
	src/error.c	\
	src/flag_s.c	\
	src/freeall.c	\
	src/function.c	\
	src/init_nbr.c	\
	src/printnum.c	\
	src/printnum_next.c	\
	src/print_while.c

CFLAGS= -I include

CTESTFLAGS = -Wall -Wextra -g3

@OBJ = $(SRC:.c=.o)

NAME = crocus

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(SRC) $(CFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@$(clean)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: $(OBJ)
	@gcc -o $(NAME) $(SRC) $(CFLAGS) $(CTESTFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@$(clean)

.PHONY: all clean fclean re
