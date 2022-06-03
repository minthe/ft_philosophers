/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:58:24 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/03 17:16:38 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// prints character
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// prints string to specified fd
void	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	if (!s)
		return ;
	counter = 0;
	while (s[counter])
	{
		ft_putchar_fd(s[counter], fd);
		counter++;
	}
}

// prints string to specified fd and prints a new line
void	ft_putendl_fd(char *s, int fd)
{
	int	counter;

	if (!s)
		return ;
	counter = 0;
	while (s[counter])
	{
		ft_putchar_fd(s[counter], fd);
		counter++;
	}
	write(fd, "\n", 1);
}

// prints integer to specified fd
void	ft_putnbr_fd(int n, int fd)
{
	int	temp;

	temp = n;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (temp < 0)
	{
		ft_putchar_fd('-', fd);
		temp *= -1;
	}
	if (temp < 10)
		ft_putchar_fd(temp + '0', fd);
	else
	{
		ft_putnbr_fd(temp / 10, fd);
		ft_putnbr_fd(temp % 10, fd);
	}
}
