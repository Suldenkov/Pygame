/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:35:04 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:35:06 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mas;

	mas = (void*)malloc(count * size);
	if (mas == NULL)
		return (NULL);
	ft_bzero(mas, count * size);
	return (mas);
}
