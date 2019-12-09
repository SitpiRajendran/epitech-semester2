##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile compiles your programs
##

SRC 	=	src/main.c	\
	src/dispatch.c	\
	src/error.c	\
	src/flag_s.c	\
	src/freeall.c	\
	src/function.c	\
	src/init_nbr.c	\
	src/malloc.c	\
	src/printnum.c	\
	src/printnum_next.c	\
	src/print_while.c

SRC_T 	=	src/dispatch.c	\
	src/error.c	\
	src/flag_s.c	\
	src/freeall.c	\
	src/function.c	\
	src/init_nbr.c	\
	src/malloc.c	\
	src/printnum.c	\
	src/printnum_next.c	\
	src/print_while.c	\
	tests/test_crocus.c	\

OBJ_T = $(SRC_T:.c=.o)

NAME_T = unit_tests

CFLAGS += -I include

FLAGS	=	--coverage -lcriterion

OBJ = $(SRC:.c=.o)

NAME = crocus

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f tests/*.o
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_T)

re: fclean all

test: CFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"

tests_run: $(OBJ_T) $(OBJ)
	@gcc -o $(NAME_T) $(FLAGS) $(SRC_T) $(CFLAGS)
	./$(NAME_T)
	gcovr

fclean_t: clean
	@rm -f $(NAME)
	@rm -f $(NAME_T)

.PHONY: all clean fclean re test test_run fclean_t

.SILENT: $(OBJ) $(OBJ_T)
