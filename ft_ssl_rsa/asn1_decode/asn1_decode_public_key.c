/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_decode_public_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 00:57:54 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_parse_values(t_rsa_data *data, char **ptr, size_t *len)
{
	ft_bzero(data, sizeof(*data));
	if (ft_asn1_get_value(&data->modulus, 0x2, ptr, len))
		return (1);
	if (ft_asn1_get_value(&data->public_exponent, 0x2, ptr, len))
		return (1);
	return (0);
}

static char g_magic_string[] =
{
	0x00, 0x05, 0x01, 0x01, 0x01, 0x0d, 0xf7,
	0x86, 0x48, 0x86, 0x2a, 0x09, 0x06
};

static int	ft_check_magic_number(char **ptr, size_t *len)
{
	t_bigint			my_magic;
	t_bigint			original_magic;

	if (ft_asn1_get_value(&my_magic, 0x30, ptr, len))
		return (1);
	original_magic.size = 13;
	original_magic.value = (unsigned char *)g_magic_string;
	if (ft_bigint_equal(&my_magic, &original_magic) == 0)
	{
		ft_bigint_del(&my_magic);
		return (1);
	}
	ft_bigint_del(&my_magic);
	return (0);
}

static int	ft_check_size(char **ptr, size_t *len)
{
	if (ft_asn1_check_size(ptr, 0x03, len))
		return (1);
	*len -= 1;
	*ptr += 1;
	if (ft_asn1_check_size(ptr, 0x30, len))
		return (1);
	return (0);
}

int			ft_asn1_decode_public_key(t_rsa *rsa)
{
	char	*ptr;

	ptr = rsa->text;
	if (ft_asn1_check_size(&ptr, 0x30, &rsa->len))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	if (ft_check_magic_number(&ptr, &rsa->len))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	if (ft_check_size(&ptr, &rsa->len))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	if (ft_parse_values(&rsa->data, &ptr, &rsa->len))
	{
		ft_rsa_free_data(&rsa->data);
		ft_strdel(&rsa->text);
		return (1);
	}
	return (0);
}
