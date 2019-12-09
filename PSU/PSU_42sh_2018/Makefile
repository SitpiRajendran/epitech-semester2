##
## EPITECH PROJECT, 2019
## PSU_42sh_2018
## File description:
## Makefile of the navy project
##

SRC		=	src/args_checks.c		\
			src/args_modif.c		\
			src/buffer_change_third.c	\
			src/buffer_change_sec.c	\
			src/buffer_change.c		\
			src/buffer_error.c		\
			src/built_ins.c			\
			src/check_echo.c		\
			src/more_built_in.c		\
			src/env_change.c		\
			src/env.c				\
			src/execve_check.c		\
			src/execve.c			\
			src/handle_pipe.c		\
			src/history.c		\
			src/lib_advanced.c		\
			src/lib_functions_sec.c	\
			src/lib_functions_tres.c	\
			src/lib_functions.c		\
			src/list_manage.c		\
			src/lists_functions.c	\
			src/main.c				\
			src/more_redirections.c	\
			src/paths.c				\
			src/redirections.c		\

NAME	=	42sh

OBJ = $(SRC:.c=.o)

CPPFLAGS	+=	-I ./include

all:	$(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: CFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

.PHONY: all clean fclean re test

.SILENT: $(OBJ)
