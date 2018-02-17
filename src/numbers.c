/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 01:10:53 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/18 01:10:55 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	shorten(t_struct **list)
{
	int		pr;
	char	*st;

	st = f_strdup((*list)->content);
	pr = ((int)(*list)->m_w > (*list)->prec) ? (*list)->m_w : (*list)->prec;
	free((*list)->content);
	(*list)->content = (char *)ft_memalloc(sizeof(char) * ft_strlen(st) + 1);
	ft_memcpy((*list)->content, st, pr);
	free(st);
}

void	create_mw_min(t_struct **list)
{
	int i;

	i = 0;
	if (ft_strchr((*list)->mod, '0') && ((*list)->prec == 0)
			&& !ft_strchr((*list)->mod, '-'))
		create_zs((*list)->m_w - ft_strlen((*list)->content), list, '0');
	else
		create_zs((*list)->m_w - ft_strlen((*list)->content), list, ' ');
	if (ft_strchr((*list)->mod, '0') && (*list)->prec == 0
			&& (*list)->content[0] == '0')
		(*list)->content[0] = '-';
	else if ((*list)->content[0] == ' ')
	{
		while ((*list)->content[i] == ' ')
			i++;
		(*list)->content[i - 1] = '-';
	}
	else
		(*list)->content = free_join(f_strdup("-"), (*list)->content);
	shorten(list);
}

void	sharp_mw(t_struct **list)
{
	if (ft_strchr((*list)->mod, '0') && ((*list)->prec == 0)
			&& !ft_strchr((*list)->mod, '-'))
	{
		create_zs((*list)->m_w - ft_strlen((*list)->content), list, '0');
		((*list)->cons == 'x') ?
			((*list)->content[ft_strchr((*list)->content, 'x') -
				(*list)->content] = '0') :
					((*list)->content[ft_strchr((*list)->content, 'X') -
						(*list)->content] = '0');
		((*list)->cons == 'x') ? ((*list)->content[1] = 'x') :
			((*list)->content[1] = 'X');
	}
	else
		create_zs((*list)->m_w - ft_strlen((*list)->content), list, ' ');
}

void	create_mw(t_struct **list)
{
	if (ft_strchr((*list)->mod, '#'))
		sharp_mw(list);
	else if ((*list)->sym > 0)
	{
		if (ft_strchr((*list)->mod, '0') && !ft_strchr((*list)->mod, '-') &&
				((*list)->prec == 0))
			create_zs((*list)->m_w - ft_strlen((*list)->content), list, '0');
		else
			create_zs((*list)->m_w - ft_strlen((*list)->content), list, ' ');
	}
	else
		create_mw_min(list);
}

void	create_zs(size_t a, t_struct **list, char c)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)ft_memalloc(sizeof(char) * a + 1);
	while (i < a)
		res[i++] = c;
	if (c == '0')
		(*list)->content = free_join(f_strdup(res), (*list)->content);
	else
	{
		if (ft_strchr((*list)->mod, '-'))
			(*list)->content = free_join((*list)->content, f_strdup(res));
		else
			(*list)->content = free_join(ft_strdup(res), (*list)->content);
	}
	free(res);
}
