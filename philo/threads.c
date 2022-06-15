/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:02:19 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/15 18:28:41 by vfuhlenb         ###   ########.fr       */
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
	while (i < philo->data->nbr_philo)
	{
		pthread_create(&thread[i], NULL, philo_cycle, philo + i);
		philo[i].thread = thread[i];
		if (i % 2 == 0)
			usleep(10);
		if (i % 3 == 0)
			usleep(20);
		if (i % 5 == 0)
			usleep(30);
		i++;
	}
	return (0);
}

int	manage_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_philo)
	{
		pthread_mutex_destroy(&philo->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->data->status);
	if (free_all(NULL, philo, philo->fork))
		return (printf("\n** mutex failed **\n\n"));
	return (0);
}
