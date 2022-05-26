/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:13:15 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/26 18:13:29 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_data
{
	int				death;
	pthread_mutex_t	mutex1;
	pthread_mutex_t	mutex2;
	struct timeval	start;
	struct timeval	end;
} t_data;

#endif
