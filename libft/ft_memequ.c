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

int		ft_memequ(void *mem1, void *mem2, size_t n)
{
	size_t			i;
	size_t			*mem1_64;
	size_t			*mem2_64;
	unsigned char	*mem1_8;
	unsigned char	*mem2_8;

	mem1_64 = (size_t *)mem1;
	mem2_64 = (size_t *)mem2;
	i = n / sizeof(size_t);
	while (i--)
		if (*mem1_64++ != *mem2_64++)
			return (0);
	mem1_8 = (unsigned char *)mem1_64;
	mem2_8 = (unsigned char *)mem2_64;
	i = n % sizeof(size_t);
	while (i--)
		if (*mem1_8++ != *mem2_8++)
			return (0);
	return (1);
}
