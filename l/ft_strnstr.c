/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:29:35 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:29:38 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	count;

	count = 0;
	len_needle = ft_strlen(needle);
	while (count < len - len_needle)
	{
		if (ft_strncmp(haystack + count, needle, len_needle) == 0)
			return ((char*)(haystack + count));
		count++;
	}
	return (NULL);
}
