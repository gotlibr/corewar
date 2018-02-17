/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:52:34 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/03 11:52:36 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	while (*s1 == *s2 && *s2 != '\0' && *s1 != '\0' && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if ((i == n && *(--s1) == *(--s2)) || (*s1 == '\0' && *s2 == '\0'))
		return (1);
	return (0);
}
