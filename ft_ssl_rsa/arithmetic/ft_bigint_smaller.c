/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_smaller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 20:29:20 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

static int	ft_iszero(void *memptr, size_t num)
{
	size_t			i;
	size_t			*str64;
	unsigned char	*str8;

	str64 = (size_t *)memptr;
	i = num / sizeof(size_t);
	while (i--)
		if (*str64++ != 0)
			return (0);
	str8 = (unsigned char *)str64;
	i = num % sizeof(size_t);
	while (i--)
		if (*str8++ != 0)
			return (0);
	return (1);
}

static int	ft_mem_smaller(unsigned char *val1, unsigned char *val2, size_t n)
{
	size_t			*val64_1;
	size_t			*val64_2;
	size_t			i;

	val64_1 = (size_t *)val1;
	val64_2 = (size_t *)val2;
	i = n / sizeof(size_t);
	while (i--)
	{
		if (*--val64_1 < *--val64_2)
			return (1);
		if (*val64_1 > *val64_2)
			return (0);
	}
	val1 = (unsigned char *)val64_1;
	val2 = (unsigned char *)val64_2;
	i = n % sizeof(size_t);
	while (i--)
	{
		if (*--val1 < *--val2)
			return (1);
		if (*val1 > *val2)
			return (0);
	}
	return (0);
}

int			ft_bigint_smaller(void *memptr1, void *memptr2, size_t n1,
size_t n2)
{
	unsigned char *val1;
	unsigned char *val2;

	if (n1 == n2)
		return (ft_mem_smaller(memptr1 + n1, memptr2 + n2, n1));
	val1 = memptr1;
	val2 = memptr2;
	if (n1 < n2)
	{
		if (ft_iszero(memptr2 + n1, n2 - n1))
			return (ft_mem_smaller(memptr1 + n1, memptr2 + n1, n1));
		return (1);
	}
	if (n1 > n2)
	{
		if (ft_iszero(memptr1 + n2, n1 - n2))
			return (ft_mem_smaller(memptr1 + n2, memptr2 + n2, n2));
		return (0);
	}
	return (0);
}
