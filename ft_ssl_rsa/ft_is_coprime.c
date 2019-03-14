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

int		ft_is_coprime(t_bigint *a, t_bigint *b)
{
	t_bigint	gcd;

	ft_euclid_gcd(&gcd, a, b);
	if (ft_bigint_isvalue(&gcd, 1))
	{
		ft_bigint_del(&gcd);
		return (1);
	}
	ft_bigint_del(&gcd);
	return (0);
}
