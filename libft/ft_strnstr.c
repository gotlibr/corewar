/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:29:43 by mkoniev           #+#    #+#             */
/*   Updated: 2017/10/31 12:29:44 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = 0;
	if (*little == '\0')
		return (big);
	if (little == big)
		return (little);
	while (big[i] != '\0' && i < (len - ft_strlen(little) + 1))
	{
		j = i;
		while (big[j] == little[k] && little[k] != '\0'
			&& big[j] != '\0' && k < len)
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
