/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:45 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:34:47 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dst_copy;
	const char	*src_copy;

	i = 0;
	dst_copy = (char*)dst;
	src_copy = (const char*)src;
	while (i < n)
	{
		*dst_copy = *src_copy;
		if (*dst_copy == c)
			return (dst_copy + 1);
		dst_copy++;
		src_copy++;
	}
	return (NULL);
}
