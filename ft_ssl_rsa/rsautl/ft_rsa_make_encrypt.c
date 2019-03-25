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

static int	ft_rsa_add_padding(t_rsa *rsa)
{
	size_t	r;
	char	*padding_text;
	size_t	padding_len;

	if (rsa->data.modulus.size < rsa->len + 11)
	{
		ft_print_fd(2, "ft_ssl: data too large for key size\n");
		ft_rsa_free_data(&rsa->data);
		ft_strdel(&rsa->text);
		return (1);
	}
	r = rsa->data.modulus.size - 3 - rsa->len;
	padding_len = rsa->len + r + 3;
	padding_text = (char *)malloc(rsa->len + r + 3);
	padding_text[0] = 0x00;
	padding_text[1] = 0x02;
	ft_generate_urandom(padding_text + 2, r);
	padding_text[r + 2] = 0x00;
	ft_memcpy(padding_text + r + 3, rsa->text, rsa->len);
	ft_strdel(&rsa->text);
	rsa->text = padding_text;
	rsa->len = rsa->len + r + 3;
	////memswap
	return (0);
}

int			ft_rsa_make_encrypt(t_rsa *rsa)
{
	if (ft_rsa_add_padding(rsa))
		return (1);

	
	USE(rsa);

	return (0);
}