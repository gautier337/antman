##
## EPITECH PROJECT, 2021
## antman
## File description:
## makefile for antman
##

SRC		=	src/errors/errors.c				\
			src/displays/display_tools.c	\
			src/utilities/define_string.c	\
			src/antman.c 					\
			src/lib_tools/lib.c				\
			src/lib_tools/lib2.c			\
			src/list/manage_list.c			\
			src/list/list_functions.c		\
			src/utilities/free_all.c

SRC_MAIN = main.c

SRC_TESTS	=	tests/

NAME	=	antman

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

CFLAGS = -I./includes

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) -L./includes

unit_tests: re
	gcc -o unit_tests $(SRC) $(SRC_TESTS) $(CFLAGS) --coverage -lcriterion

tests_run: unit_tests
	-./unit_tests
	rm unit_tests

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_MAIN)
	rm -f *.gcda
	rm -f *.gcno
	rm -f a.out
	rm -f tmp

fclean: 	clean
	rm -f $(NAME)
	rm -f unit_tests

cover:
	gcovr --exclude tests/
	gcovr --branches --exclude tests/
	make fclean

re:			fclean all

my_tests: tests_run cover

.PHONY = all $(NAME) unit_tests tests_run clean fclean cover re my_tests
