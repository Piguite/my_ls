##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRCS = 	src/args.c \
		src/folder.c \
		src/info.c \
		src/get_flag.c \
		src/main_fonction.c \
		src/sort_folder.c \
		src/utils.c \
		src/sort_args.c \
		src/print.c \
		src/print2.c \
		main.c \

OBJS = ${SRCS:.c=.o}

NAME = my_ls

CC = gcc

RM = rm -f

${NAME}:	${OBJS}
			cd include/lib_printf && make
			${CC} -o ${NAME} ${OBJS} -L include/lib_printf -lmy

all :	${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		cd include/lib_printf && make fclean
		${RM} ${NAME}

re: fclean all
