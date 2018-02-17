/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:42:07 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/09 13:42:09 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < (int)len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
