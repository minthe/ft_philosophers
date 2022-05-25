/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:07:13 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/25 17:38:07 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*myTurn(t_data *data)
{
	while(1)
	{
		data->death = 2;
		sleep(1);
		printf("My Turn!\n");
		
	}
	return (NULL);
}

void	*yourTurn(t_data *data)
{
	while(1)
	{
		data->death = 1;
		sleep(1);
		printf("Your Turn!\n");
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	thread1;
	pthread_t	thread2;
	t_data		data;

	data.death = 0;
	pthread_create(&thread1, NULL, (void*)myTurn, (void *)&data);
	pthread_create(&thread2, NULL, (void*)yourTurn, (void *)&data);
	pthread_join(thread2, NULL);
	return (0);
}
