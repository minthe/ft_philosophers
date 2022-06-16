/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:13:15 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 11:48:00 by vfuhlenb         ###   ########.fr       */
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

typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;

typedef struct s_data
{
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_eat;
	long long		start;
	pthread_mutex_t	status;
}					t_data;

typedef struct s_philo
{
	int				id;
	bool			full;
	bool			right_fork;
	bool			*left_fork;
	int				meals;
	long long		last_meal;
	t_data			*data;
	pthread_mutex_t	mfork;
	pthread_mutex_t	mfull;
	pthread_mutex_t	mlast_meal;
	pthread_t		thread;
}					t_philo;

/*
** utils
*/

int			check_char(const char *str);
int			ft_atoi(const char *str);
long long	time_current(void);
long long	time_passed(long long time);
int			free_all(t_data *data, t_philo *philo, pthread_mutex_t *mutex);

/*
** philo
*/

void		*philo_cycle(void *ptr);
int			init_threads(t_philo *philo);
int			manage_threads(t_philo *philo);
int			init_data(t_data *data);
int			init_philo(t_data *data);

#endif
