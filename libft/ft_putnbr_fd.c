/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:42:56 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/03 15:44:11 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cas(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		return (1);
	}
	return (0);
}

void			ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c;

	i = 10;
	if (cas(n, fd) == 0)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		while (n / i >= 1)
			i *= 10;
		i /= 10;
		while (i > 0)
		{
			c = (n / i) + 48;
			n -= (n / i) * i;
			i /= 10;
			write(fd, &c, 1);
		}
	}
}
