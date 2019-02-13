/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asn1_decode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 17:06:54 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_get_byte_size(char **text, size_t *len, size_t *size)
{
	size_t			byte_count;
	unsigned char	value;

	value = **text;
	if (value >= 0x80)
	{
		byte_count = value - 0x80;
		*len -= 1;
		(*text) += 1;
		if (*len < byte_count)
			return (1);
		*size = 0;
		ft_memcpy(size, *text, byte_count);
		ft_memrev(size, byte_count);
		*len -= byte_count;
		(*text) += byte_count;
	}
	else
	{
		*size = value;
		*len -= 1;
		(*text) += 1;
	}
	return (0);
}

static int	ft_val(unsigned char **val, size_t *vlen, char **text, size_t *len)
{
	if (*len < 1 || **text != 0x02)
		return (1);
	*len -= 1;
	(*text) += 1;
	if (ft_get_byte_size(text, len, vlen))
		return (1);
	if (*len < *vlen)
		return (1);
	*val = (unsigned char *)malloc(*vlen);
	ft_memcpy(*val, *text, *vlen);
	ft_memrev(*val, *vlen);
	*len -= *vlen;
	(*text) += *vlen;
	return (0);
}

static int	ft_parse_values(t_rsa_data *dt, char **text, size_t *len)
{
	if (ft_val(&dt->modulus, &dt->modulus_len, text, len))
		return (1);
	if (ft_val(&dt->modulus, &dt->modulus_len, text, len))
		return (1);
	if (ft_val(&dt->public_exponent, &dt->public_exponent_len, text, len))
		return (1);
	if (ft_val(&dt->private_exponent, &dt->private_exponent_len, text, len))
		return (1);
	if (ft_val(&dt->prime1, &dt->prime1_len, text, len))
		return (1);
	if (ft_val(&dt->prime2, &dt->prime2_len, text, len))
		return (1);
	if (ft_val(&dt->exponent1, &dt->exponent1_len, text, len))
		return (1);
	if (ft_val(&dt->exponent2, &dt->exponent2_len, text, len))
		return (1);
	if (ft_val(&dt->coefficient, &dt->coefficient_len, text, len))
		return (1);
	return (0);
}

static int	ft_check_size(char **text, size_t *len)
{
	size_t	size;

	if (*len < 1 || **text != 0x30)
	{
		ft_print("eror len1 0x30\n");
		return (1);
	}
	*len -= 1;
	(*text) += 1;
	if (ft_get_byte_size(text, len, &size))
		return (1);
	if (*len != size)
	{
		ft_print("len[%U] != size[%U]\n", *len, size);
		return (1);
	}
	return (0);
}

int			ft_asn1_decode(t_rsa_data *data, char *text, size_t len)			
{	
	if (ft_check_size(&text, &len))
	{
		ft_print("error in check size\n");
		return (1);
	}
	if (ft_parse_values(data, &text, &len))
	{
		ft_print("error in values\n");
		return (1);
	}
	return (0);
}
