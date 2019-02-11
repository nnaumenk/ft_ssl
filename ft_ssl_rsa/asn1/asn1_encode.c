/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_encode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 17:06:54 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static void	ft_set_size(size_t size, char **text)
{
	size_t	byte_count;

	*(*text)++ = 0x30;
	if (size >= 0x80)
	{
		byte_count = (size + 255) / 256;
		*(*text)++ = 0x80 + byte_count;
		ft_memcpy(*text, &size, byte_count);
		ft_memrev(*text, byte_count);
		(*text) += byte_count;
	}
	else
		*(*text)++ = size;
	*(*text)++ = 0x02;
	*(*text)++ = 0x01;
	*(*text)++ = 0x00;
}

static void	ft_val(unsigned char *val, size_t vlen, char **text)
{
	size_t	byte_count;

	*(*text)++ = 0x02;
	if (vlen >= 0x80)
	{
		byte_count = (vlen + 255) / 256;
		*(*text)++ = 0x80 + byte_count;
		ft_memcpy(*text, &vlen, byte_count);
		ft_memrev(*text, byte_count);
		(*text) += byte_count;
	}
	else
		*(*text)++ = vlen;
	ft_memcpy(*text, val, vlen);
	ft_memrev(*text, vlen);
	(*text) += vlen;
}

static void	ft_set_values(t_rsa_data data, size_t size, char *text)
{
	ft_set_size(size, &text);
	ft_val(data.modulus, data.modulus_len, &text);
	ft_val(data.public_exponent, data.public_exponent_len, &text);
	ft_val(data.private_exponent, data.private_exponent_len, &text);
	ft_val(data.prime1, data.prime1_len, &text);
	ft_val(data.prime2, data.prime2_len, &text);
	ft_val(data.exponent1, data.exponent1_len, &text);
	ft_val(data.exponent2, data.exponent2_len, &text);
	ft_val(data.coefficient, data.coefficient_len, &text);
}

static void	ft_determine_size(t_rsa_data data, size_t *size, size_t *len)
{
	*len = 2 * 8 + 3;
	if (data.modulus_len >= 0x80)
		*len += (data.modulus_len + 255) / 256;
	if (data.modulus_len >= 0x80)
		*len += (data.public_exponent_len + 255) / 256;
	if (data.modulus_len >= 0x80)
		*len += (data.private_exponent_len + 255) / 256; 
	if (data.modulus_len >= 0x80)
		*len += (data.prime1_len + 255) / 256; 
	if (data.modulus_len >= 0x80)
		*len += (data.prime2_len + 255) / 256; 
	if (data.modulus_len >= 0x80)
		*len += (data.exponent1_len + 255) / 256; 
	if (data.modulus_len >= 0x80)
		*len += (data.exponent2_len + 255) / 256; 
	if (data.modulus_len >= 0x80)
		*len += (data.coefficient_len + 255) / 256;
	*len += data.modulus_len + data.public_exponent_len +
	data.private_exponent_len + data.prime1_len + data.prime2_len +
	data.exponent1_len + data.exponent2_len + data.coefficient_len;
	*size = *len;
	if (*len >= 0x80)
		*len += (*len + 255) / 256;
	*len += 2;
}

int		ft_asn1_encode(t_rsa_data data, char **text, size_t *len)			
{
	size_t		size;

	ft_determine_size(data, &size, len);
	*text = (char *)malloc(*len);
	ft_set_values(data, size, *text);
	return (0);
}