/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:30:31 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:30:33 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len_dst;
	size_t len_src;
	size_t i;

	i = 0;
	len_dst = 0;
	len_src = ft_strlen(src);
	while (dst[len_dst] != '\0' && len_dst < dstsize)
		len_dst++;
	while (src[i] != '\0' && len_dst != dstsize - 1)
	{
		*(dst + len_dst) = src[i];
		i++;
		len_dst++;
	}
	if (dst[len_dst + i] != '\0')
		dst[len_dst + i] = '\0';
	return (len_dst + len_src - i);
}
