/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsa_make_decrypt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/26 18:57:05 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_rsa_check_padding(t_rsa *rsa)
{
	size_t	r;
	char	*ptr;
	char	*original_text;
	size_t	original_len;

	ptr = rsa->text + rsa->len - 1;
	if (*ptr-- != 0x02)
		return (1);
	r = 0;
	while (1)
	{
		if (*ptr-- == 0x00)
			break ;
		r++;
	}
	if (r < 8)
		return (1);
	original_len = rsa->len - r - 2;
	original_text = (char *)malloc(original_len);
	ft_memcpy(original_text, rsa->text, original_len);
	ft_memrev(original_text, original_len);
	ft_strdel(&rsa->text);
	rsa->text = original_text;
	rsa->len = original_len;
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
	ft_rsa_free_data(&rsa->data);
	return (0);
}