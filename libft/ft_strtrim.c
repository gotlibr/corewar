/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:02:57 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/03 12:26:01 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		end;
	int		i;
	int		j;
	char	*new;

	end = 0;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[end] != '\0')
		end++;
	while (s[end] == '\0' || s[end] == ' ' || s[end] == '\n'
				|| s[end] == '\t')
		end--;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup("\0"));
	if (!(new = (char *)malloc(sizeof(char) * (end - i + 2))))
		return (NULL);
	while (i <= end)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
