#include "philosophers.h"

void	init_vars(t_vars *vars, int argc, char **argv)
{
	vars->n_philo = ft_atoi(argv[1]);
	vars->t_die = ft_atoi(argv[2]);
	vars->t_eat = ft_atoi(argv[3]);
	vars->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars->n_must_eat = ft_atoi(argv[5]);
	else
		vars->n_must_eat = -1;
}

void	*philosophing(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		print_status(vars, philo, THINKING);
		if (!taken_fork_and_eat(vars, philo))
			break ;
		print_status(vars, philo, SLEEPING);
		ft_usleep(vars->t_sleep);
	}
}

int		create_philo(t_vars *vars)
{
	t_philo	*philo;
	int		i;

	if (!(philo = malloc(sizeof(t_philo) * vars->n_philo)))
		return (0);
	i = 0;
	while (i < vars->n_philo)
	{
		philo->t_last_eat = get_time();
		if (pthread_create(&(philo[i].philo), 0, &philosophing, &philo[i])
			return (ft_error("Error: cannot create pthread"));
		if (pthread_detach(philo[i].philo))
			return (ft_error("Error: cannot detach pthread"));
		if (pthread_create(&(philo[i].m_philo), 0, &monitering, &philo[i])
			return (ft_error("Error: cannot create pthread"));
		if (pthread_detach(philo[i].m_philo))
			return (ft_error("Error: cannot detach pthread"));
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_vars	vars;

	init(&vars, argc, argv);
	if (!create_philo(vars))
		return (0);
}