/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:02:02 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/07 18:02:04 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countn(int n)
{
	int	num;

	num = 0;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		n *= -1;
		num++;
	}
	while (n > 0)
	{
		n /= 10;
		num++;
	}
	return (num);
}

static char	*retrev(char *str, int n)
{
	char	*rev;
	int		i;

	i = 0;
	rev = (char *)malloc(sizeof(char) * (n + 1));
	if (!rev)
		return (NULL);
	n--;
	while (n >= 0)
	{
		rev[i] = str[n];
		i++;
		n--;
	}
	rev[i] = '\0';
	return (rev);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		temp;

	i = 0;
	temp = n;
	if (n == 0)
		return (ft_strdup("0\0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	if (!(res = (char *)malloc(sizeof(char) * (countn(n) + 1))))
		return (NULL);
	if (n < 0)
	{
		res[countn(n) - 1] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		res[i++] = n % 10 + '0';
		n /= 10;
	}
	res = retrev(res, countn(temp));
	return (res);
}
