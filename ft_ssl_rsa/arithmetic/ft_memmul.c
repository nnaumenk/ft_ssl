/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 03:49:00 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

// static void	ft_mul_algor(uint8_t *buf, uint8_t *val1, uint8_t *val2, int size)
// {
// 	uint16_t	product;
// 	uint8_t		overflow;
	
// 	overflow = 0;
// 	while (size--)
// 	{
// 		product = (*val1) * (*val2) + overflow;
// 		*buf = product % 0x100;
// 		overflow = product / 0x100;
// 		val2++;
// 		buf++;
// 	}
// }


void		ft_memmul(void *dst, void *src, size_t n)
{
	// uint8_t		val[size];///pererobyt na mallco
	// uint8_t		val_buf[size];///pererobyt na malloc
	// int			i;

	// ft_bzero(val, size);
	// i = -1;
	// while (++i < size)
	// {
	// 	ft_bzero(val_buf, i);
	// 	ft_mul_algor(val_buf + i, val8_1 + i, val8_2, size - i);
	// 	//ft_byte_add(val, val_buf, size);
	// }
	// ft_memcpy(val8_1, val, size);
	USE(src);
	USE(dst);
	USE(n);
}

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