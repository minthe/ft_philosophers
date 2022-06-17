/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:18 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/17 13:57:23 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	vf_usleep(long long time_need_sleep)
{
	long long	start_time;

	start_time = time_current();
	while (1)
	{
		if (time_passed(start_time) >= time_need_sleep)
			break ;
		usleep(10);
	}
}

static int	philo_eating(t_philo *philo)
{
	vf_usleep(200);
	handle_fork(philo, TAKE);
	print_status(philo, philo->data->start, "has taken his fork");
	if (philo->data->nbr_philo == 1)
		return (1);
	handle_left_fork(philo, TAKE);
	print_status(philo, philo->data->start, "has taken the left fork");
	print_status(philo, philo->data->start, "is eating");
	philo->meals++;
	pthread_mutex_lock(&philo->data->status);
	philo->last_meal = time_current();
	pthread_mutex_unlock(&philo->data->status);
	vf_usleep(philo->data->time_eat);
	handle_fork(philo, LEAVE);
	print_status(philo, philo->data->start, "returned his fork");
	handle_left_fork(philo, LEAVE);
	print_status(philo, philo->data->start, "returned the left fork");
	return (0);
}

static int	philo_sleeping(t_philo *philo)
{
	print_status(philo, philo->data->start, "is sleeping");
	vf_usleep(philo->data->time_sleep);
	return (0);
}

void	*philo_cycle(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (!check_left_fork(philo) && !check_fork(philo))
		{
			if (philo_eating(philo))
				break ;
			pthread_mutex_lock(&philo->data->status);
			if ((philo->data->nbr_eat && philo->meals == philo->data->nbr_eat)
				|| philo->data->death)
			{
				philo->data->full++;
				pthread_mutex_unlock(&philo->data->status);
				break ;
			}
			pthread_mutex_unlock(&philo->data->status);
			philo_sleeping(philo);
			print_status(philo, philo->data->start, "is thinking");
		}
	}
	return (0);
}
