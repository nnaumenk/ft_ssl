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

static void	ft_algor(t_bigint *d, t_bigint *t, t_bigint *pow, t_bigint *mod)
{
	t_bigint	integer;
	t_bigint	remainder;
	t_bigint	mul;
	
	while (1)
	{
		if (pow->value[0] & 0x01)
		{
			ft_bigint_mul(&mul, d, t);
			ft_bigint_div(&integer, &remainder, &mul, mod);
			ft_bigint_del(&mul);
			ft_bigint_del(&integer);
			ft_bigint_del(d);
			*d = remainder;
			
		}
		ft_bigint_shr(pow, 1);
		if (ft_bigint_isnull(pow))
			break ;
		ft_bigint_mul(&mul, t, t);
		ft_bigint_div(&integer, &remainder, &mul, mod);
		ft_bigint_del(&mul);
		ft_bigint_del(&integer);
		ft_bigint_del(t);
		*t = remainder;
	}
}

void		ft_pow_mod(t_bigint *r, t_bigint *num, t_bigint *pow, t_bigint *mod)
{
	t_bigint	pow_buf;
	t_bigint	d;
	t_bigint	t;
	
	pow_buf = ft_bigint_dup(pow);
	t = ft_bigint_dup(num);
	d.size = 1;
	d.value = (unsigned char *)malloc(1);
	d.value[0] = 1;
	ft_algor(&d, &t, &pow_buf, mod);
	ft_bigint_del(&t);
	ft_bigint_del(&pow_buf);
	*r = d;
}
