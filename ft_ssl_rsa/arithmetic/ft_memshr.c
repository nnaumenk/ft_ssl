/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_by_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 03:49:00 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static void	ft_copy_1byte(void *memptr, size_t shift, size_t n)
{
	size_t			i;
	unsigned char	*src8;
	unsigned char	*dst8;

	if (shift == 0)
		return ;
	src8 = (unsigned char *)memptr;
	dst8 = (unsigned char *)memptr + shift;
	i = shift - 1;
	while (++i < n)
		*dst8++ = *src8++;
	ft_bzero(memptr + n - shift, shift);
}

static void	ft_shift_1byte(void *memptr, size_t shift, size_t n)
{
	unsigned char	overflow;
	unsigned char	buf;
	unsigned char	*mem8;

	if (shift == 0)
		return ;
	overflow = 0;
	mem8 = (unsigned char *)memptr + n - 1;
	while (n--)
	{
		buf = (*mem8 << (8 - shift));
		*mem8 = (*mem8 >> shift) | overflow;
		overflow = buf;
		mem8--;
	}
}

void		ft_memshr(void *memptr, size_t shift, size_t n)
{
	ft_copy_1byte(memptr, shift / 8, n);
	ft_shift_1byte(memptr, shift % 8, n);
}
