/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:43:43 by mkoniev           #+#    #+#             */
/*   Updated: 2017/10/23 19:57:39 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iterative_factorial(int nb)
{
	int counter;

	counter = 1;
	if (nb > 12 || nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
		while (nb > 0)
		{
			counter *= nb;
			nb--;
		}
	return (counter);
}
