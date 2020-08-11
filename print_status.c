#include "philosophers.h"
// void		print_status_body(t_vars *vars, t_philo *philo, t_status status, char *phrase)
// {
// 	unsigned long	time;
// 	int				philo_no;

// 	philo_no = philo->p_idx + 1;
// 	pthread_mutex_lock((&vars->print));
// 	time = get_time() - philo->start_time;
// 	pthread_mutex_lock(&vars->someone_died);
// 	if (vars->flag_died)
// 	{
// 		pthread_mutex_unlock(&vars->someone_died);
// 		return ;
// 	}
// 	pthread_mutex_unlock(&vars->someone_died);
// 	ft_putnbr(time);
// 	ft_putstr(" ");
// 	ft_putnbr(philo_no);
// 	ft_putstr(phrase);
// 	free(phrase);
// 	if (!(status == DIED))
// 		pthread_mutex_unlock(&vars->print);
// }

int	    print_status(t_vars *vars, t_philo *philo, t_status status)
{
	int	philo_no;
	int	time;

	pthread_mutex_lock(&vars->print);
	philo_no = philo->philo_no;
	time = get_time() - vars->t_start;
	pthread_mutex_lock(&vars->someone_died);
	if (vars->died == 1 && status != DIED)
	{
		pthread_mutex_unlock(&vars->someone_died);
		pthread_mutex_unlock(&vars->print);
		return (0);
	}
	pthread_mutex_unlock(&vars->someone_died);
	ft_putnbr(time);
	ft_putstr(" ");
	ft_putnbr(philo_no);
	if (status == THINKING)
		ft_putstr(" is thinking\n");
	else if (status == EATING)
	 	ft_putstr(" is eating\n");
	else if (status == SLEEPING)
	 	ft_putstr(" is sleeping\n");
	else if (status == DIED)
	 	ft_putstr(" died\n");
	else if (status == FORK_TAKEN)
	 	ft_putstr(" has taken a fork\n");
	pthread_mutex_unlock(&vars->print);
	return (0);
	// char *phrase;

	// phrase = 0;
	// if (status == THINKING)
	// 	phrase = ft_strdup(" is thinking\n");
	// else if (status == EATING)
	// 	phrase = ft_strdup(" is eating\n");
	// else if (status == SLEEPING)
	// 	phrase = ft_strdup(" is sleeping\n");
	// else if (status == DIED)
	// 	phrase = ft_strdup(" died\n");
	// else if (status == FORK_TAKEN)
	// 	phrase = ft_strdup(" has taken a fork\n");
	// if (phrase == 0)
	// 	return (0);
	// print_status_body(vars, philo, status, phrase);
	// return (1);
}
