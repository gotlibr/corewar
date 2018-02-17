/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:53:05 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/05 15:56:41 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(size + 1);
	if (new == NULL)
		return (NULL);
	while (i <= size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
