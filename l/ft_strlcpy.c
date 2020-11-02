/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:36:01 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:36:04 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t count;

	count = 0;
	if (size - 1 != 0)
	{
		while (size - 1 > count && src[count] != '\0')
		{
			dst[count] = src[count];
			count++;
			size--;
		}
		dst[count] = '\0';
		count = 0;
	}
	while (src[count] != '\0')
		count++;
	return (count);
}
