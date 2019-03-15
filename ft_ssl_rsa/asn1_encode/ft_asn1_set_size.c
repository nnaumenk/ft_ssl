/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_encode_private_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:06:46 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	ft_asn1_set_size(size_t size, char tag, char **ptr)
{
	size_t	byte_number;

	*(*ptr)++ = tag;
	if (size >= 0x80)
	{
		byte_number = ft_asn1_get_byte_number(size);
		*(*ptr)++ = 0x80 + byte_number;
		ft_memcpy(*ptr, &size, byte_number);
		ft_memrev(*ptr, byte_number);
		(*ptr) += byte_number;
	}
	else
		*(*ptr)++ = size;
}
