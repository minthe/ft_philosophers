/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:48:45 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/03 17:52:08 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// fills string with Zeros
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// copies the character c to the first n characters of the string
// pointed to, by the argument str
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((char *)s)[counter] = c;
		counter++;
	}
	return (s);
}

// allocates the requested memory, sets it to zero and returns a pointer to it
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
