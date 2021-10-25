SRCS	= ft_printf.c write_arg.c write_arg_nbr.c write_arg_letter.c ft_putnbr_base.c util.c util2.c

OBJS    = ${SRCS:.c=.o}

NAME    = libftprintf.a

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

%.o: %.c
	        ${CC} ${CFLAGS} -c $< -o $@

$(NAME) : ${OBJS}
	        ar rc ${NAME} ${OBJS}

all     : ${NAME}

clean   :
	        rm -f *.o

fclean  : clean
	        rm -f $(NAME)

re      : fclean all

