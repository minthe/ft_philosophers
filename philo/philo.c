/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:18 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/15 22:34:51 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, long long time, char *str)
{
	(void)time;
	pthread_mutex_lock(&philo->data->status);
	printf("%lldms	%d %s\n", philo->data->start, philo->id, str);
	pthread_mutex_unlock(&philo->data->status);
}

static int	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork[philo->id - 1]);
	print_status(philo, philo->data->start, "has taken the left fork");
	pthread_mutex_lock(&philo->fork[philo->id]);
	print_status(philo, philo->data->start, "has taken his fork");
	print_status(philo, philo->data->start, "is eating");
	philo->meals++;
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->fork[philo->id]);
	pthread_mutex_unlock(&philo->fork[philo->id - 1]);
	return (0);
}

static int	philo_sleeping(t_philo *philo)
{
	print_status(philo, philo->data->start, "is sleeping");
	usleep(philo->data->time_sleep * 1000);
	return (0);
}

void	*philo_cycle(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		philo_eating(philo);
		philo_sleeping(philo);
		print_status(philo, philo->data->start, "is thinking");
	}
	return (0);
}
