/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:18 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/15 21:26:49 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, long long time, char *str)
{
	pthread_mutex_lock(&philo->data->status);
	printf("%lldms	%d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->status);
}

static int	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork[philo->id - 1]);
	print_status(philo, philo->data->start, "has taken a fork");
	if (philo->id == 6)
		usleep(350);
	print_status(philo, philo->data->start, "is eating");
	return (0);
}

// eating

// sleeping

void	*philo_cycle(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo_eating(philo);
	// while (1)
	// {
	// 	philo_eating(philo);
	// }
	return (0);
}
