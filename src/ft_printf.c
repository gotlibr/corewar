/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 22:50:44 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/18 00:59:16 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_n(size_t a, int base)
{
	int res;

	res = 0;
	while (a > 0)
	{
		a /= base;
		res++;
	}
	return (res);
}

void		itoa_cont(t_struct **list, int *plus, int *base)
{
	*base = 10;
	if ((*list)->cons == 'x' || (*list)->cons == 'X' || (*list)->cons == 'p')
		*base = 16;
	if ((*list)->cons == 'o' || (*list)->cons == 'O')
		*base = 8;
	if (*base == 16)
		*plus = (((*list)->cons) == 'x') ? 'a' - 10 : 'A' - 10;
}

char		*itoa_printf(size_t a, t_struct **list, int sym)
{
	char	*res;
	int		i;
	int		plus;
	int		base;

	itoa_cont(list, &plus, &base);
	res = (char *)ft_memalloc(sizeof(char) * count_n(a, base) + 1);
	if (a == 0 && ((*list)->prec == 0))
		return (f_strdup(""));
	if (a == 0)
	{
		free(res);
		res = ft_strdup("0");
	}
	i = count_n(a, base) - 1;
	while (i >= 0)
	{
		res[i] = a % base + '0';
		if (a % base > 9)
			res[i] = a % base + plus;
		a /= base;
		i--;
	}
	(*list)->sym = sym;
	return (res);
}

void		free_list(t_struct **list)
{
	free((*list)->content);
	free((*list)->mod);
	free((*list)->flags);
	free(*list);
}

int			ft_printf(char *format, ...)
{
	va_list				vl;
	t_struct			*list;
	t_struct			*head;
	int					res;

	g_null = 1;
	g_l = 0;
	res = 0;
	list = new_elem();
	head = list;
	if (!ft_strcmp("%", format))
		return (0);
	read_format(format, &list);
	list = head;
	get_mpwf(&list);
	list = head;
	va_start(vl, format);
	res = make_content(&list, vl);
	va_end(vl);
	return (res);
}
