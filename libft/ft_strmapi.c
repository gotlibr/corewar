/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:47:25 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/01 14:47:26 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*news;
	long int		counter;

	counter = 0;
	if (!s || !f)
		return (NULL);
	if (!(news = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[counter] != '\0')
	{
		news[counter] = f(counter, (char)s[counter]);
		counter++;
	}
	news[counter] = '\0';
	return (news);
}
