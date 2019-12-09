##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME = mysh

SRC	=	src/main.c
SRC	+=	src/boxwhile.c
SRC	+=	src/cd.c
SRC	+=	src/command.c
SRC	+=	src/env.c
SRC	+=	src/execve.c
SRC	+=	src/fonction_next.c
SRC	+=	src/fonctions.c

@OBJ = $(SRC:.c=.o)

all:	$(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(SRC) -g3 -Wall -Wextra -I include
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@$(clean)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean
