/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:07:13 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/25 16:29:43 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*myTurn(void *arg)
{
	while(1)
	{
		sleep(1);
		printf("My Turn!\n");
	}
	return (NULL);
}

void	*yourTurn(void *arg)
{
	while(1)
	{
		sleep(3);
		printf("Your Turn!\n");
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	thread1;
	pthread_t	thread2;

	while(1)
	{
	pthread_create(&thread1, NULL, myTurn, NULL);
	pthread_create(&thread1, NULL, yourTurn, NULL);
	}
	return (0);
}
