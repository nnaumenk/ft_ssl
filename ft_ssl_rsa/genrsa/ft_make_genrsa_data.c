/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_genrsa_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/15 09:54:22 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_generate_rand_number(int rand_fd, t_bigint *prime, size_t bitlen)
{
	const char	mask1[] = {0xff, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f};
	const char	mask2[] = {0x80, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40};

	prime->size = (bitlen + 7) / 8;
	prime->value = (unsigned char *)malloc(prime->size);
	if (read(rand_fd, prime->value, prime->size) != prime->size)
	{
		ft_print_fd(2, "ft_ssl: not enough random bytes in the source file\n");
		ft_bigint_del(prime);
		return (1);
	}
	prime->value[0] |= 0x1;
	prime->value[prime->size - 1] &= mask1[bitlen % 8];
	prime->value[prime->size - 1] |= mask2[bitlen % 8];
	return (0);
}


static int	ft_generate_primes(t_rsa *rsa)
{
	size_t		bit_len1;
	size_t		bit_len2;
	
	ft_printf("Generating RSA private key, %zu bit long modulus\n",
	rsa->flag.numbits);
	bit_len1 = rsa->flag.numbits / 2;
	bit_len2 = rsa->flag.numbits - bit_len1;
	if (ft_generate_rand_number(rsa->flag.rand_fd, &rsa->data.prime1, bit_len1))
		return (1);
	if (ft_generate_rand_number(rsa->flag.rand_fd, &rsa->data.prime2, bit_len2))
	{
		ft_bigint_del(&rsa->data.prime1);
		return (1);
	}
	if (ft_bigint_equal(&rsa->data.prime1, &rsa->data.prime2))
	{
		ft_print_fd(2, "ft_ssl: not random data in the source file\n");
		ft_bigint_del(&rsa->data.prime1);
		ft_bigint_del(&rsa->data.prime2);
		return (1);
	}
	return (0);
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

static int	ft_make_private_exponent(
			t_bigint *exp, t_bigint *publ_exp, t_bigint *p1, t_bigint *p2)
{
	t_bigint	eiler;

	ft_bigint_decrement(p1);
	ft_bigint_decrement(p2);
	ft_bigint_mul(&eiler, p1, p2);
	ft_bigint_increment(p1);
	ft_bigint_increment(p2);
	if (ft_mod_inverse(exp, publ_exp, &eiler))
	{
		ft_printf("inverse error\n");
		return (1);
	}
	ft_bigint_del(&eiler);
	return (0);
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

int		ft_make_genrsa_data(t_rsa *rsa)
{
	if (ft_generate_primes(rsa))
		return (1);
	ft_make_public_exponent(&rsa->data.public_exponent, rsa->flag.exp_value_3);
	ft_find_prime_number(&rsa->data.prime1, &rsa->data.public_exponent);
	ft_find_prime_number(&rsa->data.prime2, &rsa->data.public_exponent);
	ft_bigint_mul(&rsa->data.modulus, &rsa->data.prime1, &rsa->data.prime2);
	ft_make_private_exponent(&rsa->data.private_exponent,
	&rsa->data.public_exponent, &rsa->data.prime1, &rsa->data.prime2);
	ft_make_exponent(&rsa->data.exponent1, &rsa->data.private_exponent,
	&rsa->data.prime1);
	ft_make_exponent(&rsa->data.exponent2, &rsa->data.private_exponent,
	&rsa->data.prime2);
	ft_mod_inverse(
	&rsa->data.coefficient, &rsa->data.prime2, &rsa->data.prime1);
	return (0);
}
