/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoniev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:55:11 by mkoniev           #+#    #+#             */
/*   Updated: 2017/11/09 15:55:13 by mkoniev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map;
	t_list *head;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(map = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	head = map;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(map->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		map = map->next;
		lst = lst->next;
	}
	return (head);
}
