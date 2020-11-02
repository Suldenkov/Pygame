/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wronnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:32:06 by wronnel           #+#    #+#             */
/*   Updated: 2020/11/01 16:39:04 by wronnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**create_mas(char **mas, char c, char const *s)
{
	int index;
	int ind;
	int i;

	index = 0;
	ind = 0;
	i = 0;
	while (s[index] != '\0')
	{
		if (s[index++] == c)
		{
			mas[ind] = (char*)malloc(sizeof(char) * (i + 1));
			i = 0;
			if (mas[ind] == NULL)
				return (NULL);
			ind++;
		}
		else
			i++;
	}
	mas[ind] = (char*)malloc(sizeof(char) * i);
	return (mas);
}

static char	**write_mas(char **mas, char c, char const *s)
{
	int index;
	int ind;
	int i;

	index = 0;
	ind = 0;
	i = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			mas[ind][i] = '\0';
			i = 0;
			ind++;
		}
		else
			mas[ind][i++] = s[index];
		index++;
	}
	mas[ind][i] = '\0';
	mas[ind + 1] = NULL;
	return (mas);
}

char		**ft_split(char const *s, char c)
{
	char	**mas;
	int		size;
	int		index;

	size = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index++] == c)
			size++;
	}
	mas = (char**)malloc(sizeof(char*) * (size + 2));
	if (mas == NULL)
		return (NULL);
	mas = create_mas(mas, c, s);
	if (mas == NULL)
		return (NULL);
	mas = write_mas(mas, c, s);
	return (mas);
}
