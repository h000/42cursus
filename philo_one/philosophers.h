#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

typedef struct	s_vars{
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_must_eat;
	pthread_mutext_t	*fork;
}				t_vars;

typedef struct	s_philo{
	pthread_t	philo;
	pthread_t	m_philo;
	int			t_last_eat;
}				t_philo


#endif