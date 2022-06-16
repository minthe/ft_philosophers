/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:13:15 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 22:41:48 by vfuhlenb         ###   ########.fr       */
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
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_eat;
	long long		start;
	bool			*forks;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	status;
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
int			check_fork(t_philo *philo);
int			check_left_fork(t_philo *philo);
void		handle_fork(t_philo *philo, bool action);
void		handle_left_fork(t_philo *philo, bool action);

#endif
