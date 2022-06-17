/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:47:00 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/17 17:30:43 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, long long time, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	if (!philo->data->death)
		printf("%lld %d %s\n", time_passed(time), philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	return_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutexes[philo->id]);
	philo->data->forks[philo->id] = LEAVE;
	pthread_mutex_unlock(&philo->data->mutexes[philo->id]);
}

void	return_left_fork(t_philo *philo)
{
	if (philo->id > 0)
	{
		pthread_mutex_lock(&philo->data->mutexes[philo->id - 1]);
		philo->data->forks[philo->id - 1] = LEAVE;
		pthread_mutex_unlock(&philo->data->mutexes[philo->id - 1]);
	}
	else if (philo->id == 0)
	{
		pthread_mutex_lock(&philo->data->mutexes[philo->data->n_ph - 1]);
		philo->data->forks[philo->data->n_ph - 1] = LEAVE;
		pthread_mutex_unlock(&philo->data->mutexes[philo->data->n_ph - 1]);
	}
}

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutexes[philo->id]);
	if (philo->data->forks[philo->id] == 0)
	{
		philo->data->forks[philo->id] = TAKE;
		pthread_mutex_unlock(&philo->data->mutexes[philo->id]);
		return (TAKE);
	}
	pthread_mutex_unlock(&philo->data->mutexes[philo->id]);
	return (LEAVE);
}

int	take_left_fork(t_philo *philo)
{
	if (philo->id > 0)
	{
		pthread_mutex_lock(&philo->data->mutexes[philo->id - 1]);
		if (philo->data->forks[philo->id - 1] == 0)
		{
			philo->data->forks[philo->id - 1] = TAKE;
			pthread_mutex_unlock(&philo->data->mutexes[philo->id - 1]);
			return (TAKE);
		}
		pthread_mutex_unlock(&philo->data->mutexes[philo->id - 1]);
	}
	else if (philo->id == 0)
	{
		pthread_mutex_lock(&philo->data->mutexes[philo->data->n_ph - 1]);
		if (!philo->data->forks[philo->data->n_ph - 1])
		{
			philo->data->forks[philo->data->n_ph - 1] = TAKE;
			pthread_mutex_unlock(&philo->data->mutexes[philo->data->n_ph - 1]);
			return (TAKE);
		}
		pthread_mutex_unlock(&philo->data->mutexes[philo->data->n_ph - 1]);
	}
	return (LEAVE);
}
