/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:07:13 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/03 15:50:59 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse_infos(t_data *data, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_char(argv[i]) == -1)
			return (-1);
		else if (ft_atoi(argv[i]) < 0)
			return (-1);
		i++;
	}
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		return (-1);
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_eat = ft_atoi(argv[5]);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		data;

	data.nbr_eat = ft_atoi(argv[5]);
	if (argc != 5 && argc != 6)
		return (1);
	if (parse_infos(&data, argc, argv) == -1)
	{
		printf ("Input Error\n");
		return (1);
	}
	return (0);
}
