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

static int	ft_get_byte_amount(char **text, size_t *len, size_t *size)
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
	{
		ft_printf("first != 0x2\n");
		return (1);
	}
	*len -= 1;
	(*text) += 1;
	if (ft_get_byte_amount(text, len, vlen))
	{
		ft_printf("byte_size");
		return (1);
	}
	if (*len < *vlen)
	{
		ft_printf("len(%zu) < vlen(%zu)\n", *len, *vlen);
		return (1);
	}
	*val = (unsigned char *)malloc(*vlen);
	ft_memcpy(*val, *text, *vlen);
	ft_memrev(*val, *vlen);
	*len -= *vlen;
	(*text) += *vlen;
	return (0);
}

static int	ft_parse_values(t_rsa_data *dt, char **text, size_t *len)
{
	if (ft_val(&dt->version.value, &dt->version.size, text, len))
	{
		ft_printf("1 value\n");
		return (1);
	}
	if (ft_val(&dt->modulus.value, &dt->modulus.size, text, len))
	{
		ft_printf("2 value\n");
		return (1);
	}
	if (ft_val(&dt->public_exponent.value, &dt->public_exponent.size, text, len))
	{
		ft_printf("3 value\n");
		return (1);
	}
	if (ft_val(&dt->private_exponent.value, &dt->private_exponent.size, text, len))
	{
		ft_printf("4 value\n");
		return (1);
	}
	if (ft_val(&dt->prime1.value, &dt->prime1.size, text, len))
	{
		ft_printf("5 value\n");
		return (1);
	}
	if (ft_val(&dt->prime2.value, &dt->prime2.size, text, len))
	{
		ft_printf("6 value\n");
		return (1);
	}
	if (ft_val(&dt->exponent1.value, &dt->exponent1.size, text, len))
	{
		ft_printf("7 value\n");
		return (1);
	}
	if (ft_val(&dt->exponent2.value, &dt->exponent2.size, text, len))
	{
		ft_printf("8 value\n");
		return (1);
	}
	if (ft_val(&dt->coefficient.value, &dt->coefficient.size, text, len))
	{
		ft_printf("9 value\n");
		return (1);
	}
	return (0);
}

static int	ft_check_size(char **text, size_t *len)
{
	size_t	size;

	if (*len < 1 || **text != 0x30)
		return (1);
	*len -= 1;
	(*text) += 1;
	if (ft_get_byte_amount(text, len, &size))
		return (1);
	if (*len != size)
		return (1);
	return (0);
}

int			ft_asn1_decode(t_rsa_data *data, char *text, size_t len)			
{	
	if (ft_check_size(&text, &len))
	{
		ft_printf("error in check size\n");
		return (1);
	}
	if (ft_parse_values(data, &text, &len))
	{
		ft_printf("error in values!\n");
		return (1);
	}
	return (0);
}
