#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
char	*ft_strcpy(char *dst, char const *src);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(char const *s1);
int		ft_strcmp(char const *s1, char const *s2);

int main(void)
{
	char dest[50];
	char buf[10];
	int fd;
	char *a;
	char *b;
	char *c;

	printf("========write=======\n");
	printf("write_size is : %zu\n", write(1, "hello\n", 6));
	printf("errno %d\n", errno);
	write(3, "hello\n", 6);
	printf("errno %d\n", errno);
	printf("========read=======\n");
	fd = open("test.txt", O_RDONLY);
	printf("read_size is : %zu\n", read(fd, buf, 5));
	buf[5] = '\n';
	buf[6] = '\0';
	write(1, buf, 6);
	printf("errno %d\n", errno);
	fd = open("test2.txt", O_RDONLY);
	read(fd, buf, -1);
	buf[5] = '\n';
	buf[6] = '\0';
	write(1, buf, 6);
	printf("errno %d\n", errno);
	printf("========ft_strlen=======\n");
	printf("strlen is : %zu\n", ft_strlen("wow"));
	printf("strlen is : %zu\n", ft_strlen(""));
	printf("========ft_strcpy=======\n");
	printf("%s\n", ft_strcpy(dest, "licorne"));
	printf("%s\n", ft_strcpy(dest, "aaa"));
	printf("%s\n", ft_strcpy(dest, "aa"));
	printf("%s\n", ft_strcpy(dest, ""));
	printf("========ft_strcmp=======\n");
	printf("%d\n", ft_strcmp("abc", "abc"));
	printf("%d\n", ft_strcmp("a", "b"));
	printf("%d\n", ft_strcmp("", "a"));
	printf("%d\n", ft_strcmp("aaaaa", "a"));
	printf("%d\n", ft_strcmp("a", "aaaaa"));
	// printf("========ft_strdup=======\n");
	// a = ft_strdup("hello");
	// b = ft_strdup("strdup is done!");
	// c = ft_strdup("");
	// printf("'%s'\n", a);
	// printf("'%s'\n", b);
	// printf("'%s'\n", c);
	// free(a);
	// free(b);
	// free(c);
	return (0);
}