/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_to_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:07:56 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 01:08:23 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bits_to_mem(void *mem, void *bits, size_t n)
{
	uint8_t			*bit_pointer;
	uint8_t			value;

	bit_pointer = bits;
	while (n--)
	{
		value = *bit_pointer++ * 128;
		value += *bit_pointer++ * 64;
		value += *bit_pointer++ * 32;
		value += *bit_pointer++ * 16;
		value += *bit_pointer++ * 8;
		value += *bit_pointer++ * 4;
		value += *bit_pointer++ * 2;
		value += *bit_pointer++;
		*(uint8_t *)mem++ = value;
	}
}
