/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <nnaumenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:45:35 by nnaumenk          #+#    #+#             */
/*   Updated: 2019/02/27 18:44:55 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

static void	ft_get_random_1_to_prime_minus_1(t_bigint *rand, t_bigint *prime)
{
	t_bigint	integer;
	t_bigint	remainder;

	rand->size = prime->size;
	rand->value = (unsigned char *)malloc(rand->size);
	ft_generate_urandom(rand->value, rand->size);
	ft_bigint_decrement(prime);
	ft_bigint_div(&integer, &remainder, rand, prime);
	ft_bigint_increment(prime);
	ft_bigint_increment(&remainder);
	*rand = remainder;
	ft_bigint_del(&integer);
}

static void	ft_find_minimal_odd(
			t_bigint *minimal_odd, t_bigint *pow, t_bigint *prime)
{
	pow->size = prime->size;
	pow->value = (unsigned char *)malloc(prime->size);
	ft_bzero(pow->value, pow->size);
	*minimal_odd = ft_bigint_dup(prime);
	ft_bigint_decrement(minimal_odd);
	while (1)
	{
		ft_bigint_shr(minimal_odd, 1);
		ft_bigint_increment(pow);
		if (minimal_odd->value[0] & 0x01)
			break ;
	}
}

static int	ft_is_pseudoprime_by_1_statement(
			t_bigint *rand, t_bigint *min_odd, t_bigint *prime)
{
	t_bigint result;

	ft_pow_mod(&result, rand, min_odd, prime);
	if (ft_bigint_equ_value(&result, 1))
		return (1);
	ft_bigint_decrement(prime);
	if (ft_bigint_equal(&result, prime))
	{
		ft_bigint_increment(prime);
		return (1);
	}
	ft_bigint_increment(prime);
	return (0);
}

static int	ft_is_composit_by_2_statement(
			t_bigint *rand, t_bigint *min_odd, t_bigint *prime, t_bigint *pow)
{
	t_bigint			result;
	t_bigint			iteration_pow;
	t_bigint			counter;

	iteration_pow = ft_bigint_dup(min_odd);
	counter = ft_bigint_dup(pow);
	ft_bigint_decrement(&counter);
	while (ft_bigint_isnull(&counter) == 0)
	{
		ft_bigint_shl_overflow(&iteration_pow, 1);
		ft_pow_mod(&result, rand, &iteration_pow, prime);
		ft_bigint_decrement(prime);
		if (ft_bigint_equal(&result, prime) == 0)
		{
			ft_bigint_increment(prime);
			ft_bigint_del(&iteration_pow);
			ft_bigint_del(&counter);
			return (0);
		}
		ft_bigint_increment(prime);
		ft_bigint_decrement(&counter);
	}
	ft_bigint_del(&iteration_pow);
	ft_bigint_del(&counter);
	return (1);
}

int			ft_is_composit_by_miller_rabin(t_bigint *prime, unsigned rounds)
{
	t_bigint	rand;
	t_bigint	minimal_odd;
	t_bigint	pow;

	ft_find_minimal_odd(&minimal_odd, &pow, prime);
	while (rounds--)
	{
		ft_get_random_1_to_prime_minus_1(&rand, prime);
		if (ft_is_pseudoprime_by_1_statement(&rand, &minimal_odd, prime))
		{
			ft_bigint_del(&rand);
			continue ;
		}
		if (ft_is_composit_by_2_statement(&rand, &minimal_odd, prime, &pow))
		{
			ft_bigint_del(&rand);
			continue ;
		}
		ft_bigint_del(&rand);
		return (1);
	}
	return (0);
}
