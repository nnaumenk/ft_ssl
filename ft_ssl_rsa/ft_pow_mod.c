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

void	ft_power_mod(t_bigint *res, t_bigint *num, t_bigint *pow, t_bigint *mod)
{
	t_bigint	integer;
	t_bigint	remainder;
	t_bigint	mul;
	t_bigint	d;
	t_bigint	t;

	ft_bigint_print("number", number);
	ft_bigint_print("power", pow);
	ft_bigint_print("mod", mod);


	t = ft_bigint_dup(number);
	d.size = 1;
	d.value = (unsigned char *)malloc(1);
	d.value[0] = 1;
	while (1)
	{
		if (pow->value[0] & 0x01)
		{
			ft_bigint_mul(&mul, &d, &t);
			ft_bigint_div(&integer, &remainder, &mul, mod);
			d = remainder;
			ft_bigint_normalize(&d);
			ft_bigint_print("d", &d);
		}
		ft_bigint_shr(pow, 1);
		if (ft_bigint_isnull(pow))
			break ;
		ft_bigint_mul(&mul, &t, &t);
		ft_bigint_div(&integer, &remainder, &mul, mod);
		t = remainder;
		ft_bigint_normalize(&t);
	}
	ft_bigint_normalize(&d);
	ft_bigint_print("result", &d);
}
