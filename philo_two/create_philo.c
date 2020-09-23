/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:47:15 by hpark             #+#    #+#             */
/*   Updated: 2020/08/19 14:59:56 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosophing(void *p)
{
	t_philo	*philo;
	t_vars	*vars;

	vars = get_vars();
	philo = (t_philo *)p;
	while (vars->died == 0 && philo->n_eat != vars->n_must_eat)
	{
		// print_status(vars, philo, THINKING);
		eat(vars, philo);
		if (philo->n_eat == vars->n_must_eat)
		{
			philo->done += 1;
			vars->n_done += 1;
			break ;
		}
		print_status(vars, philo, SLEEPING);
		ft_usleep(vars->t_sleep);
		print_status(vars, philo, THINKING);
	}
	return (0);
}

void	*monitoring(void *p)
{
	t_philo	*philo;
	t_vars	*vars;

	vars = get_vars();
	philo = (t_philo *)p;
	while (philo->done == 0 && vars->died == 0)
	{
		if ((get_time() - philo->t_last_eat) > vars->t_die \
		&& vars->died == 0 && vars->n_done != vars->n_philo)
		{
			print_status(vars, philo, DIED);
			break ;
		}
		// ft_usleep(1);
		usleep(400);
	}
	return (0);
}

int		create_philo(t_vars *vars)
{
	t_philo	*philo;
	int		i;

	i = 0;
	if (!(philo = malloc(sizeof(t_philo) * vars->n_philo)))
		return (1);
	vars->t_start = get_time();
	i = 0;
	while (i < vars->n_philo)
	{
		philo[i].philo_no = i + 1;
		philo[i].t_last_eat = vars->t_start;
		philo[i].n_eat = 0;
		philo[i].done = 0;
		if (pthread_create(&(philo[i].philo), 0, &philosophing, &philo[i]))
			return (ft_error("Error: cannot create pthread"));
		if (pthread_detach(philo[i].philo))
			return (ft_error("Error: cannot detach pthread"));
		if (pthread_create(&(philo[i].m_philo), 0, &monitoring, &philo[i]))
			return (ft_error("Error: cannot create pthread"));
		if (pthread_detach(philo[i].m_philo))
			return (ft_error("Error: cannot detach pthread"));
		i++;
	}
	return (free_philo(philo, 0));
}
