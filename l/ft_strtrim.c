/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:32:25 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/01 17:51:19 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;
	int		index;
	int		ind;

	size = 0;
	ind = 0;
	index = 0;
	while (s1[index + ft_strlen(set)] != '\0')
		if (ft_strncmp(s1 + index++, set, ft_strlen(set)) == 0)
			size += 1;
	str = (char*)malloc(sizeof(char const) * (size + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		if (ft_strncmp(&s1[index], set, ft_strlen(set)) == 0)
			index += ft_strlen(set) - 1;
		else
			str[ind++] = s1[index];
		index++;
	}
	str[ind] = '\0';
	return (str);
}
