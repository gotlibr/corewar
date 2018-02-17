/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:50:07 by mkoniev           #+#    #+#             */
/*   Updated: 2017/10/26 13:52:10 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		counter;
	int		i;

	counter = 0;
	copy = "";
	i = 0;
	while (src[counter] != '\0')
	{
		counter++;
	}
	copy = malloc(sizeof(char) * (counter + 1));
	if (!copy)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
