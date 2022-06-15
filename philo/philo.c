/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:18 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/15 21:09:15 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork[philo->id - 1]);
	pthread_mutex_lock(&philo->data->status);
	printf("%lldms    %d has taken a fork\n", \
		time_passed(philo->data->start), philo->id);
	pthread_mutex_unlock(&philo->data->status);
	pthread_mutex_lock(&philo->data->status);
	printf("%lldms    %d is eating\n", \
		time_passed(philo->data->start), philo->id);
	pthread_mutex_unlock(&philo->data->status);
	return (0);
}

// eating

// sleeping

void	*philo_cycle(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		philo_eating(philo);
	}
	return (0);
}
