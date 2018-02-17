/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:24:33 by mkoniev           #+#    #+#             */
/*   Updated: 2018/02/05 17:24:37 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
	int				start;
	int				l;
	int				ant;
	int				visited;
	struct s_link	*links;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	t_room			*link;
	struct s_link	*next;
}					t_link;

typedef struct		s_ants
{
	int				num;
	struct s_room	*loc;
	struct s_ants	*next;
}					t_ants;
int					g_ants;
int					g_count;
t_room				*g_end;
t_room				*g_start;
void				get_rooms();
void				get_links(t_room *rooms, char *str);
void				err();
t_room				*get_tab(t_room *tab, char *name);
t_room				*room(char *name, int x, int y);
int					count_ind(char *name);
t_link				*new_link(t_room *tab);
int		get_n_print(int fd, char **temp);
void free_dp(char ***str);
#endif
