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

static int	ft_mem_equal(void *mem1, void *mem2, size_t n)
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

int			ft_bigint_equal(void *memptr1, void *memptr2, size_t n1, size_t n2)
{
	unsigned char *val1;
	unsigned char *val2;

	if (n1 == n2)
		return (ft_mem_equal(memptr1, memptr2, n1));
	val1 = memptr1;
	val2 = memptr2;
	if (n1 < n2)
	{
		if (ft_iszero(memptr2 + n1, n2 - n1))
			return (ft_mem_equal(memptr1, memptr2, n1));
		return (0);
	}
	if (n1 > n2)
	{
		if (ft_iszero(memptr1 + n2, n1 - n2))
			return (ft_mem_equal(memptr1, memptr2, n2));
		return (0);
	}
	return (0);
}
