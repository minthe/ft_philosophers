/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:07:13 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/14 20:57:49 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// checks the input and if valid fills the data struct
static int	check_input(int argc, char *argv[])
{
	int	i;

	if (argc < 5 || argc > 6)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (check_char(argv[i]) == -1)
		{
			printf("Invalid characters.\n");
			return (1);
		}
		else if (ft_atoi(argv[i]) <= 0)
		{
			printf("Invalid input. Please use Natural Numbers.\n");
			return (1);
		}
		i++;
	}
	if (argc == 6 && ft_atoi(argv[5]) == 0)
	{
		printf("Invalid input.\n");
		return (1);
	}
	return (0);
}

// parses infos to struct of data
static t_data	parse_data(int argc, char *argv[])
{
	t_data	data;

	data.nbr_philo = ft_atoi(argv[1]);
	data.time_die = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.nbr_eat = ft_atoi(argv[5]);
	return (data);
}

// parses infos to struct of philos
static void	parse_philo(t_data *data, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_philo		*philo;

	if (check_input(argc, argv))
		return (0);
	data = parse_data(argc, argv);
	philo = (t_philo *)malloc(sizeof(t_philo) * data.nbr_philo);
	if (philo == NULL)
		return (0);
	parse_philo(&data, philo);
	printf("Test: %d\n", philo[0].id); // debugging
	return (0);
}
