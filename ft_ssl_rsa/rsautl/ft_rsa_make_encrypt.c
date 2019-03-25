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

static int	ft_rsa_make_padding(t_rsa *rsa)
{
	size_t	r;
	char	*ptr;
	char	*padding_text;
	size_t	padding_len;

	r = rsa->data.modulus.size - 3 - rsa->len;
	ft_printf("r = %zu\n", r);
	padding_len = rsa->len + r + 2;
	padding_text = (char *)malloc(padding_len);
	ptr = padding_text;
	ft_memcpy(ptr, rsa->text, rsa->len);
	ft_memrev(ptr, rsa->len);
	ptr += rsa->len;
	*ptr++ = 0x00;
	while (r--)
	{
		while (1)
		{
			ft_generate_urandom(ptr, 1);
			if (*ptr)
				break ;
		}
		ptr++;
	}
	*ptr++ = 0x02;
	ft_strdel(&rsa->text);
	rsa->text = padding_text;
	rsa->len = padding_len;
	return (0);
}

static void	ft_rsa_make_encrypt_algor(t_rsa *rsa)
{
	t_bigint	c;
	t_bigint	m;

	m.size = rsa->len;
	m.value = (unsigned char *)rsa->text;
	ft_pow_mod(&c, &m, &rsa->data.public_exponent, &rsa->data.modulus);
	ft_strdel(&rsa->text);
	rsa->text = (char *)c.value;
	rsa->len = c.size;
	ft_memrev(rsa->text, rsa->len);
}

int			ft_rsa_make_encrypt(t_rsa *rsa)
{
	if (rsa->data.modulus.size < rsa->len + 11)
	{
		ft_print_fd(2, "ft_ssl: data too large for key size\n");
		ft_rsa_free_data(&rsa->data);
		ft_strdel(&rsa->text);
		return (1);
	}
	ft_rsa_make_padding(rsa);
	ft_rsa_make_encrypt_algor(rsa);
	return (0);
}