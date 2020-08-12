/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:47:25 by hpark             #+#    #+#             */
/*   Updated: 2020/08/12 13:47:26 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_vars	*get_vars(void)
{
	static t_vars vars;

	return (&vars);
}

int		free_philo(void *t, int ret)
{
	if (t)
	{
		free(t);
		t = 0;
	}
	return (ret);
}

int		free_vars(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->n_philo)
		pthread_mutex_destroy(&vars->fork[i++]);
	pthread_mutex_destroy(&vars->print);
	pthread_mutex_destroy(&vars->pickup);
	pthread_mutex_destroy(&vars->someone_died);
	free(vars->fork);
	free(vars);
	return (0);
}

void	init_vars(t_vars *vars, int argc, char **argv)
{
	int	i;

	vars->n_philo = ft_atoi(argv[1]);
	vars->t_die = ft_atoi(argv[2]);
	vars->t_eat = ft_atoi(argv[3]);
	vars->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars->n_must_eat = ft_atoi(argv[5]);
	else
		vars->n_must_eat = -1;
	pthread_mutex_init(&vars->print, 0);
	pthread_mutex_init(&vars->pickup, 0);
	pthread_mutex_init(&vars->someone_died, 0);
	i = 0;
	vars->fork = malloc(sizeof(pthread_mutex_t) * vars->n_philo);
	while (i < vars->n_philo)
	{
		pthread_mutex_init(&vars->fork[i], 0);
		i++;
	}
	if (vars->n_must_eat == 0)
		vars->n_done = vars->n_philo;
	else
		vars->n_done = 0;
	vars->died = 0;
}

int		main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 5 && argc != 6)
		return (ft_error("Error: Wrong Number of Arguments\n"));
	vars = get_vars();
	init_vars(vars, argc, argv);
	if (create_philo(vars))
		return (free_vars(vars));
	while (1)
	{
		if (vars->n_done == vars->n_philo)
		{
			pthread_mutex_lock(&vars->print);
			ft_putstr("Every philosopher ate enough!\n");
			pthread_mutex_unlock(&vars->print);
			return (free_vars(vars));
		}
		pthread_mutex_lock(&vars->someone_died);
		if (vars->died == 1)
			return (free_vars(vars));
		pthread_mutex_unlock(&vars->someone_died);
		ft_usleep(5);
	}
}
