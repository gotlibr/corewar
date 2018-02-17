/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:09:56 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/05 13:37:06 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	char temp;

	while (*s != '\0')
	{
		temp = *s;
		write(1, &temp, 1);
		s++;
	}
}
