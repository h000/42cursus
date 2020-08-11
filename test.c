#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

unsigned long	get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, 0))
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void			ft_usleep(unsigned long time)
{
	unsigned long start;
	unsigned long time_elapsed;

	start = get_time();
	while (1)
	{
		time_elapsed = get_time() - start;
		if (time_elapsed >= time)
			break ;
		usleep(1);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar_fd(nb + '0', 1);
}

void	*test(void *p)
{

	// vars = get_vars();
	// philo = (t_philo *)p;
	while (1)
	{
		// print_status(vars, philo, THINKING);
		ft_putstr("1234");
		// if (!eat(vars, philo))
		// 	break ;
		// print_status(vars, philo, SLEEPING);
	 	usleep(600);
	}
}

int		main(int argc, char **argv)
{
    pthread_t   *thread;
    thread = malloc(sizeof(pthread_t) * 5);

    int i = 0;
	while (i < 5)
	{
		if (pthread_create(&thread[i], 0, &test, 0))
			return (0);
		// if (pthread_join(thread[i], 0))
		// 	return (0);
		if (pthread_detach(thread[i]))
			return (0);
		i++;
	}
	// if (pthread_join(thread[i], 0))
	// 		return (0);

	ft_usleep(100);
}