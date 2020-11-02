/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:31:41 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:31:43 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_copy;
	char	*src_copy;
	size_t	count;

	dst_copy = (char*)dst;
	src_copy = (char*)src;
	count = 0;
	if (dst_copy > src_copy)
	{
		while (len > 0)
		{
			*(dst_copy + len - 1) = *(src_copy + len - 1);
			len--;
		}
	}
	else
	{
		while (count < len)
		{
			*(dst_copy + count) = *(src_copy + count);
			count++;
		}
	}
	return (dst);
}
