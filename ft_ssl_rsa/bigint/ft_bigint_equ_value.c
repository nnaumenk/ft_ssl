/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 20:28:59 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

static int	ft_iszero(void *memptr, size_t num)
{
	size_t			i;
	size_t			*mem64;
	unsigned char	*mem8;

	mem64 = (size_t *)memptr;
	i = num / sizeof(size_t);
	while (i--)
		if (*mem64++ != 0)
			return (0);
	mem8 = (unsigned char *)mem64;
	i = num % sizeof(size_t);
	while (i--)
		if (*mem8++ != 0)
			return (0);
	return (1);
}

int			ft_bigint_equ_value(t_bigint *a, unsigned char value)
{
	if (ft_iszero(a->value + 1, a->size - 1))
	{
		if (a->value[0] == value)
			return (1);
		return (0);
	}
	return (0);
}
