/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 20:28:40 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

static int	ft_max_value(void *memptr, size_t num)
{
	size_t			i;
	size_t			*str64;
	unsigned char	*str8;

	str64 = (size_t *)memptr;
	i = num / sizeof(size_t);
	while (i--)
		if (*str64++ != 0xffffffffffffffff)
			return (0);
	str8 = (unsigned char *)str64;
	i = num % sizeof(size_t);
	while (i--)
		if (*str8++ != 0xff)
			return (0);
	return (1);
}

static void	ft_overflow(void **memptr1, size_t *n1, size_t *n2)
{
	unsigned char	*new;
	size_t			len;

	len = *n1 - *n2;
	if (len == 0)
	{
		new = malloc(*n1 + 1);
		ft_memcpy(new, *memptr1, *n1);
		new[(*n1)++] = 1;
		ft_memdel(memptr1);
		*memptr1 = new;
		return ;
	}
	else if (ft_max_value(*memptr1 + *n2, len))
	{
		new = malloc(*n1 + 1);
		ft_memcpy(new, *memptr1, *n2);
		ft_bzero(new + *n2, len);
		new[(*n1)++] = 1;
		ft_memdel(memptr1);
		*memptr1 = new;
		return ;
	}
	ft_bigint_increment(*memptr1 + *n2, len);
}

static void	ft_add_8byte(void **mem1, void **mem2, size_t i, char *overflow)
{
	size_t			*val1;
	size_t			*val2;
	size_t			sum64;

	val1 = (size_t *)*mem1;
	val2 = (size_t *)*mem2;
	while (i--)
	{
		sum64 = *val1 + *val2 + *overflow;
		if ((size_t)(sum64 - *overflow) < *val1)
			*overflow = 1;
		else
			*overflow = 0;
		*val1 = sum64;
		val1++;
		val2++;
	}
	*mem1 = val1;
	*mem2 = val2;
}

static void	ft_add_1byte(void **mem1, void **mem2, size_t i, char *overflow)
{
	unsigned char	*val1;
	unsigned char	*val2;
	unsigned char	sum8;
	
	val1 = (unsigned char *)*mem1;
	val2 = (unsigned char *)*mem2;
	while (i--)
	{
		sum8 = *val1 + *val2 + *overflow;
		if ((unsigned char)(sum8 - *overflow) < *val1)
			*overflow = 1;
		else
			*overflow = 0;
		*val1 = sum8;
		val1++;
		val2++;
	}
	*mem1 = val1;
	*mem2 = val2;
}

void		ft_bigint_add(void **memptr1, void **memptr2, size_t *n1, size_t *n2)
{
	void			*val1;
	void			*val2;
	char			overflow;

	if (*n2 > *n1)
	{
		ft_memswap(memptr1, memptr2, sizeof(*memptr1));
		ft_memswap(n1, n2, sizeof(*n1));
	}
	val1 = *memptr1;
	val2 = *memptr2;
	overflow = 0;
	ft_add_8byte(&val1, &val2, *n2 / sizeof(size_t), &overflow);
	ft_add_1byte(&val1, &val2, *n2 % sizeof(size_t), &overflow);
	if (overflow)
		ft_overflow(memptr1, n1, n2);
}
