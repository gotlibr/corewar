/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 22:50:58 by mkoniev           #+#    #+#             */
/*   Updated: 2018/01/17 22:51:01 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include <stdio.h>
# include <locale.h>

int					ft_printf(char *format, ...);
typedef struct		s_struct
{
	char			*block;
	int				sym;
	char			*content;
	char			*mod;
	char			*flags;
	char			cons;
	size_t			m_w;
	int				prec;
	struct s_struct	*next;
	int				isp;
	int				dop;
}					t_struct;
char				g_null;
int					g_l;
char				*free_join(char *line, char *end);
void				read_format(char *format, t_struct **list);
t_struct			*new_elem(void);
int					print_list(t_struct **list);
void				get_mpwf(t_struct **list);
int					get_f(char *format, t_struct **list);
char				*free_charjoin(char **line, char end);
int					get_w(char *format, t_struct **list);
int					make_content(t_struct **list, va_list vl);
void				get_decimal(t_struct **list, va_list vl);
char				*itoa_printf(size_t a, t_struct **list, int sym);
void				set_flags(t_struct **list);
void				create_zs(size_t a, t_struct **list, char c);
void				get_link(t_struct **list, va_list vl);
void				get_str(t_struct **list, va_list vl);
size_t				get_unic_s(wint_t i, t_struct **list, int counter);
int					get_unic_l(unsigned int i);
size_t				mask(unsigned int i, t_struct **list, int counter);
size_t				maskk(unsigned int i, t_struct **list, int counter);
size_t				maskkk(unsigned int i, t_struct **list, int counter);
size_t				mas(unsigned int i, t_struct **list, int counter);
void				get_unic_str(wchar_t *str, t_struct **list);
void				clean_content(t_struct **list);
void				getd(t_struct **list, char c, long long l, va_list vl);
void				create_mw(t_struct **list);
void				test_null(t_struct **list);
void				dif_cons(t_struct **list);
void				sht(char *st, t_struct **list);
void				shorten(t_struct **list);
void				free_list(t_struct **list);
char				*f_strdup(char *src);
void				put_plus(t_struct **list);
void				put_space(t_struct **list);
void				continue_fl(t_struct **list);
int					find_unic(t_struct *list);
void				continue_str(t_struct **list,
						va_list vl, char *c, char **s);
#endif
