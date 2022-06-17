/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:13:15 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/17 17:30:27 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define TAKE 1
# define LEAVE 0

typedef struct s_data
{
	bool			death;
	int				full;
	int				n_ph;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_eat;
	long long		start;
	bool			*forks;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	status;
	pthread_mutex_t	print;
}					t_data;

typedef struct s_philo
{
	int				id;
	bool			full;
	int				meals;
	long long		last_meal;
	t_data			*data;
	pthread_t		thread;
}					t_philo;

/*
** utils
*/

int			check_char(const char *str);
int			ft_atoi(const char *str);
long long	time_current(void);
long long	time_passed(long long time);
int			free_all(t_data *data, t_philo *philo);

/*
** philo
*/

void		*philo_cycle(void *ptr);
void		init_threads(t_philo *philo);
void		manage_threads(t_philo *philo, t_data *data);
void		join_threads(t_philo *philo, t_data *data);

/*
** mutexes
*/

void		print_status(t_philo *philo, long long time, char *str);
int			take_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
void		return_fork(t_philo *philo);
void		return_left_fork(t_philo *philo);

#endif
