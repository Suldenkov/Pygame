/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:30:59 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/02 14:31:01 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mas;
	int		len_mass;
	int		i;

	i = 0;
	len_mass = ft_strlen(s1);
	mas = (char*)malloc(sizeof(char) * (len_mass + 1));
	if (mas == NULL)
		return (NULL);
	while (i < len_mass)
	{
		mas[i] = s1[i];
		i++;
	}
	mas[i] = '\0';
	return (mas);
}
