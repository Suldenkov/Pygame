/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:22 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:34:25 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s_copy;

	s_copy = (char*)s;
	i = 0;
	while (n-- != 0)
	{
		if (s_copy == c)
			return (s_copy);
		s_copy++;
	}
	return (NULL);
}
