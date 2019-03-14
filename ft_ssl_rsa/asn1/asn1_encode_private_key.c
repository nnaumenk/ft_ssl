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

static int	ft_get_byte_amount(size_t len)
{
	if (len <= 0xff)
		return (1);
	if (len <= 0xffff)
		return (2);
	if (len <= 0xffffff)
		return (3);
	if (len <= 0xffffffff)
		return (4);
	if (len <= 0xffffffffff)
		return (5);
	if (len <= 0xffffffffffff)
		return (6);
	if (len <= 0xffffffffffffff)
		return (7);
	return (8);
}

static void	ft_set_size(size_t size, char **text)
{
	size_t	byte_count;

	*(*text)++ = 0x30;
	if (size >= 0x80)
	{
		byte_count = ft_get_byte_amount(size);
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

static void	ft_val(t_bigint a, char **text)
{
	size_t	byte_count;

	*(*text)++ = 0x02;
	if (a.size >= 0x80)
	{
		byte_count = ft_get_byte_amount(a.size);
		*(*text)++ = 0x80 + byte_count;
		ft_memcpy(*text, &a.size, byte_count);
		ft_memrev(*text, byte_count);
		(*text) += byte_count;
	}
	else
		*(*text)++ = a.size;
	ft_memcpy(*text, a.value, a.size);
	ft_memrev(*text, a.size);
	(*text) += a.size;
}

static void	ft_set_values(t_rsa_data data, size_t size, char *text)
{
	ft_set_size(size, &text);
	ft_val(data.modulus, &text);
	ft_val(data.public_exponent, &text);
	ft_val(data.private_exponent, &text);
	ft_val(data.prime1, &text);
	ft_val(data.prime2, &text);
	ft_val(data.exponent1, &text);
	ft_val(data.exponent2, &text);
	ft_val(data.coefficient, &text);
}

static void	ft_determine_size(t_rsa_data data, size_t *size, size_t *len)
{
	*len = 8 + 8 + 2;
	if (data.modulus.size >= 0x80)
		*len += ft_get_byte_amount(data.modulus.size);
	if (data.public_exponent.size >= 0x80)
		*len += ft_get_byte_amount(data.public_exponent.size);
	if (data.private_exponent.size >= 0x80)
		*len += ft_get_byte_amount(data.private_exponent.size); 
	if (data.prime1.size >= 0x80)
		*len += ft_get_byte_amount(data.prime1.size);
	if (data.prime2.size >= 0x80)
		*len += ft_get_byte_amount(data.prime2.size);
	if (data.exponent1.size >= 0x80)
		*len += ft_get_byte_amount(data.exponent1.size); 
	if (data.exponent2.size >= 0x80)
		*len += ft_get_byte_amount(data.exponent2.size); 
	if (data.coefficient.size >= 0x80)
		*len += ft_get_byte_amount(data.coefficient.size);
	*len += 1 + data.modulus.size + data.public_exponent.size +
	data.private_exponent.size + data.prime1.size + data.prime2.size +
	data.exponent1.size + data.exponent2.size + data.coefficient.size;
	*size = *len;
	if (*len >= 0x80)
		*len += ft_get_byte_amount(*len);
	*len += 2;
}

void	ft_asn1_normalize_value(t_bigint *a)
{
	t_bigint	new;

	if (a->value[a->size - 1] >= 0x80)
	{
		new.size = a->size + 1;
		new.value = (unsigned char *)malloc(new.size);
		ft_memcpy(new.value, a->value, a->size);
		new.value[new.size - 1] = 0;
		ft_bigint_del(a);
		*a = new;
	}
}

void	ft_asn1_normalize(t_rsa_data *data)
{
	ft_asn1_normalize_value(&data->modulus);
	ft_asn1_normalize_value(&data->public_exponent);
	ft_asn1_normalize_value(&data->private_exponent);
	ft_asn1_normalize_value(&data->prime1);
	ft_asn1_normalize_value(&data->prime2);
	ft_asn1_normalize_value(&data->exponent1);
	ft_asn1_normalize_value(&data->exponent2);
	ft_asn1_normalize_value(&data->coefficient);
}

int		ft_asn1_encode_private_key(t_rsa_data *data, char **text, size_t *len)			
{
	size_t		size;

	ft_asn1_normalize(data);
	ft_determine_size(*data, &size, len);
	*text = (char *)malloc(*len);
	ft_set_values(*data, size, *text);
	return (0);
}