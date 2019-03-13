/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genrsa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/28 00:00:12 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static void	ft_delete_genrsa_data(t_rsa *rsa)
{
	ft_bigint_del(&rsa->data.modulus);
	ft_bigint_del(&rsa->data.public_exponent);
	ft_bigint_del(&rsa->data.private_exponent);
	ft_bigint_del(&rsa->data.prime1);
	ft_bigint_del(&rsa->data.prime2);
	ft_bigint_del(&rsa->data.exponent1);
	ft_bigint_del(&rsa->data.exponent2);
	ft_bigint_del(&rsa->data.coefficient);
}

static void	ft_genrsa_make_asn1_text(t_rsa *rsa)
{
	const char	*line1 = "-----BEGIN RSA PRIVATE KEY-----\n";
	const char	*line2 = "-----END RSA PRIVATE KEY-----\n";
	char		*asn_text;
	size_t		asn_len;

	ft_asn1_encode(&rsa->data, &asn_text, &asn_len);
	asn_text = ft_b64_encode(asn_text, &asn_len);
	rsa->text = ft_mem_joiner(&rsa->len, 3,
	(char *)line1, (size_t)32, asn_text, asn_len, (char *)line2, (size_t)30);
	ft_strdel(&asn_text);
}

void		ft_genrsa(void *v_data)
{
	t_rsa	rsa;

	rsa.flag = *(t_rsa_flag *)v_data;
	if (rsa.flag.numbits <= 30)
	{
		ft_printf("ft_ssl: key's size is too small\n");
		return ;
	}
	rsa.flag.rand_fd = ft_rsa_make_flag_rand(rsa.flag.in);
	if (rsa.flag.rand_fd == -1)
		return ;
	if (ft_make_genrsa_data(&rsa))
		return ;
	ft_close_fd(rsa.flag.rand_fd);
	ft_printf("0\n");
	ft_genrsa_make_asn1_text(&rsa);
	ft_printf("1\n");
	ft_delete_genrsa_data(&rsa);
	ft_printf("2\n");
	ft_rsa_make_flag_out(rsa.text, rsa.len, rsa.flag.out);
	ft_strdel(&rsa.text);
}
