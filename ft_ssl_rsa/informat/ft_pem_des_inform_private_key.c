/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pem_inform_private_key.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:39:21 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_get_asn1_text(char **text, size_t *len)
{
	char		*start_key;

	start_key = *text + 57;
	*len -= 57;
	if (*start_key != '\n')
	{
		ft_strdel(text);
		return (1);
	}
	start_key++;
	(*len)--;
	if (*start_key != '\n')
	{
		ft_strdel(text);
		return (1);
	}
	start_key++;
	(*len)--;
	start_key = (char *)ft_memdup(start_key, *len);
	ft_strdel(text);
	*text = start_key;
	return (0);
}

static int	ft_rsa_des_cbc_decryption(t_rsa *rsa, char *key, char *iv)
{
	uint8_t		buf[8];
	char		vector[8];
	char		keys[16][48];
	char		*ptr;
	size_t		blocks;

	ft_des_decrypt_keys((uint8_t *)keys, (uint8_t *)key);
	ft_memcpy(vector, iv, 8);
	ptr = rsa->text;
	blocks = rsa->len / 8;
	while (blocks--)
	{
		ft_memcpy(buf, ptr, 8);
		ft_des_algor((uint8_t *)ptr, (uint8_t *)keys);
		ft_xor_mem((void *)ptr, (void *)vector, 8);
		ft_memcpy(vector, buf, 8);
		ptr += 8;
	}
	if (ft_des_check_padding((uint8_t *)(ptr - 8), &rsa->len, 1))
		return (1);
	return (0);
}

static int	ft_rsa_make_decryption(t_rsa *rsa)
{
	char	*key;

	if (ft_rsa_make_flag_passin(rsa))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	key = ft_evp(rsa->flag.passin, (uint8_t *)rsa->flag.vector, 8);
	if (ft_rsa_des_cbc_decryption(rsa, key, rsa->flag.vector))
	{
		ft_strdel(&rsa->text);
		ft_strdel(&key);
		return (1);
	}
	ft_strdel(&key);
	return (0);
}

int			ft_pem_des_inform_private_key(t_rsa *rsa)
{
	char	*hex;

	hex = rsa->text + 41;
	if (rsa->len < (41 + 16))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	if (ft_hex_to_ascii((uint8_t *)rsa->flag.vector, hex, 8))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	if (ft_get_asn1_text(&rsa->text, &rsa->len))
		return (1);
	rsa->text = ft_b64_decode(rsa->text, &rsa->len);
	if (ft_rsa_make_decryption(rsa))
		return (1);
	if (ft_asn1_decode_private_key(rsa))
		return (1);
	return (0);
}
