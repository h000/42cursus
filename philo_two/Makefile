SRCS	= main.c create_philo.c utils.c libft.c

OBJS    = $(SRCS:.c=.o)

NAME    = philo_two

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	      

all     : $(NAME)

clean   :
	        rm -f $(OBJS)

fclean  : clean
	        rm -f $(NAME)

re      : fclean all
