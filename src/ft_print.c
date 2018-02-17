/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 22:50:13 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/17 22:50:29 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_f(char *format, t_struct **list)
{
	int counter;

	counter = 0;
	while (ft_strchr("hljz", format[counter]))
		(*list)->flags = free_charjoin(&(*list)->flags, format[counter++]);
	return (counter - 1);
}

char	*f_strdup(char *src)
{
	char	*copy;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	while (src[counter] != '\0')
	{
		counter++;
	}
	copy = malloc(sizeof(char) * (counter + 1));
	if (!copy)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		get_mpwf_cont(t_struct **list, int i)
{
	t_struct	*temp;

	while (!(ft_strchr("sSpdDioOuUxXcC", (*list)->block[++i])))
	{
		if (ft_isdigit((*list)->block[i]) || (*list)->block[i] == '.')
			i += get_w(&(*list)->block[i], list);
		else if (ft_strchr("#0-+ ", (*list)->block[i]))
			(*list)->mod = free_charjoin(&(*list)->mod, (*list)->block[i]);
		else if (ft_strchr("hljz", (*list)->block[i]))
			i += get_f(&(*list)->block[i], list);
		else
			break ;
	}
	(*list)->cons = (*list)->block[i];
	if ((*list)->cons == '\0')
	{
		(*list)->cons = '%';
		(*list)->block = free_join((*list)->block, (*list)->next->block);
		temp = (*list)->next->next;
		free_list(&(*list)->next);
		(*list)->next = temp;
	}
	return (i);
}

void	get_mpwf(t_struct **list)
{
	int			i;
	char		*buf;

	while (*list)
	{
		i = 0;
		if ((*list)->block[i] != '%')
		{
			free((*list)->content);
			(*list)->content = f_strdup((*list)->block);
		}
		else
		{
			i = get_mpwf_cont(list, i);
			buf = f_strdup(&((*list)->block[i + 1]));
			free((*list)->block);
			(*list)->block = buf;
		}
		(*list) = (*list)->next;
	}
}

int		print_list(t_struct **list)
{
	int		i;

	i = 0;
	if ((*list)->cons == '0')
	{
		if ((*list)->block)
			write(1, (*list)->block, ft_strlen((*list)->block));
		i += ft_strlen((*list)->block);
		return (i);
	}
	ft_strchr("diDoOuUxX", (*list)->cons) ? set_flags(list) : 1;
	if (MB_CUR_MAX == 1 && ((*list)->cons == 'C' ||
			((*list)->cons == 'c' && ft_strchr((*list)->flags, 'l'))))
		write(1, (*list)->content, 1);
	else if ((*list)->content)
		write(1, (*list)->content, ft_strlen((*list)->content));
	i += ft_strlen((*list)->content);
	if ((*list)->block)
		write(1, (*list)->block, ft_strlen((*list)->block));
	i += ft_strlen((*list)->block);
	if ((*list)->block)
		free((*list)->block);
	return (i);
}
