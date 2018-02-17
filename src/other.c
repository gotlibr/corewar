/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:17:37 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/29 14:17:39 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*free_charjoin(char **line, char end)
{
	char *temp;
	char *t;

	t = (char *)ft_memalloc(sizeof(char) * 2);
	t[0] = end;
	temp = ft_strjoin(*line, t);
	free(*line);
	free(t);
	return (temp);
}

char	*free_join(char *line, char *end)
{
	char *temp;

	temp = ft_strjoin(line, end);
	free(line);
	free(end);
	return (temp);
}

int		get_w(char *format, t_struct **list)
{
	int counter;

	counter = 0;
	if (format[0] == '0' && format[-1] != '.')
	{
		(*list)->mod = free_charjoin(&(*list)->mod, '0');
		return (0);
	}
	(*list)->m_w = ft_atoi(format);
	while (ft_isdigit(format[counter]))
		counter++;
	if (format[counter] != '.')
		return (counter - 1);
	counter++;
	(*list)->prec = ft_atoi(format + counter);
	while (ft_isdigit(format[counter]))
		counter++;
	return (counter - 1);
}

void	get_decimal(t_struct **list, va_list vl)
{
	long long	l;
	char		c;
	char		*fl;

	if (ft_strchr("DOU", (*list)->cons))
	{
		(*list)->cons += 32;
		free((*list)->flags);
		if (!ft_strcmp("", (*list)->flags))
			(*list)->flags = f_strdup("l");
		else
			(*list)->flags = f_strdup("ll");
	}
	c = (*list)->cons;
	fl = (*list)->flags;
	(c == 'i') ? (c = 'd') : 1;
	(c == 'd' && !ft_strcmp("", fl)) ? l = (int)va_arg(vl, int) : 1;
	(c == 'd' && !ft_strcmp("hh", fl)) ? l = (signed char)va_arg(vl, int) : 1;
	(c == 'd' && !ft_strcmp("h", fl)) ? l = (short)va_arg(vl, int) : 1;
	(c == 'd' && !ft_strcmp("l", fl)) ? l = va_arg(vl, long) : 1;
	(c == 'd' && !ft_strcmp("ll", fl)) ? l = va_arg(vl, long long) : 1;
	(c == 'd' && !ft_strcmp("j", fl)) ? l = va_arg(vl, intmax_t) : 1;
	(c == 'd' && !ft_strcmp("z", fl)) ? l = va_arg(vl, size_t) : 1;
	getd(list, c, l, vl);
}

void	getd(t_struct **list, char c, long long l, va_list vl)
{
	char	*fl;
	size_t	s;

	fl = (*list)->flags;
	s = 0;
	(c != 'd' && !ft_strcmp("", fl)) ? s = va_arg(vl, unsigned int) : 1;
	(c != 'd' && !ft_strcmp("hh", fl)) ? s = (unsigned char)va_arg(vl, int) : 1;
	(c != 'd' && !ft_strcmp("h", fl)) ? s = (unsigned short)va_arg(vl, int) : 1;
	(c != 'd' && !ft_strcmp("l", fl)) ? s = va_arg(vl, unsigned long) : 1;
	(c != 'd' && !ft_strcmp("ll", fl)) ? s = va_arg(vl, unsigned long long) : 1;
	(c != 'd' && !ft_strcmp("j", fl)) ? s = va_arg(vl, uintmax_t) : 1;
	(c != 'd' && !ft_strcmp("z", fl)) ? s = va_arg(vl, size_t) : 1;
	free((*list)->content);
	if (c == 'd' && l < 0)
		((*list)->content = itoa_printf(-1 * l, (list), -1));
	else if (c == 'd' && l >= 0)
		((*list)->content = itoa_printf(l, (list), 1));
	else if (c != 'd')
		((*list)->content = itoa_printf(s, (list), 1));
}
