/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:02:19 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 20:46:48 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_philo *philo)
{
	int			i;
	pthread_t	*thread;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * philo->data->nbr_philo);
	if (thread == NULL)
		return (1);
	i = 0;
	philo->data->start = time_current();
	while (i < philo->data->nbr_philo)
	{
		philo[i].thread = thread[i];
		philo[i].last_meal = time_current();
		pthread_create(&thread[i], NULL, philo_cycle, philo + i);
		i++;
	}
	return (0);
}

int	manage_threads(t_philo *philo, t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		usleep(100);
		while (i < data->nbr_philo)
		{
			pthread_mutex_lock(&data->status);
			if (time_passed(philo[i].last_meal) > \
				(long long)data->time_die)
			{
				pthread_mutex_unlock(&data->status);
				print_status(&philo[i], data->start, "died");
				return (0);
			}
			pthread_mutex_unlock(&data->status);
		}
		pthread_mutex_lock(&data->status);
		if (data->full == data->nbr_philo)
		{
			pthread_mutex_unlock(&data->status);
			break ;
		}
		pthread_mutex_unlock(&data->status);
	}
	return (0);
}
