/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:31:21 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:31:23 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int count;

	count = 0;
	while (*(s + count) != '\0')
	{
		if (*(s + count) == (char)c)
			return (s + count);
		count++;
	}
	if (*(s + count) == '\0')
		return (s + count);
}
