SRCS	= PhoneBook.cpp main.cpp Contact.cpp

OBJS    = $(SRCS:.c=.o)

NAME    = phonebook

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
