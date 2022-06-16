/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:02:19 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 17:11:35 by vfuhlenb         ###   ########.fr       */
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
		pthread_create(&thread[i], NULL, philo_cycle, philo + i);
		philo[i].thread = thread[i];
		philo[i].last_meal = time_current();
		i++;
	}
	return (0);
}

int	manage_threads(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->data->nbr_philo)
		{
			if (time_passed(philo[i].last_meal) > \
				(long long)philo->data->time_die)
			{
				
			}
		}
		if ()
	}
	pthread_mutex_destroy(&philo->data->status);
	return (0);
}
