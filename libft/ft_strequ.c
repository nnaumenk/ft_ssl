/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:16:06 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/23 16:21:45 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char *str1, char *str2)
{
	size_t	i;

	if (str1 == NULL)
	{
		if (str2 == NULL)
			return (1);
		return (0);
	}
	else if (str2 == NULL)
		return (0);
	i = -1;
	while (str1[++i])
		if (str1[i] != str2[i])
			return (0);
	if (str1[i] != str2[i])
		return (0);
	return (1);
}
