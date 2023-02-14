##
## EPITECH PROJECT, 2022
## antman
## File description:
## compress and decompress a file
##

all:
	make -C antman all
	make -C giantman all

clean:
	make -C antman clean
	make -C giantman clean

fclean:
	make -C antman fclean
	make -C giantman fclean

re:			fclean all

.PHONY = all re clean fclean
