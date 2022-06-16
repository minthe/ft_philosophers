/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:02:07 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 13:14:19 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// returns the current time
long long	time_current(void)
{
	struct timeval	time_store;
	long long		time;

	gettimeofday(&time_store, NULL);
	time = time_store.tv_sec * 1000 + time_store.tv_usec / 1000;
	return (time);
}

// returns the time passed since start in miliseconds
long long	time_passed(long long time)
{
	struct timeval	time_store;
	long long		time_offset;

	gettimeofday(&time_store, NULL);
	time_offset = (time_store.tv_sec * 1000 + time_store.tv_usec / 1000) - time;
	return (time_offset);
}
