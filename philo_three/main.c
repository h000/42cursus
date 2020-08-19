/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:47:25 by hpark             #+#    #+#             */
/*   Updated: 2020/08/19 17:21:31 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_shm(void)
{
	sem_unlink("/fork");
	sem_unlink("/pickup");
	sem_unlink("/print");
	sem_unlink("/someone_died");
}

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
	// ft_putstr("in free vars!!!\n");
	(void)vars;
	sem_close(vars->fork);
	sem_close(vars->pickup);
	sem_close(vars->print);
	sem_close(vars->someone_died);
	// ft_putstr("in free vars2!!!\n");
	clean_shm();
	// ft_putstr("in free vars3!!!\n");
	return (0);
}

int		init_vars(t_vars *vars, int argc, char **argv)
{
	clean_shm();
	vars->n_philo = ft_atoi(argv[1]);
	vars->t_die = ft_atoi(argv[2]);
	vars->t_eat = ft_atoi(argv[3]);
	vars->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars->n_must_eat = ft_atoi(argv[5]);
	else
		vars->n_must_eat = -1;
	if ((vars->fork = sem_open("/fork", O_CREAT, 0660, vars->n_philo)) == SEM_FAILED)
		return (1);
	if ((vars->print = sem_open("/print", O_CREAT, 0660, 1)) == SEM_FAILED)
		return (1);
	if ((vars->pickup = sem_open("/pickup", O_CREAT, 0660, 1)) == SEM_FAILED)
		return (1);
	if ((vars->someone_died = sem_open("/someone_died", O_CREAT, 0660, 1)) == SEM_FAILED)
		return (1);
	if (vars->n_must_eat == 0)
		vars->n_done = vars->n_philo;
	else
		vars->n_done = 0;
	vars->died = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 5 && argc != 6)
		return (ft_error("Error: Wrong Number of Arguments\n"));
	vars = get_vars();
	if (init_vars(vars, argc, argv))
		return (ft_error("Error: sem_open\n"));
	if (create_philo(vars))
		return (free_vars(vars));
	clean_shm();
	return (0);
	// while (1)
	// {
	// 	// ft_putstr("111");
	// 	if (vars->n_done == vars->n_philo)
	// 	{
	// 		if ((sem_wait(vars->print) == -1))
	// 			ft_error("Error: sem_wait\n");
	// 		ft_putstr("Every philosopher ate enough!\n");
	// 		if ((sem_post(vars->print) == -1))
	// 			ft_error("Error: sem_post\n");
	// 		return (free_vars(vars));
	// 	}
	// 	if ((sem_wait(vars->someone_died) == -1))
	// 		ft_error("Error: sem_wait\n");
	// 	if (vars->died == 1)
	// 	{
	// 		if ((sem_post(vars->someone_died) == -1))
	// 			ft_error("Error: sem_post\n");
	// 		// if ((sem_wait(vars->print) == -1))
	// 		// 	ft_error("Error: sem_wait\n");
	// 		clean_shm();
	// 		return (0);
	// 	}
	// 	if ((sem_post(vars->someone_died) == -1))
	// 		ft_error("Error: sem_post\n");
	// 		// ft_putstr("111");
	// 	ft_usleep(5);
	// 	// ft_putstr("111");
	// }
}
