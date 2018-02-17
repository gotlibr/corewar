/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:32:33 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/01 14:32:35 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*news;
	long int		counter;

	counter = 0;
	if (!s || !f)
		return (NULL);
	while (s[counter] != '\0')
		counter++;
	if (!(news = (char *)malloc(sizeof(char) * (counter + 1))))
		return (NULL);
	news[counter] = '\0';
	counter--;
	while (counter >= 0)
	{
		news[counter] = f(s[counter]);
		counter--;
	}
	return (news);
}
