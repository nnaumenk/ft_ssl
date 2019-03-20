/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_decode_private_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 10:06:36 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_parse_values(t_rsa_data *data, char **ptr, size_t *len)
{
	ft_bzero(data, sizeof(*data));
	if (ft_asn1_get_value(&data->modulus, 0x2, ptr, len))
		return (1);
	ft_bigint_del(&data->modulus);
	if (ft_asn1_get_value(&data->modulus, 0x2, ptr, len))
		return (1);
	if (ft_asn1_get_value(&data->public_exponent, 0x2, ptr, len))
		return (1);
	if (ft_asn1_get_value(&data->private_exponent, 0x2, ptr, len))
		return (1);
	if (ft_asn1_get_value(&data->prime1, 0x2, ptr, len))
		return (1);
	if (ft_asn1_get_value(&data->prime2, 0x2, ptr, len))
		return (1);
	if (ft_asn1_get_value(&data->exponent1, 0x2, ptr, len))
		return (1);
	if (ft_asn1_get_value(&data->exponent2, 0x2, ptr, len))
		return (1);
	if (ft_asn1_get_value(&data->coefficient, 0x2, ptr, len))
		return (1);
	return (0);
}

int			ft_asn1_decode_private_key(t_rsa *rsa)
{
	char	*ptr;

	ptr = rsa->text;
	if (ft_asn1_check_size(&ptr, 0x30, &rsa->len))
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
