##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRCS	=	src/printf_utils.c \
			src/printf_hub.c	\
			src/printf_utils.c	\
			src/printf_main.c \
			src/printf_convertor.c	\
			src/printf_integers.c	\
			src/printf_parsing.c	\
			src/printf_chars.c	\

OBJS = ${SRCS:.c=.o}

RM = rm -f

CRITERION_F = --coverage -lcriterion -I include

NAME = libmy.a

all : ${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

test_criterion_fclean:
	rm -f *gcno
	rm -f *gcda
	rm -f unit_tests

test_criterion: test_criterion_fclean
	${CC} -o unit_tests src/*.c tests/*.c ${CRITERION_F}

tests_run: test_criterion
	./unit_tests

.PHONY: all clean fclean re
