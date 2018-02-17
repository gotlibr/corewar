/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:39:46 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/09 16:43:27 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countw(const char *str, char c)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static int		countl(const char *str, int i, char c)
{
	int end;

	end = i;
	while (str[end] != c && str[end] != '\0')
		end++;
	return (end - i + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	char				**res;
	int					j;
	unsigned int		k;
	int					a;

	k = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (countw(s, c) + 1))))
		return (NULL);
	while (s[k] != '\0')
	{
		if ((s[k] != c && (k == 0 || s[k - 1] == c)))
		{
			if (!(res[j] = (char *)malloc(sizeof(char) *
					(countl(s, k, c) + 1))))
				return (NULL);
			a = countl(s, k, c);
			res[j++] = ft_strsub(s, k, a - 1);
		}
		k++;
	}
	res[j] = NULL;
	return (res);
}
