NAME=			libftprintf.a

INCLUDE_PATH=	include/

SRC_FILES=		srcs/ft_printf.c \
				srcs/printf_utils1.c \
				srcs/printf_utils2.c \
				srcs/decimal_number.c \
				srcs/hexa_number_pointer.c \
				srcs/parser.c \
				srcs/strings_and_char.c \
				srcs/to_print.c

BONUS=			srcs/ft_printf.c \
				srcs/printf_utils1.c \
				srcs/printf_utils2.c \
				srcs/decimal_number.c \
				srcs/hexa_number_pointer.c \
				srcs/parser.c \
				srcs/strings_and_char.c \
				srcs/to_print.c

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

.PHONY:        all clean fclean re bonus
