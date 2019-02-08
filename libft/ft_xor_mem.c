/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 15:26:46 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_xor_mem(void *dst, void *src, size_t count)
{
	unsigned char	*dst8;
	unsigned char	*src8;
	size_t			*dst64;
	size_t			*src64;
	size_t			i;

	dst64 = (size_t *)dst;
	src64 = (size_t *)src;
	i = count / sizeof(size_t);
	while (i--)
		*dst64++ ^= *src64++;
	dst8 = (unsigned char *)dst64;
	src8 = (unsigned char *)src64;
	i = count % sizeof(size_t);
	while (i--)
		*dst8++ ^= *src8++;
}
