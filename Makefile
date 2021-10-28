SRCS	=	srcs/draw_map.c \
			srcs/error_handling.c \
			srcs/error_handling2.c \
			srcs/ft_free.c		\
			srcs/parse_map.c		\
			srcs/so_long.c \
			srcs/move_handler.c

LIBFT	= libft/libft.a
OBJS	= ${SRCS:.c=.o}
NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Imlx
RM		= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@make -C libft
	@${CC} ${CFLAGS} ${LIBFT} ${OBJS} -Iincludes -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	@cd libft ; make clean
	@${RM} ${OBJS}

fclean: clean
	@cd libft : make fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
