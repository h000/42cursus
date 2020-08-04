SRCS	= ft_write.s ft_strlen.s ft_strcpy.s ft_strcmp.s ft_read.s

OBJS	= $(SRCS:.s=.o)

NAME	= libasm.a

%.o		: %.s
		nasm -f macho64 $<

$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)

all		: $(NAME)

clean	:
		rm -f *.o

fclean	: clean
		rm -f $(NAME)

re		: fclean all