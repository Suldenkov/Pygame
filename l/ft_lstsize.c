/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:32:09 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:40:41 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curent;
	int		len;

	curent = lst;
	len = 0;
	while (curent != NULL)
	{
		curent = curent->next;
		len++;
	}
	return (len);
}
