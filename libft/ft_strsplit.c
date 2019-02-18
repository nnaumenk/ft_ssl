/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 23:50:45 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/09/15 03:32:37 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsplit_counter(char *s, char c)
{
	int		words;
	size_t	i;

	i = 0;
	words = 1;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

char		**ft_strsplit(char *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	offset;
	size_t	arr_index;

	offset = 0;
	arr_index = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_strsplit_counter(s, c) + 1));
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr[arr_index] = ft_strnew(i - offset + 1);
			ft_strncpy(arr[arr_index++], &s[offset], (i - offset + 1));
			offset = i + 1;
		}
		else if (s[i] == c)
			offset++;
	}
	arr[arr_index] = NULL;
	return (arr);
}
