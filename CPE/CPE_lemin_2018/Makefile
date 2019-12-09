##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME = lem_in

SRC	=	sources/main.c
SRC	+=	sources/check_map.c
SRC	+=	sources/check_position.c
SRC	+=	sources/check_room.c
SRC	+=	sources/check_tunnels.c
SRC	+=	sources/count_room.c
SRC	+=	sources/count_tunnel.c
SRC	+=	sources/free_map.c
SRC	+=	sources/get_map.c
SRC	+=	sources/lem_in.c
SRC	+=	sources/new_parser.c
SRC	+=	sources/rooms_occurences.c
SRC	+=	ressources/fonctions.c
SRC	+=	ressources/mem_alloc_2d_array.c
SRC	+=	ressources/fonctionsnext.c

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
