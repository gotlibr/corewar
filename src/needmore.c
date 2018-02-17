/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needmore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:29:09 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/29 20:29:38 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sht(char *st, t_struct **list)
{
	int pr;

	pr = ((*list)->prec == -1) ? ft_strlen(st) : (*list)->prec;
	free((*list)->content);
	(*list)->content = (char *)ft_memalloc(sizeof(char) * ft_strlen(st) + 1);
	ft_memcpy((*list)->content, st, pr);
}

void	get_str(t_struct **list, va_list vl)
{
	char c;
	char *s;

	c = (*list)->cons;
	if ((c == 's' || c == 'c') && !ft_strcmp((*list)->flags, ""))
		continue_str(list, vl, &c, &s);
	else if ((c == 'S' || (c == 's' && ft_strchr(((*list)->flags), 'l')))
				&& (*list)->prec != 0)
		get_unic_str(va_arg(vl, wchar_t *), list);
	else if (c == 'C' || (c == 'c' && ft_strchr(((*list)->flags), 'l')))
		get_unic_s(va_arg(vl, wint_t), list, 0);
	((*list)->prec == -1) ? ((*list)->prec = 0) : 1;
	if (g_null == 0)
		test_null(list);
	else if ((*list)->m_w > ft_strlen((*list)->content))
		create_mw(list);
}

void	get_unic_str(wchar_t *str, t_struct **list)
{
	int i;
	int counter;
	int temp;

	i = 0;
	counter = 0;
	free((*list)->content);
	if (str == NULL)
	{
		(*list)->content = ft_strdup("(null)");
		return ;
	}
	while (str[i])
		i++;
	(*list)->content = (char *)ft_memalloc(sizeof(char) * (i * MB_CUR_MAX) + 1);
	i = 0;
	while (str[i])
	{
		temp = get_unic_s(str[i], list, counter);
		if (temp > 0)
			counter += temp;
		else
			break ;
		i++;
	}
}

void	put_plus(t_struct **list)
{
	int i;

	i = 0;
	if ((*list)->content[0] == '0' && (*list)->dop > 0 &&
			ft_strchr((*list)->mod, '0')
				&& !ft_strchr((*list)->mod, '-'))
		(*list)->content[0] = '+';
	else if ((*list)->content[0] == ' ')
	{
		while ((*list)->content[i] == ' ')
			i++;
		(*list)->content[i - 1] = '+';
	}
	else
		(*list)->content = free_join(f_strdup("+"), (*list)->content);
	if (!ft_strchr((*list)->mod, '0') && ft_strchr((*list)->mod, '-') &&
			(*list)->dop > 0)
		(*list)->content[ft_strlen((*list)->content) - 1] = '\0';
}

void	put_space(t_struct **list)
{
	int i;

	i = 0;
	if ((*list)->content[0] == '0' && (*list)->dop > 0 &&
			ft_strchr((*list)->mod, '0')
				&& !ft_strchr((*list)->mod, '-'))
		(*list)->content[0] = ' ';
	else if ((*list)->content[0] == ' ')
	{
		while ((*list)->content[i] == ' ')
			i++;
		(*list)->content[i - 1] = ' ';
	}
	else
		(*list)->content = free_join(f_strdup(" "), (*list)->content);
	if (!ft_strchr((*list)->mod, '0') && ft_strchr((*list)->mod, '-') &&
			(*list)->dop > 0)
		(*list)->content[ft_strlen((*list)->content) - 1] = '\0';
}
