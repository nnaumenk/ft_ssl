/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_encode_public_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:06:48 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static char g_magic_string[] =
{
	0x00, 0x05, 0x01, 0x01, 0x01, 0x0d, 0xf7,
	0x86, 0x48, 0x86, 0x2a, 0x09, 0x06
};

static void	ft_asn1_set_magic_number(char **ptr)
{
	t_bigint			original_magic;

	original_magic.size = 13;
	original_magic.value = (unsigned char *)g_magic_string;
	ft_asn1_set_value(original_magic, 0x30, ptr);
}

static void	ft_set_values(t_rsa_data data, size_t *size, char *ptr)
{
	ft_asn1_set_size(*size++, 0x30, &ptr);
	ft_asn1_set_magic_number(&ptr);
	ft_asn1_set_size(*size++, 0x03, &ptr);
	*ptr++ = 0;
	ft_asn1_set_size(*size, 0x30, &ptr);
	ft_asn1_set_value(data.modulus, 0x02, &ptr);
	ft_asn1_set_value(data.public_exponent, 0x02, &ptr);
}

static void	ft_determine_size(t_rsa_data data, size_t *size, size_t *len)
{
	*len = 2 + 2;
	if (data.modulus.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.modulus.size);
	if (data.public_exponent.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.public_exponent.size);
	*len += data.modulus.size + data.public_exponent.size;
	size += 2;
	*size-- = *len;
	if (*len >= 0x80)
		*len += ft_asn1_get_byte_number(*len);
	*len += 2;
	*len += 1;
	*size-- = *len;
	if (*len >= 0x80)
		*len += ft_asn1_get_byte_number(*len);
	*len += 2;
	*len += 13;
	*len += 2;
	*size = *len;
	if (*len >= 0x80)
		*len += ft_asn1_get_byte_number(*len);
	*len += 2;
}

int			ft_asn1_encode_public_key(t_rsa *rsa)
{
	size_t		size[3];

	ft_determine_size(rsa->data, (size_t *)size, &rsa->len);
	rsa->text = (char *)malloc(rsa->len);
	ft_set_values(rsa->data, (size_t *)size, rsa->text);
	return (0);
}
