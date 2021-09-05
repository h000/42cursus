MLX		= -lmlx -framework Metal -framework AppKit

SRCS	= src/ft_dotting.c src/ft_error_check.c src/ft_keypressed.c src/ft_keypressed_2.c src/ft_map.c\
		  src/ft_parsing.c src/ft_render.c src/ft_save.c src/ft_sprites.c src/get_next_line.c src/get_next_line_utils.c\
		  src/libft_util.c src/libft_util_2.c src/main.c

OBJS    = $(SRCS:.c=.o)

NAME    = cub3d

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		cp minilibx_mms_20200219/libmlx.dylib .
		$(CC) $(CFLAGS) $(OBJS) $(MLX) -L ./ -o $(NAME)
	      

all     : $(NAME)

clean   :
	        rm -f $(OBJS)

fclean  : clean
	        rm -f $(NAME)

re      : fclean all

