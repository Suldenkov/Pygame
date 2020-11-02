/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:59:26 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 11:42:00 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curent;
	t_list	*new;
	t_list	*begin_new;

	curent = lst
	if (curent == NULL)
		return (NULL);
	begin_new = ft_lstnew((*f)(curent->content));
	begin_new = new;
	if (new == NULL)
		return (NULL);
	curent = curent->next;
	while (curent != NULL)
	{
		new->next = ft_lstnew((*f)(curent->content));
		if (new->next == NULL)
			return (NULL);
		new = new->next;
		curent = curent->next;
	}
	ft_lst_clear(&lst, del);
	return (begin_new);
}
