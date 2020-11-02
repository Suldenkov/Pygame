/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:50:25 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/01 17:28:08 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		index;
	int		ind;

	index = 0;
	ind = 0;
	str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[index] != '\0')
		str[ind++] = s1[index++];
	index = 0;
	while (s2[index] != '\0')
		str[ind++] = s2[index++];
	str[ind] = '\0';
	return (str);
}
