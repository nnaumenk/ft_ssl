/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_genrsa_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:23:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/03/17 00:25:29 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

static int	ft_generate_rand_number(int rand_fd, t_bigint *prime, size_t bitlen)
{
	const char	mask1[] = {0xff, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f};
	const char	mask2[] = {0x80, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40};

	prime->size = (bitlen + 7) / 8;
	prime->value = (unsigned char *)malloc(prime->size);
	if ((size_t)read(rand_fd, prime->value, prime->size) != prime->size)
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

int			ft_make_primes(t_rsa *rsa)
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
