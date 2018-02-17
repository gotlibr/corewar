/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:00:17 by mkoniev           #+#    #+#             */
/*   Updated: 2017/10/26 13:32:35 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	i = 0;
	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	while (n-- > 0)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
