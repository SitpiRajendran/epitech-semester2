## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile compiles your programs
##

SRC =	src/main.c	\
	src/attack.c	\
	src/animation.c	\
	src/error_management.c	\
	src/init_menu.c	\
	src/init_game.c	\
	src/function.c	\
	src/functions_next.c	\
	src/fight.c	\
	src/game_events.c	\
	src/game_launch.c	\
	src/launch.c	\
	src/moves.c	\
	src/menu_events.c	\
	src/pause.c	\
	src/particles.c	\
	src/life.c	\
	src/set_fight.c	\
	src/set_life.c	\
	src/setting_events.c	\
	src/talking.c	\
	src/win_lose.c

CPPFLAGS += -I include

CFLAGS += -Wall -Wextra

OBJ = $(SRC:.c=.o)

NAME = my_rpg

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo -e "\033[1;32mCleaning finished !\033[0m"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: CFLAGS += -Wall -Wextra -g3
test: $(OBJ)
	@gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
	@echo -e "\033[1;32mCompilation completed sucessfully\033[0m"
	@rm -f $(OBJ)

.PHONY: all clean fclean re test

.SILENT: $(OBJ)
