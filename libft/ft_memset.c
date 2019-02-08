/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 00:05:08 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 18:22:57 by nnaumenk         ###   ########.fr       */
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

void			*ft_memset(void *memptr, int val, size_t num)
{
	size_t			i;
	size_t			val64;
	unsigned char	val8;
	size_t			*str64;
	unsigned char	*str8;

	val8 = val;
	val64 = ft_byte_to_8byte(val8);
	str64 = (size_t *)memptr;
	i = num / sizeof(size_t);
	while (i--)
		*str64++ = val64;
	str8 = (unsigned char *)str64;
	i = num % sizeof(size_t);
	while (i--)
		*str8++ = val8;
	return (memptr);
}
