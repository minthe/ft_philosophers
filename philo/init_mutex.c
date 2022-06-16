/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:23:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 11:51:10 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data)
{
	if (pthread_mutex_init(&data->status, NULL))
		return (free_all(data, NULL, NULL));
	return (0);
}

int	init_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_philo)
	{
		if (pthread_mutex_init(&philo[i].mfork, NULL))
			return (free_all(NULL, philo, NULL));
		if (pthread_mutex_init(&philo[i].mfull, NULL))
			return (free_all(NULL, philo, NULL));
		if (pthread_mutex_init(&philo[i].mlast_meal, NULL))
			return (free_all(NULL, philo, NULL));
		i++;
	}
	return (0);
}
