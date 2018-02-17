/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:19:22 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/05 15:52:09 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	a = (void *)malloc(size);
	if (a == NULL)
		return (NULL);
	a = ft_memset(a, 0, size);
	return (a);
}
