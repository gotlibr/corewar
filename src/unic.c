/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unic.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:34:11 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/21 18:34:14 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_unic_l(unsigned int i)
{
	int				res;
	unsigned int	mask;

	res = 0;
	mask = 2147483648;
	while ((mask & i) == 0)
	{
		mask = mask >> 1;
		res++;
	}
	return (32 - res);
}

size_t	mas(unsigned int i, t_struct **list, int counter)
{
	(*list)->content[counter] = (char)i;
	return (1);
}

size_t	mask(unsigned int i, t_struct **list, int counter)
{
	unsigned int r;
	unsigned int m;
	unsigned int temp;

	m = 49280;
	temp = i << 26;
	temp = temp >> 26;
	r = temp;
	i = i >> 6;
	r = r | (i << 8);
	r = r | m;
	(*list)->content[counter] = r >> 8;
	r = r << 24;
	(*list)->content[counter + 1] = r >> 24;
	return (2);
}

size_t	maskk(unsigned int i, t_struct **list, int counter)
{
	unsigned int r;
	unsigned int m;
	unsigned int temp;

	m = 14712960;
	temp = i >> 12;
	r = temp << 16;
	temp = i << 20;
	temp = temp >> 26;
	r = r | (temp << 8);
	i = i << 26;
	r = r | (i >> 26);
	r = r | m;
	(*list)->content[counter] = r >> 16;
	r = r << 16;
	r = r >> 16;
	(*list)->content[counter + 1] = r >> 8;
	r = r << 24;
	(*list)->content[counter + 2] = r >> 24;
	return (3);
}

size_t	maskkk(unsigned int i, t_struct **list, int counter)
{
	unsigned int r;
	unsigned int m;

	m = 4034953344;
	r = (i << 26) >> 26;
	r = r | (((i << 20) >> 26) << 8) |
			(((i << 14) >> 26) << 16) | ((i >> 18) << 24) | m;
	(*list)->content[counter] = (r >> 24);
	(*list)->content[counter + 1] = (r << 8) >> 24;
	(*list)->content[counter + 2] = (r << 16) >> 24;
	(*list)->content[counter + 3] = (r << 24) >> 24;
	return (4);
}
