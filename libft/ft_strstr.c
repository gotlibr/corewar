/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:52:36 by mkoniev           #+#    #+#             */
/*   Updated: 2017/10/31 11:52:38 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *big, char *little)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = 0;
	if (*little == '\0')
		return (big);
	while (big[i] != '\0')
	{
		j = i;
		while (big[j] == little[k] && little[k] != '\0' && big[j] != '\0')
		{
			j++;
			k++;
		}
		if (little[k] == '\0')
			return (big + i);
		k = 0;
		i++;
	}
	return (NULL);
}
