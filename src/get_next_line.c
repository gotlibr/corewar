/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:26:13 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/27 12:26:16 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

t_str			*newstr(int fd)
{
	t_str *str;

	if (!(str = (t_str *)malloc(sizeof(t_str))))
		return (NULL);
	str->current_line = 0;
	str->fd = fd;
	str->end = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	str->head = str->end;
	str->r = read(str->fd, str->end, BUFF_SIZE);
	str->next = NULL;
	return (str);
}

char			*fr_join(char **line, char **end)
{
	char *temp;

	temp = ft_strjoin(*line, *end);
	free(*line);
	return (temp);
}

int				find_sub(t_str *desc, char **line)
{
	if (!desc->r)
		return (0);
	while (1)
	{
		if (ft_strchr(desc->end, '\n'))
		{
			(desc->end)[ft_strchr(desc->end, '\n') - desc->end] = '\0';
			*line = fr_join(line, &(desc->end));
			desc->end = ft_strchr(desc->end, '\0') + 1;
			return (1);
		}
		else if (ft_strchr(desc->end, '\0') != desc->end)
			*line = fr_join(line, &(desc->end));
		desc->end = desc->head;
		ft_bzero(desc->end, BUFF_SIZE * sizeof(char));
		desc->r = read(desc->fd, desc->end, BUFF_SIZE);
		if (desc->r == 0 && ft_strlen(*line) == 0)
			return (0);
		else if (desc->r == 0)
			return (1);
	}
}

t_str			*find_n_check(t_str **str, int fd)
{
	t_str *head;
	t_str *temp;

	if (!(*str))
	{
		*str = newstr(fd);
		return (*str);
	}
	head = *str;
	while (*str)
	{
		if ((*str)->fd == fd)
		{
			temp = *str;
			*str = head;
			return (temp);
		}
		*str = (*str)->next;
	}
	temp = newstr(fd);
	temp->next = head;
	*str = temp;
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_str		*fdlist;
	t_str				*desc;
	char				t;

	t = '0';
	if (read(fd, &t, 0) != 0 || BUFF_SIZE <= 0)
		return (-1);
	desc = find_n_check(&fdlist, fd);
	*line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE);
	return (find_sub(desc, line));
}
