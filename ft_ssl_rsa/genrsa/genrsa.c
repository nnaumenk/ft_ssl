// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   genrsa.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
// /*   Updated: 2018/11/15 20:45:01 by nnaumenk         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../ft_ssl.h"

// // t_rsa_option	g_option[] =
// // {
// // 	{"-inform", ft_rsa_make_flag_inform},
// // 	{"-outform", ft_rsa_make_flag_outform},
// // 	{"-in", ft_rsa_make_flag_in},
// // 	{"-passin", ft_rsa_make_flag_passin},
// // 	{"-out", ft_rsa_make_flag_out},
// // 	{"-passout", ft_rsa_make_flag_passout},
// // 	{"-des", ft_rsa_make_flag_des},
// // 	{"-text", ft_rsa_make_flag_text},
// // 	{"-noout", ft_rsa_make_flag_noout},
// // 	{"-modulus", ft_rsa_make_flag_modulus},
// // 	{"-check", ft_rsa_make_flag_check},
// // 	{"-pubin", ft_rsa_make_flag_pubin},
// // 	{"-pubout", ft_rsa_make_flag_pubout},
// // 	{0, 0}
// // };

// // typedef struct		s_rsa_data
// // {
// // 	unsigned char	*modulus;
// // 	size_t			modulus_len;
// // 	unsigned char	*public_exponent;
// // 	size_t			public_exponent_len;
// // 	unsigned char	*private_exponent;
// // 	size_t			private_exponent_len;
// // 	unsigned char	*prime1;
// // 	size_t			prime1_len;
// // 	unsigned char	*prime2;
// // 	size_t			prime2_len;
// // 	unsigned char	*exponent1;
// // 	size_t			exponent1_len;
// // 	unsigned char	*exponent2;
// // 	size_t			exponent2_len;
// // 	unsigned char	*coefficient;
// // 	size_t			coefficient_len;
// // }					t_rsa_data;

// // typedef struct		s_rsa
// // {
// // 	char			*text;
// // 	size_t			len;
// // 	t_rsa_flag		flag;
// // 	t_rsa_data		data;
// // }			

// void	ft_get_primes(t_rsa_data *data, size_t numbits)
// {
// 	const char	mask1[] = {0xff, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f};
// 	const char	mask2[] = {0x80, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40};
// 	size_t		bit_prime1_len;
// 	size_t		bit_prime2_len;
	
// 	bit_prime2_len = numbits / 2;
// 	bit_prime1_len = numbits - bit_prime2_len;
// 	data->prime1.size = (bit_prime1_len + 7) / 8;
// 	data->prime2.size = (bit_prime2_len + 7) / 8;
// 	data->prime1.value = (unsigned char *)malloc(data->prime1.size);
// 	data->prime2.value = (unsigned char *)malloc(data->prime2.size);
// 	ft_generate_urandom(data->prime1.value, data->prime1.size);
// 	ft_generate_urandom(data->prime2.value, data->prime2.size);
// 	data->prime1.value[0] |= 0x1;
// 	data->prime2.value[0] |= 0x1;
// 	data->prime1.value[data->prime1.size - 1] &= mask1[bit_prime1_len % 8];
// 	data->prime2.value[data->prime2.size - 1] &= mask1[bit_prime2_len % 8];
// 	data->prime1.value[data->prime1.size - 1] |= mask2[bit_prime1_len % 8];
// 	data->prime2.value[data->prime2.size - 1] |= mask2[bit_prime2_len % 8];
// }

// void	ft_get_modulus(t_rsa_data *data)
// {
// 	data->modulus = ft_bigint_dup(&data->prime1);
// 	// ft_bigint_mul((void **)&data->modulus, (void **)&data->prime2,
// 	// &data->modulus_len, &data->prime2_len);
// }

// void	ft_generate_genrsa_data(t_rsa *data)
// {
// 	ft_get_primes(&data->data, data->flag.numbits);
// 	//ft_check_primes();
// 	ft_get_modulus(&data->data);
// 	// ft_get_public_ecponent
// 		//ft_print_big_int();


// }

// static void	ft_set_values_test(t_rsa_data *data)///ubrat
// {
// 	// data->modulus = (unsigned char *)malloc(64);
// 	// ft_memset(data->modulus, 64, 64);
// 	// data->modulus_len = 64;

// 	data->public_exponent.value = (unsigned char *)malloc(64);
// 	ft_memset(data->public_exponent.value, 64, 64);
// 	data->public_exponent.size = 64;

// 	data->private_exponent.value = (unsigned char *)malloc(64);
// 	ft_memset(data->public_exponent.value, 64, 64);
// 	data->public_exponent.size = 64;

// 	// data->prime1 = (unsigned char *)malloc(64);
// 	// ft_memset(data->prime1, 64, 64);
// 	// data->prime1_len = 64;

// 	// data->prime2 = (unsigned char *)malloc(64);
// 	// ft_memset(data->prime2, 64, 64);
// 	// data->prime2_len = 64;

// 	data->exponent1.value = (unsigned char *)malloc(64);
// 	ft_memset(data->public_exponent.value, 64, 64);
// 	data->public_exponent.size = 64;

// 	data->exponent2.value = (unsigned char *)malloc(64);
// 	ft_memset(data->public_exponent.value, 64, 64);
// 	data->public_exponent.size = 64;

// 	data->coefficient.value = (unsigned char *)malloc(64);
// 	ft_memset(data->public_exponent.value, 64, 64);
// 	data->public_exponent.size = 64;
// }

// static void	ft_delete_genrsa_data(t_rsa_data *data)
// {
// 	ft_bigint_del(&data->modulus);
// 	ft_bigint_del(&data->public_exponent);
// 	ft_bigint_del(&data->private_exponent);
// 	ft_bigint_del(&data->prime1);
// 	ft_bigint_del(&data->prime2);
// 	ft_bigint_del(&data->exponent1);
// 	ft_bigint_del(&data->exponent2);
// 	ft_bigint_del(&data->coefficient);
// }

// static void	ft_genrsa_make_text(t_rsa *data)
// {
// 	const char	*line1 = "-----BEGIN RSA PRIVATE KEY-----\n";
// 	const char	*line2 = "-----END RSA PRIVATE KEY-----\n";
// 	char		*asn_text;
// 	size_t		asn_len;

// 	ft_asn1_encode(data->data, &asn_text, &asn_len);
// 	asn_text = ft_b64_encode(asn_text, &asn_len);
// 	data->text = ft_mem_joiner(&data->len, 3,
// 	(char *)line1, (size_t)32, asn_text, asn_len, (char *)line2, (size_t)30);
// 	ft_strdel(&asn_text);
// }

void		ft_genrsa(void *v_data)
{
	// t_rsa	data;

	USE(v_data);
	// data.flag = *(t_rsa_flag *)v_data;
	// ft_printf("numbits = %zu\n", data.flag.numbits);
	// ft_generate_genrsa_data(&data);
	// ft_set_values_test(&data.data);////change to generation
	// ft_genrsa_make_text(&data);
	// ft_delete_genrsa_data(&data.data);
	// ft_rsa_make_flag_o(&data);
	// ft_strdel(&data.text);
}