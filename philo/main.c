/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:07:13 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/15 17:25:41 by vfuhlenb         ###   ########.fr       */
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
	data.start = time_current();
	return (data);
}

// parses infos to struct of philos
static int	parse_philo(t_data *data, t_philo *philo)
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	status;
	int				i;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* data->nbr_philo);
	if (mutex == NULL)
		return (1);
	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].fork = &mutex[i]; // correct?
		if (pthread_mutex_init(philo[i].fork, 0))
			return (free_all(NULL, philo, mutex));
		if (pthread_mutex_init(&status, 0))
			return (free_all(NULL, philo, mutex));
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
	init_threads(philo);
	manage_threads(philo);
	return (0);
}
