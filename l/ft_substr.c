/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:06:14 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/01 17:42:20 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mas;
	int		index;

	index = 0;
	mas = (char*)malloc(sizeof(*s) * (len + 1));
	if (mas == NULL)
		return (NULL);
	while (s[start] != '\0')
		mas[index++] = s[start++];
	mas[index] = '\0';
	return (mas);
}
