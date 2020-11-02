/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:25:54 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:26:00 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int index;
	int count;

	count = 0;
	index = -1;
	while (*(str + count) != '\0')
	{
		if (*(str + count) == (char)ch)
			index = count;
		count++;
	}
	if (*(str + count) == '\0')
		return (str + count);
	if (index != -1)
		return (str + index);
	return (NULL);
}
