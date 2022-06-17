/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:07:13 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/17 16:52:09 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// checks the input and if valid fills the data struct
static int	check_input(int argc, char *argv[])
{
	int	i;

	if (argc < 5 || argc > 6)
		return (printf("\n** incorrect numbers of parameters **\n\n"));
	i = 1;
	while (i < argc)
	{
		if (check_char(argv[i]) == -1)
			return (printf("\n** invalid characters **\n\n"));
		else if (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) > 100000)
			return (printf \
			("\n** invalid input - please use valid numbers only **\n\n"));
		i++;
	}
	return (0);
}

// parses infos to struct of data
static t_data	parse_data(int argc, char *argv[])
{
	t_data			data;

	data.forks = NULL;
	data.mutexes = NULL;
	data.n_ph = ft_atoi(argv[1]);
	data.time_die = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.full = 0;
	data.time_sleep = ft_atoi(argv[4]);
	data.nbr_eat = 0;
	if (argc == 6)
		data.nbr_eat = ft_atoi(argv[5]);
	return (data);
}

static int	init_mutex(t_data *data, t_philo *philo)
{
	int	i;

	data->mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* data->n_ph);
	if (data->mutexes == NULL)
		return (free_all(data, philo));
	i = 0;
	while (i < data->n_ph)
	{
		if (pthread_mutex_init(&data->mutexes[i], 0))
			return (free_all(data, philo));
		i++;
	}
	return (0);
}

// parses infos to struct of philos
static int	parse_philo(t_data *data, t_philo *philo)
{
	int	i;

	data->forks = (bool *)malloc(sizeof(bool) \
		* data->n_ph);
	if (data->forks == NULL)
		return (free_all(data, philo));
	i = 0;
	if (pthread_mutex_init(&data->status, 0))
		return (free_all(data, philo));
	while (i < data->n_ph)
	{
		philo[i].id = i;
		philo[i].data = data;
		data->forks[i] = LEAVE;
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_philo		*philo;

	if (check_input(argc, argv))
		return (0);
	data = parse_data(argc, argv);
	philo = (t_philo *)malloc(sizeof(t_philo) * data.n_ph);
	if (philo == NULL)
		return (printf("\n** philo failed **\n\n"));
	if (parse_philo(&data, philo) || init_mutex(&data, philo))
		return (printf("\n** mutex failed **\n\n"));
	init_threads(philo);
	manage_threads(philo, &data);
	join_threads(philo, &data);
	free_all(&data, philo);
	return (0);
}
