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

int			ft_ssl_is_primary(t_bigint *number, unsigned probability)
{
	if (probability >= 100)
		probability = 99;
	// if (ft_is_composit_by_initial_sieve(number))
	// {
	// 	ft_printf("sieve\n");
	// 	return (0);
	// }
	if (ft_is_composit_by_miller_rabin(number, probability))
	{
		ft_printf("miller-rabin\n");
		return (0);
	}
	return (1);
}
