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

/*
**
**	miller-rabin probability is calculated by next formula
**	probability = 1 - 1/(4^rounds)
**	rounds = -(ln(1 - probability) / ln(4));
**
*/

static unsigned	ft_get_round_number(float probability)
{
	if (probability <= 0.75)
		return (1);
	if (probability <= 0.9375)
		return (2);
	if (probability <= 0.984375)
		return (3);
	if (probability <= 0.99609375)
		return (4);
	if (probability <= 0.9990234375)
		return (5);
	if (probability <= 0.999755859375)
		return (6);
	if (probability <= 0.99993896484375)
		return (7);
	if (probability <= 0.9999847412109375)
		return (8);
	if (probability <= 0.999996185302734375)
		return (9);
	return (10);
}

int				ft_ssl_is_primary(__uint64_t number, float probability)
{
	unsigned	rounds;
	t_bigint	big_number;

	if (number == 2 || number == 3)
		return (1);
	if (number < 2 || number % 2 == 0)
		return (0);
	rounds = ft_get_round_number(probability);
	big_number.size = sizeof(number);
	big_number.value = (unsigned char *)malloc(big_number.size);
	*(__uint64_t *)big_number.value = number;
	if (ft_is_composit_by_miller_rabin(&big_number, rounds))
	{
		ft_bigint_del(&big_number);
		return (0);
	}
	ft_bigint_del(&big_number);
	return (1);
}
