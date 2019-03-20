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

int	ft_make_private_exponent(
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
