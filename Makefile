NAME=			libftprintf.a

INCLUDE_PATH=	include/

SRC_FILES=		srcs/printf.c \
				srcs/printf_utils_part1.c \
				srcs/printf_utils_part2.c \
				srcs/printf_utils_part3.c

SRC_OBJS=		${SRC_FILES:.c=.o}

CC= 			gcc

CFLAGS=			-Wall -Wextra -Werror 

RM=				rm -f

AR=				ar rcs

all:			${NAME}

${NAME}:    	${SRC_OBJS}
				${AR} ${NAME} ${SRC_OBJS}

clean:
				${RM} ${SRC_OBJS}

fclean: 		clean
				${RM} ${NAME}

re:         	fclean all

.PHONY:        all clean fclean re
