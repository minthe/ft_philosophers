/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:47:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/17 13:35:54 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, long long time, char *str)
{
	pthread_mutex_lock(&philo->data->status);
	if (!philo->data->death)
		printf("%lld %d %s\n", time_passed(time), philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->status);
}

int	check_fork(t_philo *philo)
{
	bool	status;

	status = 0;
	pthread_mutex_lock(&philo->data->mutexes[philo->id]);
	if (philo->data->forks[philo->id])
		status = 1;
	pthread_mutex_unlock(&philo->data->mutexes[philo->id]);
	return (status);
}

int	check_left_fork(t_philo *philo)
{
	bool	status;

	status = 0;
	if (philo->id > 0)
	{
		pthread_mutex_lock(&philo->data->mutexes[philo->id - 1]);
		if (philo->data->forks[philo->id - 1])
			status = 1;
		pthread_mutex_unlock(&philo->data->mutexes[philo->id - 1]);
	}
	else if (philo->id == 0)
	{
		pthread_mutex_lock(&philo->data->mutexes[philo->data->nbr_philo - 1]);
		if (philo->data->forks[philo->data->nbr_philo - 1])
			status = 1;
		pthread_mutex_unlock(&philo->data->mutexes[philo->data->nbr_philo - 1]);
	}
	return (status);
}

void	handle_fork(t_philo *philo, bool action)
{
	pthread_mutex_lock(&philo->data->mutexes[philo->id]);
	philo->data->forks[philo->id] = action;
	pthread_mutex_unlock(&philo->data->mutexes[philo->id]);
}

void	handle_left_fork(t_philo *philo, bool action)
{
	if (philo->id > 0)
	{
		pthread_mutex_lock(&philo->data->mutexes[philo->id - 1]);
		philo->data->forks[philo->id - 1] = action;
		pthread_mutex_unlock(&philo->data->mutexes[philo->id - 1]);
	}
	else if (philo->id == 0)
	{
		pthread_mutex_lock(&philo->data->mutexes[philo->data->nbr_philo - 1]);
		philo->data->forks[philo->data->nbr_philo - 1] = action;
		pthread_mutex_unlock(&philo->data->mutexes[philo->data->nbr_philo - 1]);
	}
}
