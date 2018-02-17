/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 00:39:30 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/21 00:39:38 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_link(t_struct **list, va_list vl)
{
	size_t s;

	(*list)->mod = free_join((*list)->mod, f_strdup("#"));
	(*list)->cons = 'x';
	free((*list)->flags);
	(*list)->flags = f_strdup("l");
	(*list)->isp = 1;
	s = va_arg(vl, unsigned long);
	free((*list)->content);
	(*list)->content = itoa_printf(s, (list), 1);
}

void	continue_str(t_struct **list, va_list vl, char *c, char **s)
{
	if (*c == 's')
	{
		if (!(*s = va_arg(vl, char *)))
		{
			free((*list)->content);
			(*list)->content = f_strdup("(null)");
			if ((*list)->prec == 0)
			{
				free((*list)->content);
				(*list)->content = f_strdup("");
			}
			if ((*list)->prec != -1)
				create_mw(list);
			return ;
		}
		sht(*s, list);
	}
	if (*c == 'c')
	{
		g_null = (char)va_arg(vl, int);
		(*list)->content = free_charjoin(&(*list)->content, g_null);
	}
}

void	dif_cons(t_struct **list)
{
	(*list)->content = free_charjoin(&(*list)->content, (*list)->cons);
	if ((*list)->m_w > ft_strlen((*list)->content))
		create_mw(list);
}

void	test_null(t_struct **list)
{
	char s;

	if ((*list)->m_w > ft_strlen((*list)->content) + 1)
	{
		if (ft_strchr((*list)->mod, '-'))
		{
			write(1, &g_null, 1);
			s = (ft_strchr((*list)->mod, '0')) ? '0' : ' ';
			create_zs((*list)->m_w - ft_strlen((*list)->content) - 1, list, s);
			write(1, (*list)->content, ft_strlen((*list)->content));
			g_l += ft_strlen((*list)->content);
			(*list)->content = f_strdup("");
		}
		else
		{
			s = (ft_strchr((*list)->mod, '0')) ? '0' : ' ';
			create_zs((*list)->m_w - ft_strlen((*list)->content) - 1, list, s);
			write(1, (*list)->content, ft_strlen((*list)->content));
			g_l += ft_strlen((*list)->content);
			(*list)->content = f_strdup("");
			write(1, &g_null, 1);
		}
	}
	else
		write(1, &g_null, 1);
}

void	clean_content(t_struct **list)
{
	t_struct *temp;

	while (*list)
	{
		temp = (*list)->next;
		free((*list)->block);
		free_list(list);
		(*list) = temp;
	}
}
