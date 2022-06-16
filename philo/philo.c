/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:18 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 14:46:58 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_eating(t_philo *philo)
{
	if ((!check_fork(philo)) && (!check_left_fork(philo)))
	{
		take_fork(philo);
		print_status(philo, philo->data->start, "has taken his fork");
		take_left_fork(philo);
		print_status(philo, philo->data->start, "has taken the left fork");
		print_status(philo, philo->data->start, "is eating");
		philo->meals++;
		usleep(philo->data->time_eat * 1000);
	}
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
