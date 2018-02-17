/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:57:24 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/09 14:57:25 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *temp;

	lst = *alst;
	while (lst)
	{
		temp = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = temp;
	}
	*alst = NULL;
}
