/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genrsa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/11/15 20:45:01 by nnaumenk         ###   ########.fr       */
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

void	ft_generate_primes(t_rsa_data *data, size_t numbits)
{
	const char	mask1[] = {0xff, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f};
	const char	mask2[] = {0x80, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40};
	size_t		bit_prime1_len;
	size_t		bit_prime2_len;
	
	bit_prime2_len = numbits / 2;
	bit_prime1_len = numbits - bit_prime2_len;
	data->prime1.size = (bit_prime1_len + 7) / 8;
	data->prime2.size = (bit_prime2_len + 7) / 8;
	data->prime1.value = (unsigned char *)malloc(data->prime1.size);
	data->prime2.value = (unsigned char *)malloc(data->prime2.size);
	ft_generate_urandom(data->prime1.value, data->prime1.size);
	ft_generate_urandom(data->prime2.value, data->prime2.size);
	data->prime1.value[0] |= 0x1;
	data->prime2.value[0] |= 0x1;
	data->prime1.value[data->prime1.size - 1] &= mask1[bit_prime1_len % 8];
	data->prime2.value[data->prime2.size - 1] &= mask1[bit_prime2_len % 8];
	data->prime1.value[data->prime1.size - 1] |= mask2[bit_prime1_len % 8];
	data->prime2.value[data->prime2.size - 1] |= mask2[bit_prime2_len % 8];
}

void	ft_make_exponents(t_rsa_data *data, int exp_value_3)
{
	t_bigint	eiler;

	if (exp_value_3 == 0)
	{
		data->public_exponent.value = (unsigned char *)malloc(3);
		data->public_exponent.size = 3;
		*(unsigned int *)(data->public_exponent.value) = 65537;
	}
	else
	{
		data->public_exponent.value = (unsigned char *)malloc(1);
		data->public_exponent.size = 1;
		*(data->public_exponent.value) = 3;
	}
	ft_bigint_decrement(&data->prime1);
	ft_bigint_decrement(&data->prime2);
	ft_bigint_mul(&eiler, &data->prime1, &data->prime2);
	ft_print("c\n");
	if (ft_mod_inverse(&data->private_exponent, &data->public_exponent, &eiler))
	{
		ft_print("inverse error private_exponent\n");
		exit(0);
	}
	ft_bigint_del(&eiler);
	ft_print("d\n");
	if (ft_mod_inverse(&data->exponent1, &data->private_exponent, &data->prime1))
	{
		ft_print("inverse error exponent1\n");
		exit(0);
	}
	if (ft_mod_inverse(&data->exponent2, &data->private_exponent, &data->prime2))
	{
		ft_print("inverse error exponent2\n");
		exit(0);
	}
	ft_bigint_increment(&data->prime1);
	ft_bigint_increment(&data->prime2);
	if (ft_mod_inverse(&data->coefficient, &data->prime2, &data->prime1))
	{
		ft_print("inverse error coefficient\n");
		exit(0);
	}
}

static void	ft_make_genrsa_data(t_rsa *rsa)
{
	ft_generate_primes(&rsa->data, rsa->flag.numbits);
	//ft_check_primes();
	ft_print("a\n");
	ft_bigint_mul(&rsa->data.modulus, &rsa->data.prime1, &rsa->data.prime2);
	ft_print("b\n");
	ft_make_exponents(&rsa->data, rsa->flag.exp_value_3);
}

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

static void	ft_genrsa_make_text(t_rsa *rsa)
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
	ft_print("1\n");
	rsa.flag = *(t_rsa_flag *)v_data;
	ft_make_genrsa_data(&rsa);
	ft_print("2\n");
	ft_genrsa_make_text(&rsa);
	ft_delete_genrsa_data(&rsa);
	ft_rsa_make_flag_o(&rsa);
	ft_strdel(&rsa.text);
}