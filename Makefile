NAME=			libftprintf.a

INCLUDE_PATH=	include/

SRC_FILES=		srcs/printf.c \
				srcs/printf_utils_part1.c \
				srcs/printf_utils_part2.c \
				srcs/printf_utils_part3.c
BONUS=			srcs/printf_bonus.c \
			srcs/printf_utils_part1_bonus.c \
			srcs/printf_utils_part2_bonus.c \
			srcs/printf_utils_part3_bonus.c

SRC_OBJS=		${SRC_FILES:.c=.o}

BONUS_OBJS=		$(BONUS:.c=.o)

CC= 			gcc

CFLAGS=			-Wall -Wextra -Werror 

RM=				rm -f

AR=				ar rcs

FILE=				touch

all:			${NAME}

${NAME}:    	${SRC_OBJS}
				${AR} ${NAME} ${SRC_OBJS}

bonus:		$(BONUS_OBJS)
				$(AR) $(NAME) $(BONUS_OBJS)
				$(FILE) bonus

clean:
				${RM} ${SRC_OBJS} $(BONUS_OBJS) bonus

fclean: 		clean
				${RM} ${NAME}

re:         	fclean all

.PHONY:        all clean fclean re
