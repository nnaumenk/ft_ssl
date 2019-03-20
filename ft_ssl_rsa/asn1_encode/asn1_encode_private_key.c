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

static void	ft_set_values(t_rsa_data data, size_t size, char *ptr)
{
	ft_asn1_set_size(size, 0x30, &ptr);
	ft_asn1_set_version(&ptr);
	ft_asn1_set_value(data.modulus, 0x02, &ptr);
	ft_asn1_set_value(data.public_exponent, 0x02, &ptr);
	ft_asn1_set_value(data.private_exponent, 0x02, &ptr);
	ft_asn1_set_value(data.prime1, 0x02, &ptr);
	ft_asn1_set_value(data.prime2, 0x02, &ptr);
	ft_asn1_set_value(data.exponent1, 0x02, &ptr);
	ft_asn1_set_value(data.exponent2, 0x02, &ptr);
	ft_asn1_set_value(data.coefficient, 0x02, &ptr);
}

static void	ft_determine_size(t_rsa_data data, size_t *size, size_t *len)
{
	*len = 8 + 8 + 2;
	if (data.modulus.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.modulus.size);
	if (data.public_exponent.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.public_exponent.size);
	if (data.private_exponent.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.private_exponent.size);
	if (data.prime1.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.prime1.size);
	if (data.prime2.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.prime2.size);
	if (data.exponent1.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.exponent1.size);
	if (data.exponent2.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.exponent2.size);
	if (data.coefficient.size >= 0x80)
		*len += ft_asn1_get_byte_number(data.coefficient.size);
	*len += 1 + data.modulus.size + data.public_exponent.size +
	data.private_exponent.size + data.prime1.size + data.prime2.size +
	data.exponent1.size + data.exponent2.size + data.coefficient.size;
	*size = *len;
	if (*len >= 0x80)
		*len += ft_asn1_get_byte_number(*len);
	*len += 2;
}

int			ft_asn1_encode_private_key(t_rsa *rsa)
{
	size_t		size;

	ft_determine_size(rsa->data, &size, &rsa->len);
	rsa->text = (char *)malloc(rsa->len);
	ft_set_values(rsa->data, size, rsa->text);
	return (0);
}
