/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:02:19 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/17 17:32:40 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_philo *philo)
{
	int	i;

	i = 0;
	philo->data->start = time_current();
	while (i < philo->data->n_ph)
	{
		philo[i].last_meal = time_current();
		pthread_create(&(philo[i].thread), NULL, philo_cycle, philo + i);
		i++;
	}
}

static int	check_if_full(t_data *data)
{
	pthread_mutex_lock(&data->status);
	if (data->full == data->n_ph)
	{
		pthread_mutex_unlock(&data->status);
		return (1);
	}
	pthread_mutex_unlock(&data->status);
	return (0);
}

void	manage_threads(t_philo *philo, t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->n_ph)
		{
			pthread_mutex_lock(&data->print);
			pthread_mutex_lock(&data->status);
			if (time_passed(philo[i].last_meal) > (long long)data->time_die)
			{
				data->death = 1;
				printf("%lld %d died\n", time_passed(data->start), \
				philo[i].id + 1);
				pthread_mutex_unlock(&data->status);
				return ;
			}
			pthread_mutex_unlock(&data->status);
			pthread_mutex_unlock(&data->print);
			i++;
		}
		if (check_if_full(data))
			return ;
	}
}

void	join_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_ph)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->n_ph)
	{
		pthread_mutex_destroy(&data->mutexes[i]);
		i++;
	}
	pthread_mutex_destroy(&data->status);
	pthread_mutex_destroy(&data->print);
}
