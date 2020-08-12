/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:47:15 by hpark             #+#    #+#             */
/*   Updated: 2020/08/12 17:59:48 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosophing(void *p)
{
	t_philo	*philo;
	t_vars	*vars;

	vars = get_vars();
	philo = (t_philo *)p;
	while (vars->n_done != vars->n_philo)
	{
		if ((sem_wait(vars->someone_died) == -1))
			ft_error("Error: sem_wait\n");
		if (vars->died == 1)
		{
			if ((sem_post(vars->someone_died) == -1))
				ft_error("Error: sem_post%%%%%\n");
			break ;
		}
		if ((sem_post(vars->someone_died) == -1))
			ft_error("Error: sem_post^^^^^\n");
		print_status(vars, philo, THINKING);
		eat(vars, philo);
		if (philo->n_eat == vars->n_must_eat)
		{
			vars->n_done += 1;
			break ;
		}
		print_status(vars, philo, SLEEPING);
		ft_usleep(vars->t_sleep);
	}
	return (0);
}

void	*monitoring(void *p)
{
	t_philo	*philo;
	t_vars	*vars;

	vars = get_vars();
	philo = (t_philo *)p;
	while (vars->n_done != vars->n_philo)
	{
		if ((sem_wait(vars->someone_died) == -1))
			ft_error("Error: sem_wait\n");
		if ((get_time() - philo->t_last_eat) > vars->t_die \
		&& vars->died == 0 && vars->n_done != vars->n_philo)
		{
			vars->died = 1;
			if ((sem_post(vars->someone_died) == -1))
				ft_error("Error: sem_post######\n");
			print_status(vars, philo, DIED);
			break ;
		}
		ft_putstr("1");
		if ((sem_post(vars->someone_died) == -1))
			ft_error("Error: sem_post$$$$$$$\n");
		ft_usleep(2000);
	}
	ft_putstr("2");
	return (0);
}
int		create_philo_even(t_vars *vars, t_philo *philo)
{
	int i;
	int j;

	i = 0;
	while ((j = 2 * i) < vars->n_philo)
	{
		philo[j].philo_no = j + 1;
		philo[j].t_last_eat = get_time();
		philo[j].n_eat = 0;
		if (pthread_create(&(philo[j].philo), 0, &philosophing, &philo[j]))
			return (ft_error("Error: cannot create pthread"));
		if (pthread_detach(philo[j].philo))
			return (ft_error("Error: cannot detach pthread"));
		if (pthread_create(&(philo[j].m_philo), 0, &monitoring, &philo[j]))
			return (ft_error("Error: cannot create pthread"));
		if (pthread_detach(philo[j].m_philo))
			return (ft_error("Error: cannot detach pthread"));
		i++;
	}
	return (0);
}

int		create_philo_odd(t_vars *vars, t_philo *philo)
{
	int i;
	int j;

	i = 0;
	while ((j = 2 * i + 1) < vars->n_philo)
	{
		philo[j].philo_no = j + 1;
		philo[j].t_last_eat = get_time();
		philo[j].n_eat = 0;
		if (pthread_create(&(philo[j].philo), 0, &philosophing, &philo[j]))
			return (ft_error("Error: cannot create pthread"));
		if (pthread_detach(philo[j].philo))
			return (ft_error("Error: cannot detach pthread"));
		if (pthread_create(&(philo[j].m_philo), 0, &monitoring, &philo[j]))
			return (ft_error("Error: cannot create pthread"));
		if (pthread_detach(philo[j].m_philo))
			return (ft_error("Error: cannot detach pthread"));
		i++;
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
	// if (create_philo_odd(vars, philo))
	// 	return (free_philo(philo, 1));
	// if (create_philo_even(vars, philo))
	// 	return (free_philo(philo, 1));
	i = 0;
	while (i < vars->n_philo)
	{
		philo[i].philo_no = i + 1;
		philo[i].t_last_eat = get_time();
		philo[i].n_eat = 0;
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
