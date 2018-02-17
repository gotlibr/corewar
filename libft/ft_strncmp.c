/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:43:45 by mkoniev           #+#    #+#             */
/*   Updated: 2017/10/31 12:43:48 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while ((unsigned char)(*s1) == (unsigned char)(*s2) &&
			(unsigned char)(*s1) != '\0'
				&& (unsigned char)(*s2) != '\0' && i < (int)n)
	{
		i++;
		s1++;
		s2++;
	}
	if (i == (int)n)
		return ((unsigned char)(*(--s1)) - (unsigned char)*(--s2));
	return ((unsigned char)(*s1) - (unsigned char)*s2);
}
