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

int main()
{
	char	str[50];
	char	str2[50];
	int		fd;
	int		errno;
	char	*a;
	char	*b;
	char	*c;


	printf("\n============ft_write============\n");
	fd = open("test.txt", O_WRONLY | O_CREAT , 0777);
	errno = 0;
	printf("return value is %zd\n\n", ft_write(1, "hello world!\n", 13));
	printf("Before error : errno is %d\n", errno);
	printf("return value is %zd\n", ft_write(-1, "hello world!\n", 13));
	printf("After error : errno is %d\n", errno);
	printf("\nwrite test.txt...\n");
	printf("return value is %zd\n", ft_write(fd, "hello world!", 12));
	close(fd);

	printf("\n============ft_read=============\n");
	fd = open("test.txt", O_RDONLY);
	errno = 0;
	printf("read test.txt...\n");
	printf("return value is %zd\n", ft_read(fd, str, 12));
	printf("result : %s\n\n", str);
	printf("Before error : errno is %d\n", errno);
	printf("return value is %zd\n", ft_read(-1, "hello world!\n", 13));
	printf("After error : errno is %d\n", errno);
	close(fd);

	printf("\n============ft_strlen==========\n");
	printf("The length of str (%s) : %zd\n", str, ft_strlen(str));

	printf("\n============ft_strcpy==========\n");
	printf("source : %s\n", str);
	printf("result : %s\n", ft_strcpy(str2, str));
	printf("destination : %s\n", str2);

	printf("\n============ft_strcmp==========\n");
	printf("%d\n", ft_strcmp(str, str2));
	printf("%d\n", ft_strcmp("a", "b"));

	printf("\n============ft_strdup==========\n");
	a = ft_strdup("hello");
	b = ft_strdup("strdup is done!");
	c = ft_strdup("");
	printf("result : %s\n", a);
	printf("result : %s\n", b);
	printf("result : %s\n", c);
	free(a);
	free(b);
	free(c);
}