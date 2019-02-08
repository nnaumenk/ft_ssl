/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor_mem_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/08 15:26:32 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_byte_to_8byte(unsigned char val8)
{
	unsigned char	*byte_ptr;
	size_t			val64;

	byte_ptr = (unsigned char *)&val64;
	*byte_ptr++ = val8;
	*byte_ptr++ = val8;
	*byte_ptr++ = val8;
	*byte_ptr++ = val8;
	*byte_ptr++ = val8;
	*byte_ptr++ = val8;
	*byte_ptr++ = val8;
	*byte_ptr++ = val8;
	return (val64);
}

void			ft_xor_mem_value(void *dst, int val, size_t count)
{
	unsigned char	*dst8;
	size_t			*dst64;
	unsigned char	val8;
	size_t			val64;
	size_t			i;

	val64 = ft_byte_to_8byte(val);
	dst64 = (size_t *)dst;
	i = count / sizeof(size_t);
	while (i--)
		*dst64++ ^= val64;
	val8 = (unsigned char)val;
	dst8 = (unsigned char *)dst64;
	i = count % sizeof(size_t);
	while (i--)
		*dst8++ ^= val8;
}
