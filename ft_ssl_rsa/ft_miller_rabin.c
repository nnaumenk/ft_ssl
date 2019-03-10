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

static void	ft_get_random_2_to_prime_minus_2(t_bigint *rand, t_bigint *prime)
{
	t_bigint	integer;
	t_bigint	remainder;

	rand->size = prime->size;
	rand->value = (unsigned char *)malloc(rand->size);
	ft_generate_urandom(rand->value, rand->size);
	ft_bigint_decrement(prime);
	ft_bigint_decrement(prime);
	ft_bigint_decrement(prime);
	ft_bigint_div(&integer, &remainder, rand, prime);
	ft_bigint_increment(prime);
	ft_bigint_increment(prime);
	ft_bigint_increment(prime);
	ft_bigint_increment(&remainder);
	ft_bigint_increment(&remainder);
	*rand = remainder;
	ft_bigint_del(&integer);
}

static void	ft_find_minimal_odd(
	t_bigint *min_odd, t_bigint *pow, t_bigint *prime_minus_1, t_bigint *prime)
{
	pow->size = prime->size;
	pow->value = (unsigned char *)malloc(prime->size);
	ft_bzero(pow->value, pow->size);
	*prime_minus_1 = ft_bigint_dup(prime);
	ft_bigint_decrement(prime_minus_1);
	*min_odd = ft_bigint_dup(prime_minus_1);
	while (1)
	{
		ft_bigint_shr(min_odd, 1);
		ft_bigint_increment(pow);
		if (min_odd->value[0] & 0x01)
			break ;
	}
}

static int	ft_is_prime_by_1_statement(
	t_bigint *rand, t_bigint *min_odd, t_bigint *prime, t_bigint *prime_minus_1)
{
	t_bigint result;

	ft_bigint_print("base", rand);
	ft_bigint_print("exp", min_odd);
	ft_bigint_print("mod", prime);

	ft_pow_mod(&result, rand, min_odd, prime);
	ft_bigint_print("result(should be 1) = ", &result);
	ft_bigint_del(rand);
	*rand = result;
	if (ft_bigint_equ_value(rand, 1))
		return (1);
	if (ft_bigint_equal(rand, prime_minus_1))
		return (1);
	return (0);
}

static int	ft_is_prime_by_2_statement(
	t_bigint *rand, t_bigint *prime, t_bigint *pow, t_bigint *prime_minus_1)
{
	t_bigint			result;
	t_bigint			two;
	t_bigint			counter;

	two.size = 1;
	two.value = (unsigned char *)malloc(1);
	two.value[0] = 2;
	counter = ft_bigint_dup(pow);
	ft_bigint_decrement(&counter);
	while (ft_bigint_isnull(&counter) == 0)
	{
		ft_pow_mod(&result, rand, &two, prime);
		ft_bigint_del(rand);
		*rand = result;
		if (ft_bigint_equal(rand, prime_minus_1))
		{
			ft_bigint_del(&two);
			ft_bigint_del(&counter);
			return (1);
		}
		ft_bigint_decrement(&counter);
	}
	ft_bigint_del(&two);
	ft_bigint_del(&counter);
	return (0);
}

int			ft_is_composit_by_miller_rabin(t_bigint *prime, unsigned rounds)
{
	t_bigint	prime_minus_1;
	t_bigint	rand;
	t_bigint	min_odd;
	t_bigint	pow;

	ft_find_minimal_odd(&min_odd, &pow, &prime_minus_1, prime);
	while (rounds--)
	{
		//ft_get_random_2_to_prime_minus_2(&rand, prime);

		rand.size = prime->size;
		rand.value = malloc(prime->size);
		*(size_t *)rand.value = 10757916792386267255;
		ft_printf("round\n");
		if (ft_is_prime_by_1_statement(&rand, &min_odd, prime, &prime_minus_1))
		{
			ft_printf("a1\n");
			ft_bigint_del(&rand);
			continue ;
		}
		if (ft_is_prime_by_2_statement(&rand, prime, &pow, &prime_minus_1))
		{
			ft_printf("a2\n");
			ft_bigint_del(&rand);
			continue ;
		}
		ft_bigint_del(&rand);
		return (1);
	}
	return (0);
}
