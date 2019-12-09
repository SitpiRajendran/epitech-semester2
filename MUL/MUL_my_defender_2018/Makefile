##
## EPITECH PROJECT, 2018
## Makefile my_defender
## File description:
## Makefile my_defender
##

SRC	=	src/draw.c	\
	src/event_menu.c		\
	src/event_game.c		\
	src/init_menu.c	\
	src/init_game.c	\
	src/launch.c	\
	src/main.c	\
	src/music.c	\
	src/pause.c		\
	src/score.c		\
	src/movement.c

CFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

@OBJ = $(SRC:.c=.o)

NAME = my_defender

all:	$(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(SRC) -g3 -Wall -Wextra -I include $(CFLAGS)
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@$(clean)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean
