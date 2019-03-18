/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pem_outform_private_key.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 23:52:03 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 01:39:19 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static char		*ft_vector_to_hex(char *salt)
{
	char const		*base = "0123456789ABCDEF";
	size_t			len;
	char			*new;
	unsigned char	*byte;
	char			*hex;

	byte = (unsigned char *)salt;
	new = ft_strnew(18);
	new[17] = '\n';
	new[16] = '\n';
	hex = new;
	len = 8;
	while (len--)
	{
		hex[1] = base[(*byte) % 16];
		hex[0] = base[((*byte) / 16) % 16];
		hex += 2;
		byte++;
	}
	return (new);
}

int		ft_pem_des_outform_private_key(t_rsa *rsa)
{
	const char	*info = "Proc-Type: 4,ENCRYPTED\nDEK-Info: DES-CBC,";
	const char	*line1 = "-----BEGIN RSA PRIVATE KEY-----\n";
	const char	*line2 = "-----END RSA PRIVATE KEY-----\n";
	char		*tmp;
	char		*hex_vector;

	ft_asn1_encode_private_key(rsa);
	ft_generate_random(rsa->flag.vector, 8);
	if (ft_rsa_make_flag_des(rsa))
	{
		ft_strdel(&rsa->text);
		return (1);
	}
	rsa->text = ft_b64_encode(rsa->text, &rsa->len);
	hex_vector = ft_vector_to_hex(rsa->flag.vector);
	tmp = ft_mem_joiner(&rsa->len, 5,
		(char *)line1, ft_strlen((char *)line1),
		(char *)info, ft_strlen((char *)info),
		(char *)hex_vector, ft_strlen((char *)hex_vector),
		rsa->text, rsa->len,
		(char *)line2, ft_strlen((char *)line2));
	ft_strdel(&hex_vector);
	ft_strdel(&rsa->text);
	rsa->text = tmp;
	return (0);
}