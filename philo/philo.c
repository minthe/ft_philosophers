/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:18 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/15 17:16:33 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_philo *philo)
{
	printf("Philo Nr: %d\n", philo->id);
	return (0);
}

// eating

// sleeping

void	*philo_cycle(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	eating(philo);
	return (0);
}
