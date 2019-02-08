/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 23:51:33 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 20:03:41 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t			i;
	size_t			*dst64;
	size_t			*src64;
	unsigned char	*dst8;
	unsigned char	*src8;

	src64 = (size_t *)src;
	dst64 = (size_t *)dst;
	i = n / sizeof(size_t);
	while (i--)
		*dst64++ = *src64++;
	src8 = (unsigned char *)src64;
	dst8 = (unsigned char *)dst64;
	i = n % sizeof(size_t);
	while (i--)
		*dst8++ = *src8++;
	return (dst);
}
