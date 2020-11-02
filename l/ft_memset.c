/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:38:26 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:38:27 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *destination, int c, size_t n)
{
	char *str;

	str = (char*)destination;
	while (n != 0)
	{
		*str = c;
		str++;
		n--;
	}
	return (destination);
}
