/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:28:59 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:29:03 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nm(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n /= -10;
		len += 2;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*number;
	int		len_number;
	int		minus;

	minus = 0;
	len_number = len_nm(n);
	number = (char*)malloc(sizeof(char) * (len_number + 1));
	if (number == NULL)
		return (NULL);
	number[len_number] = '\0';
	if (n < 0)
	{
		number[0] = '-';
		number[--len_number] = (n % 10) * -1 + '0';
		n /= -10;
		minus = 1;
	}
	while (len_number > minus)
	{
		number[--len_number] = (n % 10) + '0';
		n /= 10;
	}
	return (number);
}
