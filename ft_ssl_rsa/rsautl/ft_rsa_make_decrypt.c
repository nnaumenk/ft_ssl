/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsautl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/05 16:29:09 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_rsa_check_padding(t_rsa *rsa)
{
	
	if (rsa->text[rsa->len - 1] != 0x02)
		return (1);







	if (rsa->data.modulus.size < rsa->len + 11)
	{
		ft_print_fd(2, "ft_ssl: data too large for key size\n");
		ft_rsa_free_data(&rsa->data);
		ft_strdel(&rsa->text);
		return (1);
	}
	r = rsa->data.modulus.size - 3 - rsa->len;
	padding_text = (char *)malloc(rsa->len + r + 3);
	padding_text[0] = 0x00;
	padding_text[1] = 0x02;
	ft_generate_urandom(padding_text + 2, r);
	padding_text[r + 2] = 0x00;
	ft_memcpy(padding_text + r + 3, rsa->text, rsa->len);
	ft_strdel(&rsa->text);
	rsa->text = padding_text;
	rsa->len = rsa->len + r + 3;
	return (0);
}

static void		ft_rsa_make_decrypt_algor(t_rsa *rsa)
{
	t_bigint	c;
	t_bigint	m;

	c.size = rsa->len;
	c.value = (unsigned char *)rsa->text;
	ft_memrev(c.value, c.size);
	ft_pow_mod(&m, &c, &rsa->data.private_exponent, &rsa->data.modulus);
	ft_strdel(&rsa->text);
	rsa->text = (char *)m.value;
	rsa->len = m.size;
}

int				ft_rsa_make_decrypt(t_rsa *rsa)
{
	if (rsa->len > rsa->data.modulus.size)
	{
		ft_print_fd(2, "ft_ssl: data too large for key size\n");
		ft_rsa_free_data(&rsa->data);
		ft_strdel(&rsa->text);
		return (1);
	}
	ft_rsa_make_decrypt_algor(rsa);
	if (ft_rsa_check_padding(rsa))
	{
		ft_print_fd(2, "ft_ssl: padding check failed\n");
		ft_rsa_free_data(&rsa->data);
		ft_strdel(&rsa->text);
		return (1);
	}
	return (0);
}