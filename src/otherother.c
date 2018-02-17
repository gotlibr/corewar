/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otherother.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:36:39 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/29 14:36:41 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	continue_fl(t_struct **list)
{
	if ((*list)->m_w > ft_strlen((*list)->content))
		create_mw(list);
	else if ((*list)->sym < 0)
		(*list)->content = free_join(f_strdup("-"), (*list)->content);
	if ((ft_strchr((*list)->mod, '+')) && (*list)->sym > 0
			&& ft_strchr("diD", (*list)->cons))
		put_plus(list);
	if ((ft_strchr((*list)->mod, ' ')) && (*list)->sym > 0
			&& ft_strchr("diD", (*list)->cons) && (*list)->content[0] != '+')
		put_space(list);
}

void	set_flags(t_struct **list)
{
	char c;

	c = (*list)->cons;
	((*list)->prec == -1 && ft_strlen((*list)->content)) ?
		((*list)->prec = 0) : 1;
	if (ft_strchr((*list)->mod, '#') && (c == 'o' || c == 'O')
			&& (*list)->prec <= (int)ft_strlen((*list)->content) &&
				ft_strcmp("0", (*list)->content))
		(*list)->content = free_join(f_strdup("0"), (*list)->content);
	if ((*list)->prec > (int)ft_strlen((*list)->content))
		create_zs((*list)->prec - ft_strlen((*list)->content), list, '0');
	(*list)->dop = (*list)->m_w - ft_strlen((*list)->content);
	if (ft_strchr((*list)->mod, '#') && ((c == 'x' &&
			ft_strcmp("0", (*list)->content) &&
				ft_strlen((*list)->content)) || (*list)->isp))
		(*list)->content = free_join(f_strdup("0x"), (*list)->content);
	if (ft_strchr((*list)->mod, '#') && c == 'X' &&
			ft_strcmp("0", (*list)->content) && ft_strlen((*list)->content))
		(*list)->content = free_join(f_strdup("0X"), (*list)->content);
	continue_fl(list);
}

size_t	get_unic_s(wint_t i, t_struct **list, int counter)
{
	int				a;
	unsigned int	b;
	int				c;

	c = (*list)->prec;
	b = (unsigned int)i;
	if (b == 0)
	{
		g_null = 0;
		return (0);
	}
	a = get_unic_l((unsigned int)i);
	if (MB_CUR_MAX == 1)
		return (((counter + 1 > c && c > 0)) ? 0 : mas(b, list, counter));
	else if (a > 16 && MB_CUR_MAX == 4)
		return ((counter + 4 > c && c > 0) ? 0 : maskkk(b, list, counter));
	else if ((a > 11 && a <= 16 && MB_CUR_MAX >= 3))
		return ((counter + 3 > c && c > 0) ? 0 : maskk(b, list, counter));
	else if ((a <= 11 && a > 7 && MB_CUR_MAX >= 2))
		return ((counter + 2 > c && c > 0) ? 0 : mask(b, list, counter));
	else if (a <= 7)
		return ((counter + 1 > c && c > 0) ? 0 : mas(i, list, counter));
	return (0);
}
