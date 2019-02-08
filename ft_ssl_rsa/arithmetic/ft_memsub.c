/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 03:49:00 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static void	ft_memsub_8byte(void **dst, void **src, size_t i, char *overflow)
{
	size_t			*dst64;
	size_t			*src64;
	size_t			sum64;

	src64 = (size_t *)*src;
	dst64 = (size_t *)*dst;
	while (i--)
	{
		sum64 = *dst64 - *src64 - *overflow;
		if (sum64 > *dst64)
			*overflow = 1;
		else
			*overflow = 0;
		*dst64 = sum64;
		src64++;
		dst64++;
	}
	*src = src64;
	*dst = dst64;
}

static void	ft_memsub_1byte(void **dst, void **src, size_t i, char *overflow)
{
	unsigned char	*dst8;
	unsigned char	*src8;
	unsigned char	sum8;
	
	src8 = (unsigned char *)*src;
	dst8 = (unsigned char *)*dst;
	while (i--)
	{
		sum8 = *dst8 - *src8 - *overflow;
		if (sum8 > *dst8)
			*overflow = 1;
		else
			*overflow = 0;
		*dst8 = sum8;
		src8++;
		dst8++;
	}
	*src = src8;
	*dst = dst8;
}

void		ft_memsub(void *dst, void *src, size_t n)
{
	char	overflow;

	overflow = 0;
	ft_memsub_8byte(&dst, &src, n / sizeof(size_t), &overflow);
	ft_memsub_1byte(&dst, &src, n % sizeof(size_t), &overflow);
}
