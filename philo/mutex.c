/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:47:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 14:47:19 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, long long time, char *str)
{
	pthread_mutex_lock(&philo->data->status);
	printf("%lldms	%d %s\n", time_passed(time), philo->id, str);
	pthread_mutex_unlock(&philo->data->status);
}

int	check_fork(t_philo *philo)
{
	bool	status;

	status = 0;
	pthread_mutex_lock(&philo->mutex[philo->id]);
	if (philo->fork[philo->id])
		status = 1;
	pthread_mutex_unlock(&philo->mutex[philo->id]);
	return (status);
}

int	check_left_fork(t_philo *philo)
{
	bool	status;

	status = 0;
	if (philo->id > 1)
	{
		pthread_mutex_lock(&philo->mutex[philo->id - 1]);
		if (philo->fork[philo->id - 1])
			status = 1;
		pthread_mutex_unlock(&philo->mutex[philo->id - 1]);
	}
	else if (philo->id < 2)
	{
		pthread_mutex_lock(&philo->mutex[philo->data->nbr_philo]);
		if (philo->fork[philo->data->nbr_philo])
			status = 1;
		pthread_mutex_unlock(&philo->mutex[philo->data->nbr_philo]);
	}
	return (status);
}

float	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex[philo->id]);
	philo->fork[philo->id] = 0;
	pthread_mutex_unlock(&philo->mutex[philo->id]);
}

float	take_left_fork(t_philo *philo)
{
	if (philo->id > 1)
	{
		pthread_mutex_lock(&philo->mutex[philo->id - 1]);
		philo->fork[philo->id - 1] = 0;
		pthread_mutex_unlock(&philo->mutex[philo->id - 1]);
	}
	else if (philo->id < 2)
	{
		pthread_mutex_lock(&philo->mutex[philo->data->nbr_philo]);
		philo->fork[philo->data->nbr_philo] = 0;
		pthread_mutex_unlock(&philo->mutex[philo->data->nbr_philo]);
	}
}
