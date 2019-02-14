/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/14 19:08:50 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static unsigned char	*ft_memmul_4byte
(unsigned int *val1, unsigned int *val2, size_t size1, size_t size2)
{
	size_t			i;
	size_t			j;
	unsigned int	*res;
	unsigned int	overflow;
	size_t			product;

	res = (unsigned int *)malloc(4 * (size1 + size2));
	ft_bzero(res, 4 * (size1 + size2));
	overflow = 0;
	i = -1;
	while (++i < size1)
	{
		j = -1;
		while (++j < size2)
		{
			product = val1[i] * val2[j] + overflow + res[i + j];
			res[i + j] = product % 0x100000000;
			overflow = product / 0x100000000;
		}
		if (overflow)
			res[i + j] = overflow;
	}
	return (res);
}

static unsigned char	*ft_memmul_2byte
(unsigned short *val1, unsigned short *val2, size_t size1, size_t size2)
{
	size_t			i;
	size_t			j;
	unsigned short	*res;
	unsigned short	overflow;
	unsigned int	product;

	res = (unsigned short *)malloc(2 * (size1 + size2));
	ft_bzero(res, 2 * (size1 + size2));
	overflow = 0;
	i = -1;
	while (++i < size1)
	{
		j = -1;
		while (++j < size2)
		{
			product = val1[i] * val2[j] + overflow + res[i + j];
			res[i + j] = product % 0x10000;
			overflow = product / 0x10000;
		}
		if (overflow)
			res[i + j] = overflow;
	}
	return (res);
}

static unsigned char	*ft_memmul_1byte
(unsigned char *val1, unsigned char *val2, size_t size1, size_t size2)
{
	size_t			i;
	size_t			j;
	unsigned char	*res;
	unsigned char	overflow;
	unsigned short	product;

	res = (unsigned char *)malloc(size1 + size2);
	ft_bzero(res, size1 + size2);
	overflow = 0;
	i = -1;
	while (++i < size1)
	{
		j = -1;
		while (++j < size2)
		{
			product = val1[i] * val2[j] + overflow + res[i + j];
			res[i + j] = product % 0x100;
			overflow = product / 0x100;
		}
		if (overflow)
			res[i + j] = overflow;
	}
	return (res);
}

unsigned char			*ft_memmul(void *m1, void *m2, size_t n1, size_t n2)
{
	if (n1 % 4 == 0 && n2 % 4 == 0)
		return (ft_memmul_4byte(m1, m2, n1 / 4, n2 / 4));
	if (n1 % 2 == 0 && n2 % 2 == 0)
		return (ft_memmul_2byte(m1, m2, n1 / 2, n2 / 2));
	return (ft_memmul_1byte(m1, m2, n1, n2));
}
