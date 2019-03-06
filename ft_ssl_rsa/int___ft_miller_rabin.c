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

static char	g_probability[] =
{
	0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 3, 3, 3, 3, 3, 4
};

static void	ft_find_minimal_odd(size_t *minimal_odd, size_t *pow, size_t prime)
{
	size_t	pow;

	*minimal_odd = prime - 1;
	*pow = 0;
	while (1)
	{
		*minimal_odd /= 2;
		++*pow;
		if (*minimal_odd % 2)
			break ;
	}
}

static int	ft_is_pseudoprime_by_2_statement(
			size_t random, size_t minimal_odd, size_t prime, size_t pow)
{
	size_t	result;

	while (--pow)
	{
		minimal_odd <<= 1;
		result = ft_pow_mod2(random, minimal_odd, prime);
		if (result == num - 1)
			return (1);
	}
	return (0);
}

int			ft_is_composit_by_miller_rabin_int(
			size_t prime, unsigned probability)
{
	size_t		result;
	size_t		random;
	size_t		minimal_odd;
	size_t		pow;

	ft_find_minimal_odd(&minimal_odd, &pow, prime);
	probability = g_probability[probability];
	while (probability--)
	{
		random = ft_get_random_range(1, num - 1);
		result = ft_pow_mod2(random, minimal_odd, prime);
		if (result == 1)
			continue ;
		if (result == num - 1)
			continue ;
		if (ft_is_pseudoprime_by_2_statement(random, minimal_odd, prime, pow))
			continue ;
		return (1);
	}
	return (0);
}
