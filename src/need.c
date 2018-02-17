/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:25:48 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/29 20:25:50 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			make_content(t_struct **list, va_list vl)
{
	t_struct	*temp;

	while ((*list))
	{
		if ((*list)->cons == '0')
		{
			free((*list)->content);
			(*list)->content = (*list)->block;
		}
		else if (ft_strchr("DdioOuUxX", (*list)->cons))
			get_decimal(list, vl);
		else if ((*list)->cons == 'p')
			get_link(list, vl);
		else if (ft_strchr("sScC", (*list)->cons))
			get_str(list, vl);
		else
			dif_cons(list);
		g_l += print_list(list);
		temp = (*list)->next;
		free_list(list);
		*list = temp;
		g_l = (g_null == 0) ? g_l + 1 : g_l + 0;
		g_null = 1;
	}
	return (g_l);
}

t_struct	*new_elem(void)
{
	t_struct *str;

	if (!(str = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	str->block = NULL;
	str->block = f_strdup("");
	str->content = f_strdup("");
	str->next = NULL;
	str->m_w = 0;
	str->prec = -1;
	str->sym = 1;
	str->isp = 0;
	str->mod = f_strdup("");
	str->flags = f_strdup("");
	str->cons = '0';
	str->dop = 0;
	return (str);
}

void		read_format(char *format, t_struct **list)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			(*list)->block = free_charjoin(&(*list)->block, format[i]);
			i++;
		}
		while (format[i] != '\0' && format[i] != '%')
		{
			(*list)->block = free_charjoin(&(*list)->block, format[i]);
			i++;
		}
		if (format[i] != '\0')
		{
			(*list)->next = new_elem();
			(*list) = (*list)->next;
		}
	}
}

int			find_unic(t_struct *list)
{
	while (list)
	{
		if (list->cons == 'C' || list->cons == 'S' ||
				(list->cons == 'c' && ft_strchr((list->flags), 'l'))
					|| (list->cons == 's' && ft_strchr((list->flags), 'l')))
			return (1);
		list = list->next;
	}
	return (0);
}
