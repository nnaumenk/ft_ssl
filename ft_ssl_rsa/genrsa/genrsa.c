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

// t_rsa_option	g_option[] =
// {
// 	{"-inform", ft_rsa_make_flag_inform},
// 	{"-outform", ft_rsa_make_flag_outform},
// 	{"-in", ft_rsa_make_flag_in},
// 	{"-passin", ft_rsa_make_flag_passin},
// 	{"-out", ft_rsa_make_flag_out},
// 	{"-passout", ft_rsa_make_flag_passout},
// 	{"-des", ft_rsa_make_flag_des},
// 	{"-text", ft_rsa_make_flag_text},
// 	{"-noout", ft_rsa_make_flag_noout},
// 	{"-modulus", ft_rsa_make_flag_modulus},
// 	{"-check", ft_rsa_make_flag_check},
// 	{"-pubin", ft_rsa_make_flag_pubin},
// 	{"-pubout", ft_rsa_make_flag_pubout},
// 	{0, 0}
// };

// typedef struct		s_rsa_data
// {
// 	unsigned char	*modulus;
// 	size_t			modulus_len;
// 	unsigned char	*public_exponent;
// 	size_t			public_exponent_len;
// 	unsigned char	*private_exponent;
// 	size_t			private_exponent_len;
// 	unsigned char	*prime1;
// 	size_t			prime1_len;
// 	unsigned char	*prime2;
// 	size_t			prime2_len;
// 	unsigned char	*exponent1;
// 	size_t			exponent1_len;
// 	unsigned char	*exponent2;
// 	size_t			exponent2_len;
// 	unsigned char	*coefficient;
// 	size_t			coefficient_len;
// }					t_rsa_data;

// typedef struct		s_rsa
// {
// 	char			*text;
// 	size_t			len;
// 	t_rsa_flag		flag;
// 	t_rsa_data		data;
// }			



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

	ft_asn1_encode(rsa->data, &asn_text, &asn_len);
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
	ft_make_genrsa_data(&rsa);
	ft_genrsa_make_asn1_text(&rsa);
	ft_delete_genrsa_data(&rsa);
	ft_rsa_make_flag_o(&rsa);
	ft_strdel(&rsa.text);
}