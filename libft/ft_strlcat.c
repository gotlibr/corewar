/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:45:16 by mkoniev           #+#    #+#             */
/*   Updated: 2017/10/31 10:45:19 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		d_len;

	d = dst;
	s = src;
	n = dstsize;
	while (n-- != 0 && *d != '\0')
		d++;
	d_len = d - dst;
	n = dstsize - d_len;
	if (n == 0)
		return (d_len + ft_strlen(src));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (d_len + ft_strlen(src));
}
