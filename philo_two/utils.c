/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:47:29 by hpark             #+#    #+#             */
/*   Updated: 2020/08/19 17:23:53 by hpark            ###   ########.fr       */
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
	int				philo_no;
	unsigned long	time;

	philo_no = philo->philo_no;
	time = get_time() - vars->t_start;
	ft_putnbr(time);
	ft_putstr(" ");
	ft_putnbr(philo_no);
}

int				print_status(t_vars *vars, t_philo *philo, t_status status)
{
	if ((sem_wait(vars->print) == -1))
		ft_error("Error: sem_wait\n");
	if ((sem_wait(vars->someone_died) == -1))
		ft_error("Error: sem_wait\n");
	if (vars->died == 1)
	{
		if ((sem_post(vars->someone_died) == -1))
				ft_error("Error: sem_post\n");
		if ((sem_post(vars->print) == -1))
				ft_error("Error: sem_post\n");
		return (0);
	}
	// if ((sem_post(vars->someone_died) == -1))
	// 	ft_error("Error: sem_post(((\n");
	print_info(vars, philo);
	if (status == THINKING)
		ft_putstr(" is thinking\n");
	else if (status == EATING)
		ft_putstr(" is eating\n");
	else if (status == SLEEPING)
		ft_putstr(" is sleeping\n");
	else if (status == DIED)
	{
		ft_putstr(" died\n");
		vars->died = 1;
	}
	else if (status == FORK_TAKEN)
		ft_putstr(" has taken a fork\n");
	if ((sem_post(vars->someone_died) == -1))
		ft_error("Error: sem_post(((\n");
	if ((sem_post(vars->print) == -1))
		ft_error("Error: sem_post\n");
	return (0);
}

void			eat(t_vars *vars, t_philo *philo)
{
	if ((sem_wait(vars->pickup) == -1))
		ft_error("Error: sem_wait\n");
	if ((sem_wait(vars->fork) == -1))
		ft_error("Error: sem_wait\n");
	print_status(vars, philo, FORK_TAKEN);
	if ((sem_wait(vars->fork) == -1))
		ft_error("Error: sem_wait\n");
	print_status(vars, philo, FORK_TAKEN);
	if ((sem_post(vars->pickup) == -1))
		ft_error("Error: sem_post\n");
	philo->t_last_eat = get_time();
	print_status(vars, philo, EATING);
	ft_usleep(vars->t_eat);
	philo->n_eat += 1;
	if ((sem_post(vars->fork) == -1))
		ft_error("Error: sem_post\n");
	if ((sem_post(vars->fork) == -1))
		ft_error("Error: sem_post\n");
}
