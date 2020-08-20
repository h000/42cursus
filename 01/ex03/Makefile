SRCS	= Zombie.cpp ZombieEvent.cpp main.cpp

OBJS    = $(SRCS:.cpp=.o)

NAME    = zombie

CC      = clang++

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
