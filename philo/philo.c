/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:18 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/17 17:34:29 by vfuhlenb         ###   ########.fr       */
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

static int	getting_forks(t_philo *philo)
{
	if (take_fork(philo) == LEAVE)
		return (1);
	print_status(philo, philo->data->start, "has taken right fork");
	if (philo->data->n_ph == 1)
		return (1);
	if (take_left_fork(philo) == LEAVE && take_fork(philo) == TAKE)
	{
		pthread_mutex_lock(&philo->data->mutexes[philo->id]);
		philo->data->forks[philo->id] = LEAVE;
		pthread_mutex_unlock(&philo->data->mutexes[philo->id]);
		return (1);
	}
	print_status(philo, philo->data->start, "has taken left fork");
	return (0);
}

static void	philo_eating(t_philo *philo)
{
	print_status(philo, philo->data->start, "is eating");
	philo->meals++;
	pthread_mutex_lock(&philo->data->status);
	philo->last_meal = time_current();
	pthread_mutex_unlock(&philo->data->status);
	vf_usleep(philo->data->time_eat);
	return_fork(philo);
	print_status(philo, philo->data->start, "returned right fork");
	return_left_fork(philo);
	print_status(philo, philo->data->start, "returned left fork");
	print_status(philo, philo->data->start, "is sleeping");
	vf_usleep(philo->data->time_sleep);
	print_status(philo, philo->data->start, "is thinking");
}

static int	philo_check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->status);
	if ((philo->data->nbr_eat && philo->meals == philo->data->nbr_eat)
		|| philo->data->death)
	{
		philo->data->full++;
		pthread_mutex_unlock(&philo->data->status);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->status);
	return (0);
}

void	*philo_cycle(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_eat * 1000);
	while (1)
	{
		if (philo_check_status(philo))
			return (0);
		if (getting_forks(philo) == 0)
			philo_eating(philo);
	}
	return (0);
}
