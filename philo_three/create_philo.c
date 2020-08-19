/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:47:15 by hpark             #+#    #+#             */
/*   Updated: 2020/08/19 16:18:13 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitoring(void *p)
{
	t_philo	*philo;
	t_vars	*vars;

	vars = get_vars();
	philo = (t_philo *)p;
	while (1)
	{
		if ((get_time() - philo->t_last_eat) > vars->t_die)
		{
			ft_putnbr(get_time() - philo->t_last_eat);
			ft_putstr(" is the time\n");
			ft_putnbr(vars->t_die);
			ft_putstr(" is the time to die\n");
			ft_putnbr((get_time() - philo->t_last_eat) > vars->t_die);
			ft_putstr(" is the differnce between two");
			vars->died = 1;
			print_status(vars, philo, DIED);
			break ;
		}
		ft_usleep(5);
	}
	// ft_putstr("2");
	return (0);
}

void	*philosophing(void *p)
{
	t_philo	*philo;
	t_vars	*vars;

	vars = get_vars();
	philo = (t_philo *)p;
	if (pthread_create(&philo->m_philo, 0, &monitoring, philo))
		exit(ft_error("Error: cannot create pthread"));
	if (pthread_detach((philo->m_philo)))
		exit(ft_error("Error: cannot create pthread"));
	while (vars->died == 0)
	{
		print_status(vars, philo, THINKING);
		eat(vars, philo);
		if (philo->n_eat == vars->n_must_eat)
			exit(0);
		print_status(vars, philo, SLEEPING);
		ft_usleep(vars->t_sleep);
	}
	exit(2);
}

void	wait_philo(t_vars *vars, t_philo *philo)
{
	int		i;
	int		status;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
		{
			i = 0;
			while (i < vars->n_philo)
			{
				ft_putstr("killing...");
				kill(philo[i++].philo, SIGINT);
			}
			return ;
		}
		else if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
			return ;
	}
	ft_putstr("Every philosopher ate enough\n");
	return ;
}

int		create_philo(t_vars *vars)
{
	t_philo	*philo;
	int		i;

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
		if ((philo[i].philo = fork()) == -1)
			return (ft_error("Error: cannot fork"));
		else if (philo[i].philo == 0)
		{
			philosophing(&philo[i]);
		}
		i++;
	}
	wait_philo(vars, philo);
	return (0);
}
