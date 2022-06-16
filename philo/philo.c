/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:18 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 16:22:31 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eating(t_philo *philo)
{
	handle_fork(philo, TAKE);
	print_status(philo, philo->data->start, "has taken his fork");
	handle_left_fork(philo, TAKE);
	print_status(philo, philo->data->start, "has taken the left fork");
	print_status(philo, philo->data->start, "is eating");
	philo->meals++;
	usleep(philo->data->time_eat * 1000);
	handle_fork(philo, LEAVE);
	print_status(philo, philo->data->start, "returned his fork");
	handle_left_fork(philo, LEAVE);
	print_status(philo, philo->data->start, "returned the left fork");
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
	if (philo->id % 2 == 0)
		usleep(10);
	while (1)
	{
		if (!check_left_fork(philo) && !check_fork(philo))
		{
			philo_eating(philo);
			philo_sleeping(philo);
			print_status(philo, philo->data->start, "is thinking");
		}
	}
	return (0);
}
