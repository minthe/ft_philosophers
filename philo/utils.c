/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:11:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/16 20:04:33 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// checks if character is a digit
static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

// checks if character is a space
static int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == ' '))
		return (1);
	else
		return (0);
}

// takes a string and converts it into an integer
int	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str)
	{
		ret = (ret * 10) + (*str - '0');
		str++;
	}
	return (ret * sign);
}

// checks if string is composed only of digits, otherwise -1 returned
int	check_char(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	return (0);
}

int	free_all(t_data *data, t_philo *philo, pthread_mutex_t *mutex)
{
	if (mutex)
		free(mutex);
	if (philo)
		free(philo);
	if (data)
		free(data);
	return (1);
}
