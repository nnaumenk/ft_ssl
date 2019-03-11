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

void	ft_generate_rand_numbers(t_rsa_data *data, size_t numbits)
{
	const char	mask1[] = {0xff, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f};
	const char	mask2[] = {0x80, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40};
	size_t		bit_prime1_len;
	size_t		bit_prime2_len;
	
	ft_printf("Generating RSA private key, %zu bit long modulus\n", numbits);
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

static void	ft_make_exponent(t_bigint *exp, t_bigint *pr_exp, t_bigint *prime)
{
	t_bigint	integer;
	t_bigint	remainder;

	ft_bigint_decrement(prime);
	ft_bigint_div(&integer, &remainder, pr_exp, prime);
	ft_bigint_increment(prime);
	*exp = remainder;
	ft_bigint_del(&integer);
}

static void	ft_make_private_exponent(
			t_bigint *exp, t_bigint *publ_exp, t_bigint *p1, t_bigint *p2)
{
	t_bigint	eiler;

	ft_bigint_decrement(p1);
	ft_bigint_decrement(p2);
	ft_bigint_mul(&eiler, p1, p2);
	ft_bigint_increment(p1);
	ft_bigint_increment(p2);
	ft_mod_inverse(exp, publ_exp, &eiler);
	ft_bigint_del(&eiler);
}

static void	ft_make_public_exponent(t_bigint *exp, int exp_value_3)
{
	if (exp_value_3 == 0)
	{
		exp->value = (unsigned char *)malloc(3);
		exp->size = 3;
		*(unsigned int *)(exp->value) = 65537;
	}
	else
	{
		exp->value = (unsigned char *)malloc(1);
		exp->size = 1;
		*(unsigned char *)exp->value = 3;
	}
	ft_bigint_print("e is", exp);
}

void		ft_make_genrsa_data(t_rsa *rsa)
{
	ft_generate_rand_numbers(&rsa->data, rsa->flag.numbits);
	ft_find_prime_number(&rsa->data.prime1);
	ft_find_prime_number(&rsa->data.prime2);
	ft_bigint_mul(&rsa->data.modulus, &rsa->data.prime1, &rsa->data.prime2);
	ft_make_public_exponent(&rsa->data.public_exponent, rsa->flag.exp_value_3);
	ft_make_private_exponent(&rsa->data.private_exponent,
	&rsa->data.public_exponent, &rsa->data.prime1, &rsa->data.prime2);
	ft_make_exponent(&rsa->data.exponent1, &rsa->data.private_exponent,
	&rsa->data.prime1);
	ft_make_exponent(&rsa->data.exponent2, &rsa->data.private_exponent,
	&rsa->data.prime2);
	ft_mod_inverse(
	&rsa->data.coefficient, &rsa->data.prime2, &rsa->data.prime1);
}
