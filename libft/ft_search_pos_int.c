/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_pos_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:18:52 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 01:05:53 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_search_pos_int(char *s, int *i)
{
	size_t	num;
	int		j;

	j = *i;
	while (s[j] == ' ')
		++j;
	num = 0;
	while (s[j] >= '0' && s[j] <= '9')
		num = num * 10 + s[j++] - '0';
	*i = j;
	return (num);
}
