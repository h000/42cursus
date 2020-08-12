/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:47:29 by hpark             #+#    #+#             */
/*   Updated: 2020/08/12 13:47:30 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void			print_info(t_vars *vars, t_philo *philo)
{
	int	philo_no;
	int	time;

	philo_no = philo->philo_no;
	time = get_time() - vars->t_start;
	ft_putnbr(time);
	ft_putstr(" ");
	ft_putnbr(philo_no);
}

int				print_status(t_vars *vars, t_philo *philo, t_status status)
{
	pthread_mutex_lock(&vars->print);
	pthread_mutex_lock(&vars->someone_died);
	if (vars->died == 1 && status != DIED)
	{
		pthread_mutex_unlock(&vars->someone_died);
		pthread_mutex_unlock(&vars->print);
		return (0);
	}
	pthread_mutex_unlock(&vars->someone_died);
	print_info(vars, philo);
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
}

void			eat(t_vars *vars, t_philo *philo)
{
	int	idx;

	idx = philo->philo_no - 1;
	pthread_mutex_lock(&vars->pickup);
	pthread_mutex_lock(&vars->fork[idx]);
	print_status(vars, philo, FORK_TAKEN);
	pthread_mutex_lock(&vars->fork[(idx + 1) % vars->n_philo]);
	print_status(vars, philo, FORK_TAKEN);
	pthread_mutex_unlock(&vars->pickup);
	philo->t_last_eat = get_time();
	print_status(vars, philo, EATING);
	ft_usleep(vars->t_eat);
	philo->n_eat += 1;
	pthread_mutex_unlock(&vars->fork[idx]);
	pthread_mutex_unlock(&vars->fork[(idx + 1) % vars->n_philo]);
}
