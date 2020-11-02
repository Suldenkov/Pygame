/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:36:33 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 12:48:01 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curent;

	curent = lst;
	if (curent == NULL)
		return (NULL);
	while (curent->next != NULL)
		curent = curent->next;
	return (curent);
}
