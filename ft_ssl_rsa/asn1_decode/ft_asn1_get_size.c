/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_decode_public_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:06:42 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		ft_asn1_get_size(size_t *size, char **ptr, size_t *len)
{
	size_t			byte_count;
	unsigned char	value;

	value = **ptr;
	if (value >= 0x80)
	{
		byte_count = value - 0x80;
		*len -= 1;
		(*ptr) += 1;
		if (byte_count > 8 || byte_count == 0 || *len < byte_count)
			return (1);
		*size = 0;
		ft_memcpy(&*size, *ptr, byte_count);
		ft_memrev(&*size, byte_count);
		*len -= byte_count;
		*ptr += byte_count;
	}
	else
	{
		*size = value;
		*len -= 1;
		*ptr += 1;
	}
	return (0);
}
