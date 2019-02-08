/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_encode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/04 16:00:33 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_val(unsigned char **val, size_t *vlen, char **text, size_t *len)
{
	if ((*len)--)////pererobyt pid odnu umovu if (*len < *vlen)
	{
		if (*(*text)++ != 0x2)
			return (1);
	}
	else
		return (1);
	if ((*len)--)
		*vlen = *(*text)++;
	else
		return (1);
	if (*len < *vlen)
		return (1);
	*val = (unsigned char *)malloc(*vlen);
	ft_bzero(*val, 0);
	ft_memcpy(*val, *text, *vlen);////dodaty umovu xhy ye konets (*text) - bytes;
	(*text) += *vlen;
	*len -= *vlen;
	return (0);
}

static int	ft_parse_values(t_rsa_data *vl, char **text, size_t *len)
{
	if (ft_val(&vl->modulus, &vl->modulus_len, text, len))
		return (1);
	if (ft_val(&vl->modulus, &vl->modulus_len, text, len))
		return (1);
	if (ft_val(&vl->public_exponent, &vl->public_exponent_len, text, len))
		return (1);
	if (ft_val(&vl->private_exponent, &vl->private_exponent_len, text, len))
		return (1);
	if (ft_val(&vl->prime1, &vl->prime1_len, text, len))
		return (1);
	if (ft_val(&vl->prime2, &vl->prime2_len, text, len))
		return (1);
	if (ft_val(&vl->exponent1, &vl->exponent1_len, text, len))
		return (1);
	if (ft_val(&vl->exponent2, &vl->exponent2_len, text, len))
		return (1);
	if (ft_val(&vl->coefficient, &vl->coefficient_len, text, len))
		return (1);
	return (0);
}

static int	ft_parse_size(char **text, size_t *len, size_t *size)
{
	size_t	bytes;

	if (*len < 2)
		return (1);
	*len -= 2;
	if (*(*text)++ != 0x30)
		return (1);
	if ((unsigned char)**text >= 0x80)
	{
		bytes = (unsigned char)*(*text)++ - 80;
		if (*len < bytes)
			return (1);
		ft_memcpy(size, *text, bytes);
		*len -= bytes;
		(*text) += bytes;
	}
	else
		*len = *(*text)++;
	return (0);
}

int			ft_asn1_encode(t_rsa_data *values, char *text, size_t len)			
{
	size_t		size;

	if (ft_parse_size(&text, &len, &size))
		return (1);
	if (len != size)
		return (1);
	if (ft_parse_values(values, &text, &len))
		return (1);
	return (0);
}
