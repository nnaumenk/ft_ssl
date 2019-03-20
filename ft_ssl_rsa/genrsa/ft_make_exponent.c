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

void	ft_make_exponent(t_bigint *exp, t_bigint *pr_exp, t_bigint *prime)
{
	t_bigint	integer;
	t_bigint	remainder;

	ft_bigint_decrement(prime);
	if (ft_bigint_smaller(pr_exp, prime))
		*exp = ft_bigint_dup(pr_exp);
	else
	{
		ft_bigint_div(&integer, &remainder, pr_exp, prime);
		ft_bigint_del(&integer);
		*exp = remainder;
	}
	ft_bigint_increment(prime);
}
