# libft

recode a few functions of the C standard library



## List of Functions
- Mandatory Part

    - memory
    
      [`memset`](./ft_memset.c) [`bzero`](./ft_bzero.c) [`memcpy`](./ft_memcpy.c) [`memccpy`](./ft_memccpy.c) [`memmove`](./ft_memmove.c) [`memchr`](./ft_memchr.c) [`memcmp`](./ft_memcmp.c) [`calloc`](./ft_calloc.c)
    
    - string
    
      [`strlen`](./ft_strlen.c) [`strlcpy`](./ft_strlcpy.c) [`strlcat`](./ft_strlcat.c) [`strchr`](./ft_strchr.c) [`strrchr`](./ft_strrchr.c) [`strnstr`](./ft_strnstr.c) [`strncmp`](./ft_strncmp.c) [`atoi`](./ft_atoi.c) [`strdup`](./ft_strdup.c)
    
      [`isalpha`](./ft_isalpha.c) [`isdigit`](./ft_isdigit.c) [`isalnum`](./ft_isalnum.c) [`isascii`](./ft_isascii.c) [`isprint`](./ft_isprint.c) [`toupper`](./ft_toupper.c) [`tolower`](./ft_tolower.c)

      [`ft_substr`](./ft_substr.c) [`ft_strjoin`](./ft_strjoin.c) [`ft_strtrim`](./ft_strtrim.c) [`ft_split`](./ft_split.c) [`ft_itoa`](./ft_itoa.c) [`ft_strmapi`](./ft_strmapi.c)

    - put_fd
    
      [`ft_putchar_fd`](./ft_putchar_fd.c) [`ft_putstr_fd`](./ft_putstr_fd.c) [`ft_putendl_fd`](./ft_putendl_fd.c) [`ft_putnbr_fd`](./ft_putnbr_fd.c)

- Bonus Part
    
    - linked list
      ``` cpp
      typedef struct  s_list
      {
        void *content;
        struct s_list *next;
      }               t_list;
      ```

      [`ft_lstnew`](./ft_lstnew.c) [`ft_lstadd_front`](./ft_lstadd_front.c) [`ft_lstsize`](./ft_lstsize.c) [`ft_lstlast`](./ft_lstlast.c) [`ft_lstadd_back`](./ft_lstadd_back.c) [`ft_lstdelone`](./ft_lstdelone.c) [`ft_lstclear`](./ft_lstclear.c) [`ft_lstiter`](./ft_lstiter.c) [`ft_lstmap`](./ft_lstmap.c)
