#include "philosophers.h"

t_vars	*get_vars(void)
{
	static t_vars vars;

	return (&vars);
}

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
	// vars->n_eat = 0;
	pthread_mutex_init(&vars->print, 0);
	pthread_mutex_init(&vars->pickup, 0);
	pthread_mutex_init(&vars->putdown, 0);
	pthread_mutex_init(&vars->someone_died, 0);
	//fork 만들기 
	int i = 0;
	vars->fork = malloc(sizeof(pthread_mutex_t) * vars->n_philo);
	while (i < vars->n_philo)
	{
		pthread_mutex_init(&vars->fork[i], 0);
		i++;
	}
	vars->n_done = 0;
	vars->died = 0;
	// pthread_mutex_init(vars->fork, 0);
}

int		eat(t_vars *vars, t_philo *philo)
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
	// philo->t_last_eat = get_time();
	// pthread_mutex_lock(&vars->putdown);
	pthread_mutex_unlock(&vars->fork[idx]);
	pthread_mutex_unlock(&vars->fork[(idx + 1) % vars->n_philo]);
	// pthread_mutex_unlock(&vars->putdown);
	return (1);
}

void	*philosophing(void *p)
{
	t_philo	*philo;
	t_vars	*vars;

	vars = get_vars();
	philo = (t_philo *)p;
	while (1)
	{
		pthread_mutex_lock(&vars->someone_died);
		if (vars->died == 1)
		{
			pthread_mutex_unlock(&vars->someone_died);
			break ;
		}
		pthread_mutex_unlock(&vars->someone_died);
		print_status(vars, philo, THINKING);
		eat(vars, philo);
		if (philo->n_eat == vars->n_must_eat)
		{
			vars->n_done += 1;
			break;
		}
		print_status(vars, philo, SLEEPING);
	 	ft_usleep(vars->t_sleep);
	}
}

void	*monitoring(void *p)
{
	t_philo	*philo;
	t_vars	*vars;

	vars = get_vars();
	philo = (t_philo *)p;
	while (1)
	{
		// if (philo->n_eat == vars->n_must_eat)
		// 	break ;
		//먹은시간으로부터 현재시간이 time to die 보다 작은지 체크
		pthread_mutex_lock(&vars->someone_died);
		if ((get_time() - philo->t_last_eat) > vars->t_die && vars-> died == 0 && vars->n_done != vars->n_philo)
		{
			vars->died = 1;
			pthread_mutex_unlock(&vars->someone_died);
			print_status(vars, philo, DIED);
			break ;
		}
		pthread_mutex_unlock(&vars->someone_died);
		ft_usleep(5);
	}
}

int		create_philo_even(t_vars *vars,t_philo *philo)
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
	return (1);
}

int		create_philo_odd(t_vars *vars,t_philo *philo)
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
	return (1);
}


int		create_philo(t_vars *vars)
{
	t_philo	*philo;
	int		i;

	if (!(philo = malloc(sizeof(t_philo) * vars->n_philo)))
		return (0);
	vars->t_start = get_time();
	create_philo_odd(vars, philo);
	create_philo_even(vars, philo);
	// i = 0;
	// while (i < vars->n_philo)
	// {
	// 	philo[i].philo_no = i + 1;
	// 	philo[i].t_last_eat = get_time();
	// 	philo[i].n_eat = 0;
	// 	if (pthread_create(&(philo[i].philo), 0, &philosophing, &philo[i]))
	// 		return (ft_error("Error: cannot create pthread"));
	// 	if (pthread_detach(philo[i].philo))
	// 		return (ft_error("Error: cannot detach pthread"));
	// 	if (pthread_create(&(philo[i].m_philo), 0, &monitoring, &philo[i]))
	// 		return (ft_error("Error: cannot create pthread"));
	// 	if (pthread_detach(philo[i].m_philo))
	// 		return (ft_error("Error: cannot detach pthread"));
	// 	i++;
	// }
}

int		main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 5 && argc != 6)
		return (1);
	vars = get_vars();
	init_vars(vars, argc, argv);
	if (!create_philo(vars))
		return (0);
	while (1)
	{
		// ft_putstr("n_done: ");
		// ft_putnbr(vars->n_done);
		if (vars->n_done == vars->n_philo)
		{
			pthread_mutex_lock(&vars->print);
			ft_putstr("Every philosopher ate enough!\n");
			pthread_mutex_unlock(&vars->print);
			return (0);
		}
		pthread_mutex_lock(&vars->someone_died);
		if (vars->died == 1)
		{
			return (0);
		}
		pthread_mutex_unlock(&vars->someone_died);
		ft_usleep(5);
	}
}