/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_mul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/20 20:29:11 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigint.h"

static void				ft_memmul_1byte(
unsigned char *res, unsigned char *val1, unsigned char *val2, size_t n2)
{
	unsigned short	product;
	unsigned char	overflow;

	overflow = 0;
	while (n2--)
	{
		product = *val1 * *val2 + overflow + *res;
		*res = product % 0x100;
		overflow = product / 0x100;
		res++;
		val2++;
	}
	if (overflow)
		*res = overflow;
}

static void				ft_memmul_4byte(
unsigned int *res32, unsigned int *val1, unsigned int *val32_2, size_t n2)
{
	size_t			i;
	size_t			product;
	unsigned int	overflow;
	unsigned char	*val8_2;
	unsigned char	*res8;

	overflow = 0;
	i = n2 / 4;
	while (i--)
	{
		product = (size_t)*val1 * (size_t)*val32_2 + overflow + *res32;
		*res32 = product % 0x100000000;
		overflow = product / 0x100000000;
		res32++;
		val32_2++;
	}
	if (overflow)
		*res32 = overflow;
	val8_2 = (unsigned char	*)val32_2;
	res8 = (unsigned char *)res32;
	i = n2 % 4;
	while (i--)
		ft_memmul_1byte(res8++, val8_2++, (unsigned char *)val1, 4);
}

static unsigned char	*ft_mul_algor(
unsigned char *val8_1, unsigned char *val8_2, size_t n1, size_t n2)
{
	size_t			i;
	unsigned int	*val32_1;
	unsigned int	*res32;
	unsigned char	*res8;
	unsigned char	*res;

	res = (unsigned char *)malloc(n1 + n2);
	ft_bzero(res, n1 + n2);
	res32 = (unsigned int *)res;
	val32_1 = (unsigned int *)val8_1;
	i = n1 / 4;
	while (i--)
		ft_memmul_4byte(res32++, val32_1++, (unsigned int *)val8_2, n2);
	i = n1 % 4;
	res8 = (unsigned char *)res32;
	val8_1 = (unsigned char	*)val32_1;
	while (i--)
		ft_memmul_1byte(res8++, val8_1++, val8_2, n2);
	return (res);
}

void					ft_bigint_mul(t_bigint *mul, t_bigint *a, t_bigint *b)
{
	unsigned char	*val1;
	unsigned char	*val2;

	val1 = a->value;
	val2 = b->value;
	mul->value = ft_mul_algor(val1, val2, a->size, b->size);
	mul->size = a->size + b->size;
}
