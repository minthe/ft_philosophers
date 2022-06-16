/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:07:13 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 15:49:14 by vfuhlenb         ###   ########.fr       */
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
		else if (ft_atoi(argv[i]) <= 0)
			return (printf \
			("\n** invalid input - please use natural numbers only **\n\n"));
		i++;
	}
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		return (printf("\n** invalid input **\n\n"));
	return (0);
}

// parses infos to struct of data
static t_data	parse_data(int argc, char *argv[])
{
	t_data			data;

	data.nbr_philo = ft_atoi(argv[1]);
	data.time_die = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.nbr_eat = ft_atoi(argv[5]);
	return (data);
}

static int	init_philo(t_philo *philo)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* philo->data->nbr_philo);
	if (mutex == NULL)
		return (1);
	i = 0;
	while (i < philo->data->nbr_philo)
	{
		philo[i].mutex = &mutex[i];
		if (pthread_mutex_init(philo[i].mutex, 0))
			return (free_all(NULL, philo, mutex));
		i++;
	}
	return (0);
}

// parses infos to struct of philos
static int	parse_philo(t_data *data, t_philo *philo)
{
	pthread_mutex_t	status;
	bool			*forks;
	int				i;

	forks = (bool *)malloc(sizeof(bool) \
		* data->nbr_philo);
	if (forks == NULL)
		return (1);
	i = 0;
	if (pthread_mutex_init(&status, 0))
		return (free_all(data, philo, &status));
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].full = 0;
		philo[i].fork = &forks[i];
		philo[i].data->status = status;
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
	philo = (t_philo *)malloc(sizeof(t_philo) * data.nbr_philo);
	if (philo == NULL)
		return (0);
	if (parse_philo(&data, philo))
		return (printf("\n** mutex failed **\n\n"));
	init_philo(philo);
	if (init_threads(philo))
		return (free_all (&data, philo, NULL));
	//manage_threads(philo);
	return (0);
}
