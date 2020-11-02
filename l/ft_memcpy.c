/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:33:28 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:33:37 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char		*destination_copy;
	const char	*source_copy;

	destination_copy = (char*)destination;
	source_copy = (const char*)source;
	while (n-- != 0)
	{
		*destination_copy = *source_copy;
		destination_copy++;
		source_copy++;
	}
	return (destination);
}
