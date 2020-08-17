/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpark <hpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:47:00 by hpark             #+#    #+#             */
/*   Updated: 2020/08/13 16:22:41 by hpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>

typedef struct	s_vars{
	int				n_philo;
	unsigned long	t_die;
	int				t_eat;
	int				t_sleep;
	int				n_must_eat;
	int				t_start;
	int				n_done;
	int				died;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*pickup;
	sem_t			*someone_died;
}				t_vars;

typedef struct	s_philo{
	int				n_eat;
	int				philo_no;
	pthread_t		philo;
	pthread_t		m_philo;
	unsigned long	t_last_eat;
	int				done;
}				t_philo;

typedef enum	e_status
{
	THINKING,
	EATING,
	SLEEPING,
	FORK_TAKEN,
	DIED
}				t_status;

int				print_status(t_vars *vars, t_philo *philo, t_status status);
unsigned long	get_time(void);
void			ft_usleep(unsigned long time);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
int				ft_error(char *str);
int				ft_atoi(const char *str);
int				create_philo(t_vars *vars);
t_vars			*get_vars(void);
void			eat(t_vars *vars, t_philo *philo);
int				free_philo(void *t, int ret);
#endif
