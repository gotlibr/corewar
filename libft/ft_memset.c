/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:58:08 by mkoniev           #+#    #+#             */
/*   Updated: 2017/10/26 13:37:07 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *d;

	d = (unsigned char*)b;
	if (len != 0)
	{
		while (len-- > 0)
			*d++ = (unsigned char)c;
	}
	return (b);
}
