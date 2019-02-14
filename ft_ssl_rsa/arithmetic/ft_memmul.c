/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/14 16:28:53 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"






// //64 ... 7f
// static void	ft_mul_algor_fast(uint32_t *buf, uint32_t *val1, uint32_t *val2, int size)
// {
// 	uint64_t	product;
// 	uint32_t	overflow;
	
// 	overflow = 0;
// 	while (size)
// 	{
// 		product = (*val1) * (*val2) + overflow;
// 		*buf = product % 0x100000000;
// 		overflow = product / 0x100000000;
// 		val2++;
// 		buf++;
// 		size -= 4;
// 	}
// }


// void		ft_byte_mul_fast(uint8_t *val8_1, uint8_t *val8_2, int size)
// {
// 	uint8_t		val[BYTE_SIZE];
// 	uint8_t		val_buf[BYTE_SIZE];
// 	int			i;

// 	ft_bzero(val, size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		ft_bzero(val_buf, i);
// 		ft_mul_algor_fast((uint32_t *)&val_buf[i], (uint32_t *)&val8_1[i], (uint32_t *)val8_2, size - i);
// 		ft_byte_add(val, val_buf, size);
// 		i += 4;
// 	}
// 	ft_memcpy(val8_1, val, size);
// }

static void		ft_mul_algor(uint8_t *res, uint8_t *val1, uint8_t val2, size_t n1)
{
	uint16_t	product;
	uint8_t		overflow;
	
	overflow = 0;
	while (n1--)
	{
		product = (*val1) * (val2) + overflow + *res;
		*res = product % 256;
		overflow = product / 256;
		val1++;
		res++;
	}
	if (overflow)
		*res = overflow;
}


unsigned char	*ft_memmul(void *dst, void *src, size_t n1, size_t n2)
{
	unsigned char	*val1;
	unsigned char	*val2;
	unsigned char	*res;
	unsigned char	*pointer;

	val1 = dst;
	val2 = src;
	res = (unsigned char *)malloc(n1 + n2);
	ft_bzero(res, n1 + n2);
	pointer = res;
	while (n2--)
		ft_mul_algor(pointer++, val1, *val2++, n1);
	return (res);
}

