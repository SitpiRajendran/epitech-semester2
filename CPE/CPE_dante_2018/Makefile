## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile compiles your programs
##

all:
	@$(MAKE) -C generator
	@$(MAKE) -C solver
	@echo -e "\033[1;32mCOMPILATION FINISHED\033[0m"
	@$(clean)

clean:
	@$(MAKE) clean -C generator
	@$(MAKE) clean -C solver
	@echo -e "\033[1;32mCLEANING WAS DONE\033[0m"

fclean:
	@$(MAKE) fclean -C generator/
	@$(MAKE) fclean -C solver/

re: fclean all

test:
	@$(MAKE) test -C generator
	@$(MAKE) test -C solver

.PHONY: all clean fclean re test