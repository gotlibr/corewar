/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:26:22 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/27 12:26:23 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 15
# include <fcntl.h>

int					get_next_line(const int fd, char **line);
typedef struct		s_str
{
	int				current_line;
	int				fd;
	char			*end;
	size_t			r;
	struct s_str	*next;
	char			*head;
}					t_str;

#endif
