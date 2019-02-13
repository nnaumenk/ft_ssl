/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_to_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:07:56 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/08/19 01:08:23 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mem_to_bits(void *bits, void *mem, size_t n)
{
	uint8_t		*bit_pointer;
	uint8_t		value;

	while (n--)
	{
		bits += 8;
		bit_pointer = bits;
		value = *(uint8_t*)mem++;
		*--bit_pointer = value % 2;
		value /= 2;
		*--bit_pointer = value % 2;
		value /= 2;
		*--bit_pointer = value % 2;
		value /= 2;
		*--bit_pointer = value % 2;
		value /= 2;
		*--bit_pointer = value % 2;
		value /= 2;
		*--bit_pointer = value % 2;
		value /= 2;
		*--bit_pointer = value % 2;
		value /= 2;
		*--bit_pointer = value % 2;
		value /= 2;
	}
}
